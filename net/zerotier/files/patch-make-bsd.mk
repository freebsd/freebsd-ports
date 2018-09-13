--- make-bsd.mk.orig	2018-09-13 10:12:22 UTC
+++ make-bsd.mk
@@ -159,7 +159,7 @@ clean:
 	rm -rf *.a *.o node/*.o controller/*.o osdep/*.o service/*.o ext/http-parser/*.o build-* zerotier-one zerotier-idtool zerotier-selftest zerotier-cli $(ONE_OBJS) $(CORE_OBJS)
 
 debug:	FORCE
-	gmake -j 4 ZT_DEBUG=1
+	$(MAKE) -j 4 ZT_DEBUG=1
 
 install:	one
 	rm -f /usr/local/sbin/zerotier-one
