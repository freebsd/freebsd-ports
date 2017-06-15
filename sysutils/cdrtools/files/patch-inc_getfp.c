###########################################################################
# This patch was contributed by Dimitry Andric.
###########################################################################
# The contents of this file are subject to the terms of the
# Common Development and Distribution License, Version 1.0 only
# (the "License").  You may not use this file except in compliance
# with the License.
#
# See the file CDDL.Schily.txt in this distribution for details.
#
# When distributing Covered Code, include this CDDL HEADER in each
# file and include the License file CDDL.Schily.txt from this distribution.
###########################################################################
# The file CDDL.Schily.txt can be found in the original cdrtools tarball,
# which is mirrored at ftp://ftp.freebsd.org/pub/FreeBSD/distfiles/.
###########################################################################

--- inc/getfp.c.orig	2008-06-13 22:32:03 UTC
+++ inc/getfp.c
@@ -52,7 +52,7 @@
 
 EXPORT	void	**___fpoff	__PR((char *cp));
 
-EXPORT void **
+EXPORT __noinline void **
 getfp()
 {
 		long	**dummy[1];
@@ -69,7 +69,7 @@ getfp()
  * We need this function to fool GCCs check for returning addresses
  * from outside the functions local address space.
  */
-EXPORT void **
+EXPORT __noinline void **
 ___fpoff(cp)
 	char	*cp;
 {
