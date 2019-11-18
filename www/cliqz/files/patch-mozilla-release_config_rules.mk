--- mozilla-release/config/rules.mk.orig	2019-11-13 13:22:25 UTC
+++ mozilla-release/config/rules.mk
@@ -960,20 +960,20 @@ $(EXTENSIONS_PATH):
 CLIQZ_XPI_PATH = $(EXTENSIONS_PATH)/cliqz@cliqz.com.xpi
 $(CLIQZ_XPI_PATH): $(EXTENSIONS_PATH)
 	echo CLIQZ_XPI_PATH in `pwd`
-	wget --output-document $(CLIQZ_XPI_PATH) $(CLIQZ_EXT_URL)
+#	wget --output-document $(CLIQZ_XPI_PATH) $(CLIQZ_EXT_URL)
 
 HTTPSE_XPI_PATH = $(EXTENSIONS_PATH)/https-everywhere@cliqz.com.xpi
 $(HTTPSE_XPI_PATH): $(EXTENSIONS_PATH)
 ifdef HTTPSE_EXT_URL
 	echo HTTPSE_XPI_PATH in `pwd`
-	wget --output-document $(HTTPSE_XPI_PATH) $(HTTPSE_EXT_URL)
+#	wget --output-document $(HTTPSE_XPI_PATH) $(HTTPSE_EXT_URL)
 endif
 
 CONSENTRICK_XPI_PATH = $(EXTENSIONS_PATH)/gdprtool@cliqz.com.xpi
 $(CONSENTRICK_XPI_PATH): $(EXTENSIONS_PATH)
 ifdef CONSENTRICK_EXT_URL
 	echo CONSENTRICK_XPI_PATH in `pwd`
-	wget --output-document $(CONSENTRICK_XPI_PATH) $(CONSENTRICK_EXT_URL)
+#	wget --output-document $(CONSENTRICK_XPI_PATH) $(CONSENTRICK_EXT_URL)
 endif
 
 DAT_XPI_PATH = $(EXTENSIONS_PATH)/dat@cliqz.com.xpi
