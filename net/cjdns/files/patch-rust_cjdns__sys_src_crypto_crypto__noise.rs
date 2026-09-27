-- Fix cjdns Noise/WireGuard packet handling for queued packets and peer addressing.
-- BoringTun queues the first data packet behind the handshake response; the old
-- code only emitted the handshake keepalive, so the queued packet was lost.
-- Also, outgoing ciphertext packets were missing the peer IPv6 header, causing
-- the receiver to fail session lookup.  Drain the queued packets and prepend the
-- peer IPv6 address to outgoing cipher messages so the wireguard interface tests pass.
-- Upstreamed: https://github.com/cjdelisle/cjdns/pull/1280

--- rust/cjdns_sys/src/crypto/crypto_noise.rs.orig	2026-09-27 19:37:09 UTC
+++ rust/cjdns_sys/src/crypto/crypto_noise.rs
@@ -233,6 +233,7 @@ impl SessionInner {
         eyre::ensure!(msg.is_aligned_to(4), "Alignment fault");
         let msg_type = cnoise::cjdns_from_wg(&mut msg)?;
         log::debug!("send_crypto message type {} length {}", msg_type, msg.len());
+        msg.push_bytes(&self.her_ip6)?;
         self.cipher_pvt.send(msg)
     }
 }
@@ -291,9 +292,10 @@ impl IfRecv for CiphertextRecv {
                 bail!("DROP packet associated with existing session trying to create a new one");
             },
             (TryMsgReply::ReplyToPeer, None, msg_type, m) => {
-                let m = m.unwrap();
+                let mut m = m.unwrap();
                 log::debug!("Replying to msg_type {}", msg_type);
                 eyre::ensure!(m.is_aligned_to(4), "Alignment fault");
+                m.push_bytes(&self.0.her_ip6)?;
                 self.0.cipher_pvt.send(m)
             },
             (TryMsgReply::Done, None, msg_type, _) => {
@@ -616,62 +618,97 @@ fn handle_incoming1(
                 msg_type, index);
             return Err(DecryptError::DecryptErr(DecryptErr::NoSession).into());
         };
