--- src/makefiles/freebsd_32bit.mak.orig	2016-04-24 14:49:31 UTC
+++ src/makefiles/freebsd_32bit.mak
@@ -25,19 +25,19 @@
 
 #CC=gcc
 
-OPTIONS_COMPILE_DEBUG=-D_DEBUG -DDEBUG -DUNIX -DUNIX_BSD -DBRIDGE_BPF -DNO_VLAN -D_REENTRANT -DREENTRANT -D_THREAD_SAFE -D_THREADSAFE -DTHREAD_SAFE -DTHREADSAFE -D_FILE_OFFSET_BITS=64 -I./src/ -I./src/Cedar/ -I./src/Mayaqua/ -I/usr/local/include -I/usr/include -g -fsigned-char
+OPTIONS_COMPILE_DEBUG=-D_DEBUG -DDEBUG -DUNIX -DUNIX_BSD -DBRIDGE_BPF -DNO_VLAN -D_REENTRANT -DREENTRANT -D_THREAD_SAFE -D_THREADSAFE -DTHREAD_SAFE -DTHREADSAFE -D_FILE_OFFSET_BITS=64 -I./src/ -I./src/Cedar/ -I./src/Mayaqua/ -g -fsigned-char
 
-OPTIONS_LINK_DEBUG=-g -fsigned-char -L/usr/local/lib -L/usr/lib -lm -lpthread -lssl -lcrypto -liconv -lreadline -lncurses -lz
+OPTIONS_LINK_DEBUG=-g -fsigned-char -lm -lpthread -lssl -lcrypto ${ICONV_LIB} -lreadline -lncurses -lz
 
-OPTIONS_COMPILE_RELEASE=-DNDEBUG -DVPN_SPEED -DUNIX -DUNIX_BSD -DBRIDGE_BPF -DNO_VLAN -D_REENTRANT -DREENTRANT -D_THREAD_SAFE -D_THREADSAFE -DTHREAD_SAFE -DTHREADSAFE -D_FILE_OFFSET_BITS=64 -I./src/ -I./src/Cedar/ -I./src/Mayaqua/ -I/usr/local/include -I/usr/include -O2 -fsigned-char
+OPTIONS_COMPILE_RELEASE=-DNDEBUG -DVPN_SPEED -DUNIX -DUNIX_BSD -DBRIDGE_BPF -DNO_VLAN -D_REENTRANT -DREENTRANT -D_THREAD_SAFE -D_THREADSAFE -DTHREAD_SAFE -DTHREADSAFE -D_FILE_OFFSET_BITS=64 -I./src/ -I./src/Cedar/ -I./src/Mayaqua/ -fsigned-char ${CFLAGS}
 
-OPTIONS_LINK_RELEASE=-O2 -fsigned-char -L/usr/local/lib -L/usr/lib -lm -lpthread -lssl -lcrypto -liconv -lreadline -lncurses -lz
+OPTIONS_LINK_RELEASE=-fsigned-char ${LDFLAGS} ${LIBS} -lm -lpthread -lssl -lcrypto ${ICONV_LIB} -lreadline -lncurses -lz
 
-INSTALL_BINDIR=/usr/bin/
-INSTALL_VPNSERVER_DIR=/usr/vpnserver/
-INSTALL_VPNBRIDGE_DIR=/usr/vpnbridge/
-INSTALL_VPNCLIENT_DIR=/usr/vpnclient/
-INSTALL_VPNCMD_DIR=/usr/vpncmd/
+INSTALL_BINDIR=${PREFIX}/sbin/
+INSTALL_VPNSERVER_DIR=${PREFIX}/softethervpn/vpnserver/
+INSTALL_VPNBRIDGE_DIR=${PREFIX}/softethervpn/vpnbridge/
+INSTALL_VPNCLIENT_DIR=${PREFIX}/softethervpn/vpnclient/
+INSTALL_VPNCMD_DIR=${PREFIX}/softethervpn/vpncmd/
 
 ifeq ($(DEBUG),YES)
 	OPTIONS_COMPILE=$(OPTIONS_COMPILE_DEBUG)
