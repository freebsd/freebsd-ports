--- SoObjects/Mailer/SOGoMailBodyPart.m.orig	2015-09-16 18:41:30 UTC
+++ SoObjects/Mailer/SOGoMailBodyPart.m
@@ -396,7 +396,7 @@ static BOOL debugOn = NO;
 	    mimeType = @"application/octet-stream";
 	  
 	  [response setHeader: mimeType forKey: @"content-type"];
-	  [response setHeader: [NSString stringWithFormat:@"%d", [data length]]
+	  [response setHeader: [NSString stringWithFormat:@"%d", (int)[data length]]
 		    forKey: @"content-length"];
   
 	  if (asAttachment)