-        let next = THREAD_CTX.with(|tc| -> Result<NextForward> {
+
+        enum Step {
+            Stop,
+            Plain(Vec<u8>),
+            Cipher(Vec<u8>),
+            Error { state: u32, code: u32, first16: Vec<u8> },
+        }
+
+        let mut first = true;
+        let mut step = THREAD_CTX.with(|tc| {
             let mut tc = tc.borrow_mut();
-            let res = sess.tunnel.decapsulate(Some(peer_id.into()), msg.bytes(), &mut tc.crypt_buf[..]);
+            let datagram: &[u8] = if first { msg.bytes() } else { &[] };
+            let res = sess.tunnel.decapsulate(Some(peer_id.into()), datagram, &mut tc.crypt_buf[..]);
             match res {
                 TunnResult::Err(e) => {
-                    // Put the message back as we found it
-                    cnoise::cjdns_from_wg(&mut msg)?;
-                    log::debug!("WG error: {:?} in msg type: {}", e, msg_type);
-                    let ee = (e as u32) + 1024; // TODO better errors ?
-
-                    let mut first16 = [0_u8; 16];
-                    first16.copy_from_slice(&msg.bytes()[0..std::cmp::min(16, msg.len())]);
-
-                    msg.clear();
-                    msg.push((sess.get_state() as u32).to_be())?;
-                    msg.push(ee.to_be())?;
-                    msg.push_bytes(&first16)?;
-                    msg.push(ee)?;
-                    //sess.plain_pvt.send(msg)?;
-                    Ok(NextForward::Plain)
-                    //return Err(DecryptError::DecryptErr(DecryptErr::Decrypt).into());
-                }
-                TunnResult::Done => {
-                    if let Some(peer_index) = peer_index {
-                        sess.update_peer_index(peer_index);
+                    if first {
+                        log::debug!("WG error: {:?} in msg type: {}", e, msg_type);
+                        let ee = (e as u32) + 1024; // TODO better errors ?
+                        let first16_len = std::cmp::min(16, msg.len());
+                        Step::Error {
+                            state: sess.get_state() as u32,
+                            code: ee,
+                            first16: msg.bytes()[..first16_len].to_vec(),
+                        }
+                    } else {
+                        log::debug!("WG error draining queued packet: {:?}", e);
+                        Step::Stop
                     }
-                    msg.clear();
-                    Ok(NextForward::Done)
                 }
-                TunnResult::WriteToNetwork(buf, _) => {
-                    if let Some(peer_index) = peer_index {
-                        sess.update_peer_index(peer_index);
-                    }
-                    msg.discard_bytes(msg.len())?;
-                    msg.push_bytes(buf)?;
-                    Ok(NextForward::Cipher)
-                }
-                TunnResult::CustomData(buf) => {
-                    // Successfully decrypted a packet - return it in the msg
-                    msg.discard_bytes(msg.len())?;
-                    msg.push_bytes(buf)?;
-                    // Message is ok, put the OK header and forward it along
-                    msg.push(0_u32)?;
-                    //sess.plain_pvt.send(msg)?;
-                    Ok(NextForward::Plain)
-                }
+                TunnResult::Done => Step::Stop,
+                TunnResult::WriteToNetwork(buf, _) => Step::Cipher(buf.to_vec()),
+                TunnResult::CustomData(buf) => Step::Plain(buf.to_vec()),
                 TunnResult::WriteToTunnelV4(_, _) |
                 TunnResult::WriteToTunnelV6(_, _) => {
                     panic!("WG unexpected IP packet");
                 }
             }
-        })?;
-        match next {
-            NextForward::Plain => sess.plain_pvt.send(msg)?,
-            NextForward::Cipher => sess.send_crypto(msg)?,
-            NextForward::Done => (),
+        });
+        loop {
+            match step {
+                Step::Stop => break,
+                Step::Plain(data) => {
+                    if first {
+                        if let Some(peer_index) = peer_index {
+                            sess.update_peer_index(peer_index);
+                        }
+                    }
+                    let mut out = msg.new_same_alloc(data.len() + 256);
+                    out.push_bytes(&data)?;
+                    out.push(0_u32)?;
+                    sess.plain_pvt.send(out)?;
+                    break;
+                }
+                Step::Cipher(data) => {
+                    if first {
+                        if let Some(peer_index) = peer_index {
+                            sess.update_peer_index(peer_index);
+                        }
+                    }
+                    let mut out = msg.new_same_alloc(data.len() + 256);
+                    out.push_bytes(&data)?;
+                    sess.send_crypto(out)?;
+                }
+                Step::Error { state, code, first16 } => {
+                    let mut err_msg = msg.new_same_alloc(256);
+                    err_msg.push(state.to_be())?;
+                    err_msg.push(code.to_be())?;
+                    err_msg.push_bytes(&first16)?;
+                    err_msg.push(code)?;
+                    sess.plain_pvt.send(err_msg)?;
+                    break;
+                }
+            }
+            first = false;
+            step = THREAD_CTX.with(|tc| {
+                let mut tc = tc.borrow_mut();
+                let res = sess.tunnel.decapsulate(Some(peer_id.into()), &[], &mut tc.crypt_buf[..]);
+                match res {
+                    TunnResult::Err(e) => {
+                        log::debug!("WG error draining queued packet: {:?}", e);
+                        Step::Stop
+                    }
+                    TunnResult::Done => Step::Stop,
+                    TunnResult::WriteToNetwork(buf, _) => Step::Cipher(buf.to_vec()),
+                    TunnResult::CustomData(buf) => Step::Plain(buf.to_vec()),
+                    TunnResult::WriteToTunnelV4(_, _) |
+                    TunnResult::WriteToTunnelV6(_, _) => {
+                        panic!("WG unexpected IP packet");
+                    }
+                }
+            });
         }
         Ok((TryMsgReply::Done, None, msg_type, None))
     } else {
