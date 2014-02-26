--- ./cli/xrl_cli_node.hh.orig	2011-03-16 21:27:45.000000000 +0000
+++ ./cli/xrl_cli_node.hh	2014-02-26 21:17:13.000000000 +0000
@@ -224,6 +224,9 @@
 				     const string *cli_term_name,
 				     const uint32_t *cli_session_id,
 				     const string *command_output);
+
+    EventLoop&		_eventloop;
+
 private:
     /**
      * Called when Finder connection is established.
@@ -241,7 +244,7 @@
 
     CliNode&	cli_node() const { return (_cli_node); }
 
-    EventLoop&		_eventloop;
+    // EventLoop&		_eventloop;
     CliNode&		_cli_node;
 
     XrlCliProcessorV0p1Client _xrl_cli_processor_client;
