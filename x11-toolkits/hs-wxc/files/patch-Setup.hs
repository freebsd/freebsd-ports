--- Setup.hs.orig	2017-04-28 17:40:12 UTC
+++ Setup.hs
@@ -15,7 +15,7 @@ import Distribution.Simple.LocalBuildInfo (LocalBuildI
 import Distribution.Simple.PackageIndex(SearchResult (..), searchByName )
 import Distribution.Simple.Program (ConfiguredProgram (..), lookupProgram, runProgram, simpleProgram, locationPath)
 import Distribution.Simple.Setup ( BuildFlags, ConfigFlags
-                                 , CopyDest(..), CopyFlags, copyVerbosity
+                                 , CopyDest(..), CopyFlags, copyVerbosity, copyDest
                                  , InstallFlags, installVerbosity
                                  , fromFlag, fromFlagOrDefault, copyDest
                                  )
@@ -640,7 +640,7 @@ ldconfig path = case buildOS of
                 otherwise -> error "Couldn't execute ldconfig, ensure it is on your path"
 
 myCopyHook :: PackageDescription -> LocalBuildInfo -> UserHooks -> CopyFlags -> IO ()
-myCopyHook = hookHelper (fromFlag . copyVerbosity) (fromFlagOrDefault NoCopyDest . copyDest) (copyHook simpleUserHooks)
+myCopyHook = hookHelper (fromFlag . copyVerbosity) (fromFlag . copyDest) (copyHook simpleUserHooks)
 
 myInstHook :: PackageDescription -> LocalBuildInfo -> UserHooks -> InstallFlags -> IO ()
 myInstHook = hookHelper (fromFlag . installVerbosity) (const NoCopyDest) (instHook simpleUserHooks)
@@ -668,4 +668,3 @@ hookHelper verbosity copydest origHook pkg_descr local
         inst_lib_dir = libdir $ absoluteInstallDirs pkg_descr local_bld_info (copydest flags)
 
     installOrdinaryFile (verbosity flags) (bld_dir </> lib_name) (inst_lib_dir </> lib_name)
-    ldconfig inst_lib_dir
