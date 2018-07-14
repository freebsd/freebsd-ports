--- mrt/netstream_access.h.orig	2018-07-12 13:27:04 UTC
+++ mrt/netstream_access.h
@@ -120,7 +120,7 @@ do {									\
 
 #define GET_HOST_16(val, cp, rcvlen)					\
 do {									\
-	register uint16_t v_;						\
+	uint16_t v_;						\
 									\
 	if ((size_t)(rcvlen) < (size_t)2)				\
 		goto rcvlen_error;					\
@@ -132,7 +132,7 @@ do {									\
 
 #define PUT_HOST_16(val, cp, buflen)					\
 do {									\
-	register uint16_t v_;						\
+	uint16_t v_;						\
 									\
 	if ((size_t)(buflen) < (size_t)2)				\
 		goto buflen_error;					\
@@ -145,7 +145,7 @@ do {									\
 #if defined(BYTE_ORDER) && (BYTE_ORDER == LITTLE_ENDIAN)
 #define GET_NET_16(val, cp, rcvlen)					\
 do {									\
-	register uint16_t v_;						\
+	uint16_t v_;						\
 									\
 	if ((size_t)(rcvlen) < (size_t)2)				\
 		goto rcvlen_error;					\
@@ -156,7 +156,7 @@ do {									\
 } while (0)
 #define PUT_NET_16(val, cp, buflen)					\
 do {									\
-	register uint16_t v_;						\
+	uint16_t v_;						\
 									\
 	if ((size_t)(buflen) < (size_t)2)				\
 		goto buflen_error;					\
@@ -174,7 +174,7 @@ do {									\
 
 #define GET_HOST_32(val, cp, rcvlen)					\
 do {									\
-	register uint32_t v_;						\
+	uint32_t v_;						\
 									\
 	if ((size_t)(rcvlen) < (size_t)4)				\
 		goto rcvlen_error;					\
@@ -188,7 +188,7 @@ do {									\
 
 #define PUT_HOST_32(val, cp, buflen)					\
 do {									\
-	register uint32_t v_;						\
+	uint32_t v_;						\
 									\
 	if ((size_t)(buflen) < (size_t)4)				\
 		goto buflen_error;					\
@@ -203,7 +203,7 @@ do {									\
 #if defined(BYTE_ORDER) && (BYTE_ORDER == LITTLE_ENDIAN)
 #define GET_NET_32(val, cp, rcvlen)					\
 do {									\
-	register uint32_t v_;						\
+	uint32_t v_;						\
 									\
 	if ((size_t)(rcvlen) < (size_t)4)				\
 		goto rcvlen_error;					\
@@ -217,7 +217,7 @@ do {									\
 
 #define PUT_NET_32(val, cp, buflen)					\
 do {									\
-	register uint32_t v_;						\
+	uint32_t v_;						\
 									\
 	if ((size_t)(buflen) < (size_t)4)				\
 		goto buflen_error;					\