@@ -379,7 +379,7 @@ tmp/objs/vpncmd.o: src/vpncmd/vpncmd.c $
 	$(CC) $(OPTIONS_COMPILE) -c src/vpncmd/vpncmd.c -o tmp/objs/vpncmd.o
 
 # Install
-install: $(INSTALL_BINDIR)vpnserver $(INSTALL_BINDIR)vpnbridge $(INSTALL_BINDIR)vpnclient $(INSTALL_BINDIR)vpncmd
+install: $(STAGEDIR)$(INSTALL_BINDIR)vpnserver $(STAGEDIR)$(INSTALL_BINDIR)vpnbridge $(STAGEDIR)$(INSTALL_BINDIR)vpnclient $(STAGEDIR)$(INSTALL_BINDIR)vpncmd
 	@echo
 	@echo "--------------------------------------------------------------------"
 	@echo "Installation completed successfully."
@@ -391,41 +391,37 @@ install: $(INSTALL_BINDIR)vpnserver $(IN
 	@echo "--------------------------------------------------------------------"
 	@echo
 
-$(INSTALL_BINDIR)vpnserver: bin/vpnserver/hamcore.se2 bin/vpnserver/vpnserver
-	@mkdir -p $(INSTALL_VPNSERVER_DIR)
-	cp bin/vpnserver/hamcore.se2 $(INSTALL_VPNSERVER_DIR)hamcore.se2
-	cp bin/vpnserver/vpnserver $(INSTALL_VPNSERVER_DIR)vpnserver
-	echo "#!/bin/sh" > $(INSTALL_BINDIR)vpnserver
-	echo $(INSTALL_VPNSERVER_DIR)vpnserver '"$$@"' >> $(INSTALL_BINDIR)vpnserver
-	echo 'exit $$?' >> $(INSTALL_BINDIR)vpnserver
-	chmod 755 $(INSTALL_BINDIR)vpnserver
+$(STAGEDIR)$(INSTALL_BINDIR)vpnserver: bin/vpnserver/hamcore.se2 bin/vpnserver/vpnserver
+	@mkdir -p $(STAGEDIR)$(INSTALL_VPNSERVER_DIR)
+	cp bin/vpnserver/hamcore.se2 $(STAGEDIR)$(INSTALL_VPNSERVER_DIR)hamcore.se2
+	$(BSD_INSTALL_PROGRAM) bin/vpnserver/vpnserver $(STAGEDIR)$(INSTALL_VPNSERVER_DIR)vpnserver
+	echo "#!/bin/sh" > $(STAGEDIR)$(INSTALL_BINDIR)vpnserver
+	echo exec $(INSTALL_VPNSERVER_DIR)vpnserver '"$$@"' >> $(STAGEDIR)$(INSTALL_BINDIR)vpnserver
+	chmod 755 $(STAGEDIR)$(INSTALL_BINDIR)vpnserver
 
-$(INSTALL_BINDIR)vpnbridge: bin/vpnbridge/hamcore.se2 bin/vpnbridge/vpnbridge
-	@mkdir -p $(INSTALL_VPNBRIDGE_DIR)
-	cp bin/vpnbridge/hamcore.se2 $(INSTALL_VPNBRIDGE_DIR)hamcore.se2
-	cp bin/vpnbridge/vpnbridge $(INSTALL_VPNBRIDGE_DIR)vpnbridge
-	echo "#!/bin/sh" > $(INSTALL_BINDIR)vpnbridge
-	echo $(INSTALL_VPNBRIDGE_DIR)vpnbridge '"$$@"' >> $(INSTALL_BINDIR)vpnbridge
-	echo 'exit $$?' >> $(INSTALL_BINDIR)vpnbridge
-	chmod 755 $(INSTALL_BINDIR)vpnbridge
+$(STAGEDIR)$(INSTALL_BINDIR)vpnbridge: bin/vpnbridge/hamcore.se2 bin/vpnbridge/vpnbridge
+	@mkdir -p $(STAGEDIR)$(INSTALL_VPNBRIDGE_DIR)
+	cp bin/vpnbridge/hamcore.se2 $(STAGEDIR)$(INSTALL_VPNBRIDGE_DIR)hamcore.se2
+	$(BSD_INSTALL_PROGRAM) bin/vpnbridge/vpnbridge $(STAGEDIR)$(INSTALL_VPNBRIDGE_DIR)vpnbridge
+	echo "#!/bin/sh" > $(STAGEDIR)$(INSTALL_BINDIR)vpnbridge
+	echo exec $(INSTALL_VPNBRIDGE_DIR)vpnbridge '"$$@"' >> $(STAGEDIR)$(INSTALL_BINDIR)vpnbridge
+	chmod 755 $(STAGEDIR)$(INSTALL_BINDIR)vpnbridge
 
-$(INSTALL_BINDIR)vpnclient: bin/vpnclient/hamcore.se2 bin/vpnclient/vpnclient
-	@mkdir -p $(INSTALL_VPNCLIENT_DIR)
-	cp bin/vpnclient/hamcore.se2 $(INSTALL_VPNCLIENT_DIR)hamcore.se2
-	cp bin/vpnclient/vpnclient $(INSTALL_VPNCLIENT_DIR)vpnclient
-	echo "#!/bin/sh" > $(INSTALL_BINDIR)vpnclient
-	echo $(INSTALL_VPNCLIENT_DIR)vpnclient '"$$@"' >> $(INSTALL_BINDIR)vpnclient
-	echo 'exit $$?' >> $(INSTALL_BINDIR)vpnclient
-	chmod 755 $(INSTALL_BINDIR)vpnclient
+$(STAGEDIR)$(INSTALL_BINDIR)vpnclient: bin/vpnclient/hamcore.se2 bin/vpnclient/vpnclient
+	@mkdir -p $(STAGEDIR)$(INSTALL_VPNCLIENT_DIR)
+	cp bin/vpnclient/hamcore.se2 $(STAGEDIR)$(INSTALL_VPNCLIENT_DIR)hamcore.se2
+	$(BSD_INSTALL_PROGRAM) bin/vpnclient/vpnclient $(STAGEDIR)$(INSTALL_VPNCLIENT_DIR)vpnclient
+	echo "#!/bin/sh" > $(STAGEDIR)$(INSTALL_BINDIR)vpnclient
+	echo exec $(INSTALL_VPNCLIENT_DIR)vpnclient '"$$@"' >> $(STAGEDIR)$(INSTALL_BINDIR)vpnclient
+	chmod 755 $(STAGEDIR)$(INSTALL_BINDIR)vpnclient
 
-$(INSTALL_BINDIR)vpncmd: bin/vpncmd/hamcore.se2 bin/vpncmd/vpncmd
-	@mkdir -p $(INSTALL_VPNCMD_DIR)
-	cp bin/vpncmd/hamcore.se2 $(INSTALL_VPNCMD_DIR)hamcore.se2
-	cp bin/vpncmd/vpncmd $(INSTALL_VPNCMD_DIR)vpncmd
-	echo "#!/bin/sh" > $(INSTALL_BINDIR)vpncmd
-	echo $(INSTALL_VPNCMD_DIR)vpncmd '"$$@"' >> $(INSTALL_BINDIR)vpncmd
-	echo 'exit $$?' >> $(INSTALL_BINDIR)vpncmd
-	chmod 755 $(INSTALL_BINDIR)vpncmd
+$(STAGEDIR)$(INSTALL_BINDIR)vpncmd: bin/vpncmd/hamcore.se2 bin/vpncmd/vpncmd
+	@mkdir -p $(STAGEDIR)$(INSTALL_VPNCMD_DIR)
+	cp bin/vpncmd/hamcore.se2 $(STAGEDIR)$(INSTALL_VPNCMD_DIR)hamcore.se2
+	$(BSD_INSTALL_PROGRAM) bin/vpncmd/vpncmd $(STAGEDIR)$(INSTALL_VPNCMD_DIR)vpncmd
+	echo "#!/bin/sh" > $(STAGEDIR)$(INSTALL_BINDIR)vpncmd
+	echo exec $(INSTALL_VPNCMD_DIR)vpncmd '"$$@"' >> $(STAGEDIR)$(INSTALL_BINDIR)vpncmd
+	chmod 755 $(STAGEDIR)$(INSTALL_BINDIR)vpncmd
 
 # Clean
 clean:
