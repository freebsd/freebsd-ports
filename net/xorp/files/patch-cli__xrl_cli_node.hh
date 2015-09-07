--- cli/xrl_cli_node.hh.orig	2012-01-11 17:56:10 UTC
+++ cli/xrl_cli_node.hh
@@ -224,6 +224,9 @@ protected:
 				     const string *cli_term_name,
 				     const uint32_t *cli_session_id,
 				     const string *command_output);
+
+    EventLoop&		_eventloop;
+
 private:
     /**
      * Called when Finder connection is established.
@@ -241,7 +244,7 @@ private:
 
     CliNode&	cli_node() const { return (_cli_node); }
 
-    EventLoop&		_eventloop;
+    // EventLoop&		_eventloop;
     CliNode&		_cli_node;
 
     XrlCliProcessorV0p1Client _xrl_cli_processor_client;
