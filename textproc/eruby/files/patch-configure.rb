Index: configure.rb.in
===================================================================
RCS file: /src/eruby/configure.rb.in,v
retrieving revision 1.9
diff -u -r1.9 configure.rb.in
--- configure.rb.in	3 Sep 2001 07:37:13 -0000	1.9
+++ configure.rb.in	18 Jan 2003 13:17:50 -0000
@@ -146,7 +146,7 @@
       $MKDLLIB << "\tenv LIB='$(subst /,\\\\,$(LIBPATH)); $(EXT_LIBRUBYARG) $(LIB)' \\\n\t"
     end
   end
-  $MKDLLIB << "$(LDSHARED) $(EXT_DLDFLAGS) -o $(DLLIB) $(EXT_OBJS) $(LIBERUBYARG) $(EXT_LIBRUBYARG) $(LIBS)"
+  $MKDLLIB << "$(LDSHARED) $(EXT_DLDFLAGS) -o $(DLLIB) $(EXT_OBJS) $(XLDFLAGS) $(LIBERUBYARG) $(EXT_LIBRUBYARG) $(LIBS)"
   if /mswin32/ =~ RUBY_PLATFORM && /nmake/i =~ $make
     $MKDLLIB << " -link /INCREMENTAL:no /EXPORT:Init_eruby"
   end
Index: configure.rb
===================================================================
RCS file: /src/eruby/configure.rb,v
retrieving revision 1.20
diff -u -r1.20 configure.rb
--- configure.rb	8 Jan 2003 08:24:20 -0000	1.20
+++ configure.rb	18 Jan 2003 13:17:50 -0000
@@ -283,6 +283,7 @@
 $VPATH = ""
 
 $arch = CONFIG["arch"]
+$sitearch = CONFIG["sitearch"]
 $ruby_version = Config::CONFIG["ruby_version"] ||
   CONFIG["MAJOR"] + "." + CONFIG["MINOR"]
 
@@ -346,6 +347,7 @@
 AC_SUBST("VPATH")
 
 AC_SUBST("arch")
+AC_SUBST("sitearch")
 AC_SUBST("ruby_version")
 AC_SUBST("drive")
 AC_SUBST("prefix")
@@ -531,7 +533,7 @@
       $MKDLLIB << "\tenv LIB='$(subst /,\\\\,$(LIBPATH)); $(EXT_LIBRUBYARG) $(LIB)' \\\n\t"
     end
   end
-  $MKDLLIB << "$(LDSHARED) $(EXT_DLDFLAGS) -o $(DLLIB) $(EXT_OBJS) $(LIBERUBYARG) $(EXT_LIBRUBYARG) $(LIBS)"
+  $MKDLLIB << "$(LDSHARED) $(EXT_DLDFLAGS) -o $(DLLIB) $(EXT_OBJS) $(XLDFLAGS) $(LIBERUBYARG) $(EXT_LIBRUBYARG) $(LIBS)"
   if /mswin32/ =~ RUBY_PLATFORM && /nmake/i =~ $make
     $MKDLLIB << " -link /INCREMENTAL:no /EXPORT:Init_eruby"
   end
