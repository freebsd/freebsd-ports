--- scripts/ais-relay.cjs.orig	2026-11-03 16:09:19 UTC
+++ scripts/ais-relay.cjs
@@ -15461,7 +15461,7 @@ const wss = new WebSocketServer({ server });
 
 const wss = new WebSocketServer({ server });
 
-server.listen(PORT, () => {
+server.listen(PORT, "127.0.0.1", () => {
   const listeningPort = server.address()?.port || PORT;
   relayBoundPort = listeningPort;
   console.log(`[Relay] WebSocket relay on port ${listeningPort} (OpenSky route: ${OPENSKY_ROUTE}${OPENSKY_ROUTE_REQUESTED !== OPENSKY_ROUTE ? ` — "${OPENSKY_ROUTE_REQUESTED}" requested but unconfigured` : ''})`);
