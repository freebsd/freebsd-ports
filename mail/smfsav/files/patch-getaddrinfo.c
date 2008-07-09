--- ../src/lib/irs/getaddrinfo.c.orig	2008-06-25 18:33:53.000000000 +0000
+++ ../src/lib/irs/getaddrinfo.c	2008-06-25 18:34:20.000000000 +0000
@@ -332,7 +332,7 @@
 	pai->ai_family = PF_UNSPEC;
 	pai->ai_socktype = ANY;
 	pai->ai_protocol = ANY;
-#ifdef __sparcv9
+#if defined __sparcv9 && !defined(__FreeBSD__)
 	/*
 	 * clear _ai_pad to preserve binary
 	 * compatibility with previously compiled 64-bit
@@ -365,7 +365,7 @@
 		}
 		memcpy(pai, hints, sizeof(*pai));
 
-#ifdef __sparcv9
+#if defined __sparcv9 && !defined(__FreeBSD__)
 		/*
 		 * We need to clear _ai_pad to preserve binary
 		 * compatibility.  See prior comment.
