--- deps/rabbitmq_cli/rabbitmq-mix.mk.orig	2019-05-18 19:51:26 UTC
+++ deps/rabbitmq_cli/rabbitmq-mix.mk
@@ -5,6 +5,7 @@
 
 HEX_OFFLINE=1
 
-HOME=$(DEPS_DIR)
+override MIX_HOME=$(DEPS_DIR)/.mix
+override HOME=$(DEPS_DIR)
 
-export HEX_OFFLINE HOME
+export HEX_OFFLINE MIX_HOME HOME
