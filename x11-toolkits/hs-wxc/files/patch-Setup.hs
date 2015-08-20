--- Setup.hs.orig	2014-08-11 14:25:54 UTC
+++ Setup.hs
@@ -12,7 +12,7 @@ import Distribution.Simple.LocalBuildInf
 import Distribution.Simple.PackageIndex(SearchResult (..), searchByName )
 import Distribution.Simple.Program (ConfiguredProgram (..), lookupProgram, runProgram, simpleProgram, locationPath)
 import Distribution.Simple.Setup ( BuildFlags, ConfigFlags
-                                 , CopyDest(..), CopyFlags, copyVerbosity
+                                 , CopyDest(..), CopyFlags, copyVerbosity, copyDest
                                  , InstallFlags, installVerbosity
                                  , fromFlag
                                  )
@@ -480,16 +480,17 @@ ldconfig path = case buildOS of
                 otherwise -> error "Couldn't execute ldconfig, ensure it is on your path"
 
 myCopyHook :: PackageDescription -> LocalBuildInfo -> UserHooks -> CopyFlags -> IO ()
-myCopyHook = hookHelper (fromFlag . copyVerbosity) (copyHook simpleUserHooks)
+myCopyHook = hookHelper (fromFlag . copyVerbosity) (fromFlag . copyDest) (copyHook simpleUserHooks)
 
 myInstHook :: PackageDescription -> LocalBuildInfo -> UserHooks -> InstallFlags -> IO ()
-myInstHook = hookHelper (fromFlag . installVerbosity) (instHook simpleUserHooks)
+myInstHook = hookHelper (fromFlag . installVerbosity) (const NoCopyDest) (instHook simpleUserHooks)
 
 hookHelper ::
     (a -> Verbosity) ->
+    (a -> CopyDest) ->
     (PackageDescription -> LocalBuildInfo -> UserHooks -> a -> IO ()) ->
     PackageDescription -> LocalBuildInfo -> UserHooks -> a -> IO ()
-hookHelper verbosity origHook pkg_descr local_bld_info user_hooks flags =
+hookHelper verbosity copyDest origHook pkg_descr local_bld_info user_hooks flags =
     do
     -- Perform simpleUserHooks (copyHook/instHook => to copy installIncludes)
     origHook pkg_descr local_bld_info user_hooks flags
@@ -504,8 +505,7 @@ hookHelper verbosity origHook pkg_descr 
         dll_name = fromJust (lookup "x-dll-name" custom_bi)
         lib_name = sharedLibName ver dll_name
 
-        inst_lib_dir = libdir $ absoluteInstallDirs pkg_descr local_bld_info NoCopyDest
+        inst_lib_dir = libdir $ absoluteInstallDirs pkg_descr local_bld_info (copyDest flags)
 
     installOrdinaryFile (verbosity flags) (bld_dir </> lib_name) (inst_lib_dir </> lib_name)
-    ldconfig inst_lib_dir
 
