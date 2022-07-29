--- samples/source/common/DumpFile.cpp.orig	2022-06-25 21:43:18 UTC
+++ samples/source/common/DumpFile.cpp
@@ -2476,7 +2476,7 @@ DumpISOBoxes(LFA_FileRef file, XMP_Uns32 maxBoxLen, st
 					DumpTIFF(tiffContent, tiffLength, offset, "HEIF Exif", "HEIF:Exif");
 					LFA_Seek(file, keep, SEEK_SET, &ok);
 					assertMsg("seek failed", ok);
-					exif_item_id = NULL;
+					exif_item_id = 0;
 				}
 			}
 			//Get the data for xmp - using value from mime_item_id
@@ -2494,7 +2494,7 @@ DumpISOBoxes(LFA_FileRef file, XMP_Uns32 maxBoxLen, st
 					DumpXMP(xmpContent, xmpLength, offset, "XMP");
 					LFA_Seek(file, keep, SEEK_SET, &ok);
 					assertMsg("seek failed", ok);
-					mime_item_id = NULL;
+					mime_item_id = 0;
 				}
 			}
 			break;
@@ -2646,7 +2646,7 @@ DumpISOBoxes(LFA_FileRef file, XMP_Uns32 maxBoxLen, st
 					DumpTIFF(tiffContent, tiffLength, offset, "HEIF Exif", "HEIF:Exif");
 					LFA_Seek(file, keep, SEEK_SET, &ok);
 					assertMsg("seek failed", ok);
-					exif_item_id = NULL;
+					exif_item_id = 0;
 				}
 			}
 			//Get the data for xmp - using value from mime_item_id
@@ -2664,7 +2664,7 @@ DumpISOBoxes(LFA_FileRef file, XMP_Uns32 maxBoxLen, st
 					DumpXMP(xmpContent, xmpLength, offset, "XMP");
 					LFA_Seek(file, keep, SEEK_SET, &ok);
 					assertMsg("seek failed", ok);
-					mime_item_id = NULL;
+					mime_item_id = 0;
 				}
 			}
 
