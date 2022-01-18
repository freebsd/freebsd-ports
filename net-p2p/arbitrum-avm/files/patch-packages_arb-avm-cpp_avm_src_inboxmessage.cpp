--- packages/arb-avm-cpp/avm/src/inboxmessage.cpp.orig	2022-01-14 20:17:14 UTC
+++ packages/arb-avm-cpp/avm/src/inboxmessage.cpp
@@ -154,14 +154,14 @@ InboxMessage InboxMessage::fromTuple(const Tuple& tup)
         throw std::runtime_error("wrong tup size");
     }
     auto kind =
-        intx::narrow_cast<uint8_t>(get<uint256_t>(tup.get_element_unsafe(0)));
+        narrow_cast<uint8_t>(get<uint256_t>(tup.get_element_unsafe(0)));
     auto block_number = get<uint256_t>(tup.get_element_unsafe(1));
     auto timestamp = get<uint256_t>(tup.get_element_unsafe(2));
     auto sender_int = get<uint256_t>(tup.get_element_unsafe(3));
     auto inbox_sequence_number = get<uint256_t>(tup.get_element_unsafe(4));
     auto gas_price_l1 = get<uint256_t>(tup.get_element_unsafe(5));
     auto data_size =
-        intx::narrow_cast<uint64_t>(get<uint256_t>(tup.get_element_unsafe(6)));
+        narrow_cast<uint64_t>(get<uint256_t>(tup.get_element_unsafe(6)));
     auto data_buf = get<Buffer>(tup.get_element_unsafe(7));
 
     uint8_t raw_sender[32];
