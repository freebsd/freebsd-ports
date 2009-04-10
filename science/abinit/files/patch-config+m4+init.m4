--- ./config/m4/init.m4.orig	2009-03-11 06:12:22.000000000 +0100
+++ ./config/m4/init.m4	2009-03-28 16:29:06.000000000 +0100
@@ -231,6 +231,101 @@
    abi_cpu_bits="64"
    ;;
 
+  i386-*freebsd*)
+  dnl Pentium 3 ?
+  if test "${abi_cpu_model}" = ""; then
+   abi_cpu_model=`sysctl hw.model | grep 'Pentium III'`
+   if test "${abi_cpu_model}" != ""; then
+    abi_cpu_model="pentium3"
+    abi_cpu_64bits="no"
+    abi_cpu_bits="32"
+   fi
+  fi
+  dnl Pentium 4 ?
+  if test "${abi_cpu_model}" = ""; then
+   abi_cpu_model=`sysctl hw.model | grep 'Intel(R) Pentium(R) 4'`
+   if test "${abi_cpu_model}" != ""; then
+    abi_cpu_model="pentium4"
+    abi_cpu_64bits="no"
+    abi_cpu_bits="32"
+   fi
+  fi
+  dnl Pentium 4M ?
+  if test "${abi_cpu_model}" = ""; then
+   abi_cpu_model=`sysctl hw.model | grep 'Intel(R) Pentium(R) M'`
+   if test "${abi_cpu_model}" != ""; then
+    abi_cpu_model="pentium4"
+    abi_cpu_64bits="no"
+    abi_cpu_bits="32"
+   fi
+  fi
+  dnl Unknown
+  if test "${abi_cpu_model}" = ""; then
+   abi_cpu_model="unknown"
+  fi
+  dnl The processor is anyway 32-bit
+  abi_cpu_64bits="no"
+  abi_cpu_bits="32"
+  ;;
+
+  amd64-*freebsd*)
+  dnl Opteron ?
+  if test "${abi_cpu_model}" = ""; then
+   abi_cpu_model=`sysctl hw.model | grep 'Opteron'`
+   if test "${abi_cpu_model}" != ""; then
+    abi_cpu_model="opteron"
+    abi_cpu_64bits="yes"
+    abi_cpu_bits="64"
+   fi
+  fi
+  dnl Xeon ?
+  if test "${abi_cpu_model}" = ""; then
+   abi_cpu_model=`sysctl hw.model | grep 'Intel(R) XEON(TM)'`
+   if test "${abi_cpu_model}" != ""; then
+    abi_cpu_model="xeon"
+    abi_cpu_64bits="yes"
+    abi_cpu_bits="64"
+   fi
+  fi
+  dnl Unknown
+  if test "${abi_cpu_model}" = ""; then
+   abi_cpu_model="unknown"
+  fi
+  dnl The processor is anyway 64-bit
+  abi_cpu_64bits="yes"
+  abi_cpu_bits="64"
+  ;;
+
+  ia64-*freebsd*)
+  dnl Itanium 1 ?
+  if test "${abi_cpu_model}" = ""; then
+   abi_cpu_model=`sysctl hw.model | grep 'Itanium 1'`
+   if test "${abi_cpu_model}" = ""; then
+    abi_cpu_model="itanium1"
+   fi
+  fi
+  dnl Itanium 2 ?
+  if test "${abi_cpu_model}" = ""; then
+   abi_cpu_model=`sysctl hw.model | grep 'Itanium 2'`
+   if test "${abi_cpu_model}" != ""; then
+    abi_cpu_model="itanium2"
+   fi
+  fi
+  dnl Unknown
+  if test "${abi_cpu_model}" = ""; then
+   abi_cpu_model="unknown"
+  fi
+  dnl The processor is anyway 64-bit
+  abi_cpu_64bits="yes"
+  abi_cpu_bits="64"
+  ;;
+
+  sparc64-*freebsd*)
+   abi_cpu_model="unknown"
+   abi_cpu_64bits="yes"
+   abi_cpu_bits="64"
+  ;;
+
  esac
 
  AC_SUBST(abi_cpu_vendor)
@@ -289,15 +384,15 @@
  fi
 
  dnl Set-up all directory names
- abinit_bindir="${abinit_prefix}/abinit/${ABINIT_VERSION_BASE}/bin"
- abinit_chkdir="${abinit_prefix}/abinit/${ABINIT_VERSION_BASE}/tests"
- abinit_datdir="${abinit_prefix}/abinit"
- abinit_docdir="${abinit_prefix}/abinit/${ABINIT_VERSION_BASE}/doc"
- abinit_incdir="${abinit_prefix}/abinit/${ABINIT_VERSION_BASE}/include"
- abinit_libdir="${abinit_prefix}/abinit/${ABINIT_VERSION_BASE}/lib"
- abinit_mandir="${abinit_prefix}/abinit/man"
- abinit_rundir="${abinit_prefix}/abinit/bin"
- abinit_wwwdir="${abinit_prefix}/abinit/${ABINIT_VERSION_BASE}/www"
+ abinit_bindir="${abinit_prefix}/bin"
+ abinit_chkdir="${abinit_prefix}/share/examples/abinit/tests"
+ abinit_datdir="${abinit_prefix}/share/abinit"
+ abinit_docdir="${abinit_prefix}/share/doc/abinit/"
+ abinit_incdir="${abinit_prefix}/include/abinit"
+ abinit_libdir="${abinit_prefix}/lib"
+ abinit_mandir="${abinit_prefix}/man"
+ abinit_rundir="${abinit_prefix}/bin"
+ abinit_wwwdir="${abinit_prefix}/www/abinit"
 
  dnl Substitute all variables
  AC_SUBST(abinit_prefix)
