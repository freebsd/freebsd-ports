--- src/types/casting.cpp.orig	2020-08-28 21:44:53 UTC
+++ src/types/casting.cpp
@@ -199,7 +199,7 @@ T1_TO_T2(str, flt)
   catch (std::invalid_argument const&) 
   {
     throwTypeException(err::FORG0001, aErrorInfo);
-    return NULL;
+    return false;
   }
   catch ( std::range_error const& ) 
   {
@@ -218,7 +218,7 @@ T1_TO_T2(str, dbl)
   catch (std::invalid_argument const& ) 
   {
     throwTypeException(err::FORG0001, aErrorInfo);
-    return NULL;
+    return false;
   }
   catch (std::range_error const& ) 
   {
@@ -237,7 +237,7 @@ T1_TO_T2(str, dec)
   catch ( std::exception const& ) 
   {
     throwTypeException( err::FORG0001, aErrorInfo );
-    return NULL;
+    return false;
   }
 }
 
@@ -252,12 +252,12 @@ T1_TO_T2(str, int)
   catch ( std::invalid_argument const& ) 
   {
     throwTypeException( err::FORG0001, aErrorInfo );
-    return NULL;
+    return false;
   }
   catch ( std::range_error const& ) 
   {
     throwTypeException( err::FOAR0002, aErrorInfo );
-    return NULL;
+    return false;
   }
 }
 
@@ -271,7 +271,7 @@ T1_TO_T2(str, dur)
     return aFactory->createDuration(result, &d);
 
   throwTypeException(err::FORG0001, aErrorInfo);
-  return NULL;
+  return false;
 }
 
 
@@ -284,7 +284,7 @@ T1_TO_T2(str, yMD)
     return aFactory->createYearMonthDuration(result, &d);
 
   throwTypeException( err::FORG0001, aErrorInfo );
-  return NULL;
+  return false;
 }
 
 
@@ -297,7 +297,7 @@ T1_TO_T2(str, dTD)
     return aFactory->createDayTimeDuration(result, &d);
 
   throwTypeException( err::FORG0001, aErrorInfo );
-  return NULL;
+  return false;
 }
 
 
@@ -308,7 +308,7 @@ T1_TO_T2(str, dT)
     return aFactory->createDateTime(result, &dt);
 
   throwTypeException( err::FORG0001, aErrorInfo );
-  return NULL;
+  return false;
 }
 
 
@@ -319,7 +319,7 @@ T1_TO_T2(str, tim)
     return aFactory->createTime(result, &t);
 
   throwTypeException( err::FORG0001, aErrorInfo );
-  return NULL;
+  return false;
 }
 
 
@@ -330,7 +330,7 @@ T1_TO_T2(str, dat)
     return aFactory->createDate(result, &d);
 
   throwTypeException( err::FORG0001, aErrorInfo );
-  return NULL;
+  return false;
 }
 
 
@@ -341,7 +341,7 @@ T1_TO_T2(str, gYM)
     return aFactory->createGYearMonth(result, &ym);
 
   throwTypeException( err::FORG0001, aErrorInfo );
-  return NULL;
+  return false;
 }
 
 
@@ -352,7 +352,7 @@ T1_TO_T2(str, gYr)
     return aFactory->createGYear(result, &y);
 
   throwTypeException( err::FORG0001, aErrorInfo );
-  return NULL;
+  return false;
 }
 
 
@@ -363,7 +363,7 @@ T1_TO_T2(str, gMD)
     return aFactory->createGMonthDay(result, &md);
 
   throwTypeException( err::FORG0001, aErrorInfo );
-  return NULL;
+  return false;
 }
 
 
@@ -374,7 +374,7 @@ T1_TO_T2(str, gDay)
     return aFactory->createGDay(result, &d);
 
   throwTypeException( err::FORG0001, aErrorInfo );
-  return NULL;
+  return false;
 }
 
 
@@ -385,7 +385,7 @@ T1_TO_T2(str, gMon)
     return aFactory->createGMonth(result, &m);
 
   throwTypeException( err::FORG0001, aErrorInfo );
-  return NULL;
+  return false;
 }
 
 
@@ -423,7 +423,7 @@ T1_TO_T2(str, bool)
   else
   {
     throwTypeException( err::FORG0001, aErrorInfo );
-    return NULL;
+    return false;
   }
 
   pos = str - strval.c_str();
@@ -443,7 +443,7 @@ T1_TO_T2(str, b64)
     return aFactory->createBase64Binary(result, n);
 
   throwTypeException( err::FORG0001, aErrorInfo );
-  return NULL;
+  return false;
 }
 
 
@@ -454,7 +454,7 @@ T1_TO_T2(str, hxB)
     return aFactory->createHexBinary(result, n);
 
   throwTypeException( err::FORG0001, aErrorInfo );
-  return NULL;
+  return false;
 }
 
 
@@ -736,7 +736,7 @@ T1_TO_T2(flt, dec)
   catch ( std::exception const& /*e*/ ) 
   {
     throwTypeException( err::FOCA0002, aErrorInfo );
-    return NULL;
+    return false;
   }
 }
 
@@ -750,7 +750,7 @@ T1_TO_T2(flt, int)
   catch ( std::exception const& ) 
   {
     throwTypeException( err::FOCA0002, aErrorInfo );
-    return NULL;
+    return false;
   }
 }
 
@@ -792,7 +792,7 @@ T1_TO_T2(dbl, dec)
   catch ( std::exception const& ) 
   {
     throwTypeException(err::FOCA0002, aErrorInfo);
-    return NULL;
+    return false;
   }
 }
 
@@ -806,7 +806,7 @@ T1_TO_T2(dbl, int)
   catch ( std::exception const& ) 
   {
     throwTypeException( err::FOCA0002, aErrorInfo );
-    return NULL;
+    return false;
   }
 }
 
@@ -1409,7 +1409,7 @@ T1_TO_T2(flt, uint)
   catch ( std::exception const& ) 
   {
     throwTypeException( err::FOCA0002, aErrorInfo );
-    return NULL;
+    return false;
   }
 }
 
@@ -1424,7 +1424,7 @@ T1_TO_T2(int, uint)
   catch ( std::exception const& ) 
   {
     throwTypeException( err::FOCA0002, aErrorInfo );
-    return NULL;
+    return false;
   }
 }
 
@@ -1439,7 +1439,7 @@ T1_TO_T2(uint, int)
   catch ( std::exception const& ) 
   {
     throwTypeException( err::FOCA0002, aErrorInfo );
-    return NULL;
+    return false;
   }
 }
 
@@ -1454,7 +1454,7 @@ T1_TO_T2(dbl, uint)
   catch ( std::exception const& ) 
   {
     throwTypeException( err::FOCA0002, aErrorInfo );
-    return NULL;
+    return false;
   }
 }
 
@@ -1491,7 +1491,7 @@ T1_TO_T2(str, uint)
   catch ( std::range_error const& ) {
     throwTypeException( err::FOCA0002, aErrorInfo );
   }
-  return NULL;
+  return false;
 }
 
 T1_TO_T2(NUL, str)
@@ -1588,7 +1588,7 @@ bool str_down(
   }
 
   throwTypeException( err::FORG0001, aErrorInfo );
-  return NULL;
+  return false;
 }
 
 
@@ -1763,7 +1763,7 @@ bool int_down(
   }
 
   throwTypeException( err::FORG0001, aErrorInfo );
-  return NULL;
+  return false;
 }
 
 
