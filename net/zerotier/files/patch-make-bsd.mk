--- make-bsd.mk.orig	2018-05-18 08:50:17 UTC
+++ make-bsd.mk
@@ -159,7 +159,7 @@ clean:
 	rm -rf *.a *.o node/*.o controller/*.o osdep/*.o service/*.o ext/http-parser/*.o build-* zerotier-one zerotier-idtool zerotier-selftest zerotier-cli $(ONE_OBJS) $(CORE_OBJS)
 
 debug:	FORCE
-	gmake -j 4 ZT_DEBUG=1
+	$(MAKE) -j ZT_DEBUG=1
 
 install:	one
 	rm -f /usr/local/sbin/zerotier-one
