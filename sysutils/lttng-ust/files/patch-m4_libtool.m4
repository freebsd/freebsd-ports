--- m4/libtool.m4.orig	2022-03-25 17:46:41 UTC
+++ m4/libtool.m4
@@ -728,6 +728,7 @@ _LT_CONFIG_SAVE_COMMANDS([
     cat <<_LT_EOF >> "$cfgfile"
 #! $SHELL
 # Generated automatically by $as_me ($PACKAGE) $VERSION
+# Libtool was configured on host `(hostname || uname -n) 2>/dev/null | sed 1q`:
 # NOTE: Changes made to this file will be lost: look at ltmain.sh.
 
 # Provide generalized library-building support services.
@@ -2886,18 +2887,6 @@ linux* | k*bsd*-gnu | kopensolaris*-gnu | gnu*)
   dynamic_linker='GNU/Linux ld.so'
   ;;
 
-netbsdelf*-gnu)
-  version_type=linux
-  need_lib_prefix=no
-  need_version=no
-  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major ${libname}${shared_ext}'
-  soname_spec='${libname}${release}${shared_ext}$major'
-  shlibpath_var=LD_LIBRARY_PATH
-  shlibpath_overrides_runpath=no
-  hardcode_into_libs=yes
-  dynamic_linker='NetBSD ld.elf_so'
-  ;;
-
 netbsd*)
   version_type=sunos
   need_lib_prefix=no
@@ -3557,7 +3546,7 @@ linux* | k*bsd*-gnu | kopensolaris*-gnu | gnu*)
   lt_cv_deplibs_check_method=pass_all
   ;;
 
-netbsd* | netbsdelf*-gnu)
+netbsd*)
   if echo __ELF__ | $CC -E - | $GREP __ELF__ > /dev/null; then
     lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so\.[[0-9]]+\.[[0-9]]+|_pic\.a)$'
   else
@@ -4063,8 +4052,7 @@ _LT_EOF
   if AC_TRY_EVAL(ac_compile); then
     # Now try to grab the symbols.
     nlist=conftest.nm
-    $ECHO "$as_me:$LINENO: $NM conftest.$ac_objext | $lt_cv_sys_global_symbol_pipe > $nlist" >&AS_MESSAGE_LOG_FD
-    if eval "$NM" conftest.$ac_objext \| "$lt_cv_sys_global_symbol_pipe" \> $nlist 2>&AS_MESSAGE_LOG_FD && test -s "$nlist"; then
+    if AC_TRY_EVAL(NM conftest.$ac_objext \| "$lt_cv_sys_global_symbol_pipe" \> $nlist) && test -s "$nlist"; then
       # Try sorting and uniquifying the output.
       if sort "$nlist" | uniq > "$nlist"T; then
 	mv -f "$nlist"T "$nlist"
@@ -4436,7 +4424,7 @@ m4_if([$1], [CXX], [
 	    ;;
 	esac
 	;;
-      netbsd* | netbsdelf*-gnu)
+      netbsd*)
 	;;
       *qnx* | *nto*)
         # QNX uses GNU C++, but need to define -shared option too, otherwise
@@ -4948,9 +4936,6 @@ m4_if([$1], [CXX], [
       ;;
     esac
     ;;
-  linux* | k*bsd*-gnu | gnu*)
-    _LT_TAGVAR(link_all_deplibs, $1)=no
-    ;;
   *)
     _LT_TAGVAR(export_symbols_cmds, $1)='$NM $libobjs $convenience | $global_symbol_pipe | $SED '\''s/.* //'\'' | sort | uniq > $export_symbols'
     ;;
@@ -5013,9 +4998,6 @@ dnl Note also adjust exclude_expsyms for C++ above.
   openbsd* | bitrig*)
     with_gnu_ld=no
     ;;
-  linux* | k*bsd*-gnu | gnu*)
-    _LT_TAGVAR(link_all_deplibs, $1)=no
-    ;;
   esac
 
   _LT_TAGVAR(ld_shlibs, $1)=yes
@@ -5270,7 +5252,7 @@ _LT_EOF
       fi
       ;;
 
-    netbsd* | netbsdelf*-gnu)
+    netbsd*)
       if echo __ELF__ | $CC -E - | $GREP __ELF__ >/dev/null; then
 	_LT_TAGVAR(archive_cmds, $1)='$LD -Bshareable $libobjs $deplibs $linker_flags -o $lib'
 	wlarc=
@@ -5791,7 +5773,6 @@ _LT_EOF
 	if test yes = "$lt_cv_irix_exported_symbol"; then
           _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $pic_flag $libobjs $deplibs $compiler_flags $wl-soname $wl$soname `test -n "$verstring" && func_echo_all "$wl-set_version $wl$verstring"` $wl-update_registry $wl$output_objdir/so_locations $wl-exports_file $wl$export_symbols -o $lib'
 	fi
