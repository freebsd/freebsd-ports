--- resources/views/graphs/realtime.blade.php.orig	2026-03-17 09:25:34 UTC
+++ resources/views/graphs/realtime.blade.php
@@ -1,4 +1,4 @@
-{!! '<?xml version="1.0" encoding="UTF-8"?>' !!}
+{!! '<' . '?xml version="1.0" encoding="UTF-8"?>' !!}
 <svg width="100%" height="100%" viewBox="0 0 {{ $width }} {{ $height }}" preserveAspectRatio="none" xml:space="preserve" xmlns="http://www.w3.org/2000/svg"
      onload="init(evt)">
   <g id="graph">
