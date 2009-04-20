--- wmbluecpu.c	2003-03-17 12:02:13.000000000 +1030
+++ wmbluecpu.c	2009-02-11 12:35:43.966803000 +1030
@@ -32,12 +32,12 @@
  argv = varg;
  parse_arguments();
  make_window();
- start_timer();
+ cpu_init();
+ handle_timer(14);
  while(!exitloop)
  {
   process_events();
  }
- stop_timer();
  free_stuff();
  return 0;
 }