-	_LT_TAGVAR(link_all_deplibs, $1)=no
       else
 	_LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags -soname $soname `test -n "$verstring" && func_echo_all "-set_version $verstring"` -update_registry $output_objdir/so_locations -o $lib'
 	_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags -soname $soname `test -n "$verstring" && func_echo_all "-set_version $verstring"` -update_registry $output_objdir/so_locations -exports_file $export_symbols -o $lib'
@@ -5813,7 +5794,7 @@ _LT_EOF
       esac
       ;;
 
-    netbsd* | netbsdelf*-gnu)
+    netbsd*)
       if echo __ELF__ | $CC -E - | $GREP __ELF__ >/dev/null; then
 	_LT_TAGVAR(archive_cmds, $1)='$LD -Bshareable -o $lib $libobjs $deplibs $linker_flags'  # a.out
       else
@@ -6439,7 +6420,7 @@ if test yes != "$_lt_caught_CXX_error"; then
       # Commands to make compiler produce verbose output that lists
       # what "hidden" libraries, object files and flags are used when
       # linking a shared library.
-      output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | $GREP -v "^Configured with:" | $GREP " \-L"'
+      output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | $GREP -v "^Configured with:" | $GREP "\-L"'
 
     else
       GXX=no
@@ -6814,7 +6795,7 @@ if test yes != "$_lt_caught_CXX_error"; then
             # explicitly linking system object files so we need to strip them
             # from the output so that they don't get included in the library
             # dependencies.
-            output_verbose_link_cmd='templist=`($CC -b $CFLAGS -v conftest.$objext 2>&1) | $EGREP " \-L"`; list= ; for z in $templist; do case $z in conftest.$objext) list="$list $z";; *.$objext);; *) list="$list $z";;esac; done; func_echo_all "$list"'
+            output_verbose_link_cmd='templist=`($CC -b $CFLAGS -v conftest.$objext 2>&1) | $EGREP "\-L"`; list= ; for z in $templist; do case $z in conftest.$objext) list="$list $z";; *.$objext);; *) list="$list $z";;esac; done; func_echo_all "$list"'
             ;;
           *)
             if test yes = "$GXX"; then
@@ -6879,7 +6860,7 @@ if test yes != "$_lt_caught_CXX_error"; then
 	    # explicitly linking system object files so we need to strip them
 	    # from the output so that they don't get included in the library
 	    # dependencies.
-	    output_verbose_link_cmd='templist=`($CC -b $CFLAGS -v conftest.$objext 2>&1) | $GREP " \-L"`; list= ; for z in $templist; do case $z in conftest.$objext) list="$list $z";; *.$objext);; *) list="$list $z";;esac; done; func_echo_all "$list"'
+	    output_verbose_link_cmd='templist=`($CC -b $CFLAGS -v conftest.$objext 2>&1) | $GREP "\-L"`; list= ; for z in $templist; do case $z in conftest.$objext) list="$list $z";; *.$objext);; *) list="$list $z";;esac; done; func_echo_all "$list"'
 	    ;;
           *)
 	    if test yes = "$GXX"; then
@@ -7218,7 +7199,7 @@ if test yes != "$_lt_caught_CXX_error"; then
 	      # Commands to make compiler produce verbose output that lists
 	      # what "hidden" libraries, object files and flags are used when
 	      # linking a shared library.
-	      output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | $GREP -v "^Configured with:" | $GREP " \-L"'
+	      output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | $GREP -v "^Configured with:" | $GREP "\-L"'
 
 	    else
 	      # FIXME: insert proper C++ library support
@@ -7302,7 +7283,7 @@ if test yes != "$_lt_caught_CXX_error"; then
 	        # Commands to make compiler produce verbose output that lists
 	        # what "hidden" libraries, object files and flags are used when
 	        # linking a shared library.
-	        output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | $GREP -v "^Configured with:" | $GREP " \-L"'
+	        output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | $GREP -v "^Configured with:" | $GREP "\-L"'
 	      else
 	        # g++ 2.7 appears to require '-G' NOT '-shared' on this
 	        # platform.
@@ -7313,7 +7294,7 @@ if test yes != "$_lt_caught_CXX_error"; then
 	        # Commands to make compiler produce verbose output that lists
 	        # what "hidden" libraries, object files and flags are used when
 	        # linking a shared library.
-	        output_verbose_link_cmd='$CC -G $CFLAGS -v conftest.$objext 2>&1 | $GREP -v "^Configured with:" | $GREP " \-L"'
+	        output_verbose_link_cmd='$CC -G $CFLAGS -v conftest.$objext 2>&1 | $GREP -v "^Configured with:" | $GREP "\-L"'
 	      fi
 
 	      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='$wl-R $wl$libdir'
