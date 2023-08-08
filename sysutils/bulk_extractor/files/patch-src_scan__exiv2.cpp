--- src/scan_exiv2.cpp.orig	2023-04-07 18:27:14 UTC
+++ src/scan_exiv2.cpp
@@ -33,6 +33,8 @@
 #pragma GCC diagnostic ignored "-Weffc++"
 #endif
 
+using std::string;
+
 #include <exiv2/image.hpp>
 #include <exiv2/exif.hpp>
 #include <exiv2/error.hpp>
@@ -90,7 +92,7 @@ static string fix_gps(string s)
     std::vector<std::string> parts = split(s,' ');
     if(parts.size()!=3) return s;	// return the original
     double res = rational(parts[0]) + rational(parts[1])/60.0 + rational(parts[2])/3600.0;
-    s = dtos(res);
+    s = std::to_string(res);
     return s;
 }
 
@@ -106,7 +108,7 @@ void scan_exiv2(struct scanner_params &sp)
 {
     sp.check_version();
     if(sp.phase==scanner_params::PHASE_INIT){
-        sp.info.set_name("exiv2" );
+        sp.info->set_name("exiv2" );
         sp.info->author         = "Simson L. Garfinkel";
         sp.info->description    = "Searches for EXIF information using exiv2. Use exif scanner if this is not available or if this crashes.";
         sp.info->scanner_flags.default_enabled = false;
@@ -117,7 +119,7 @@ void scan_exiv2(struct scanner_params &sp)
     }
     if(sp.phase==scanner_params::PHASE_SCAN){
 
-	const sbuf_t &sbuf = sp.sbuf;
+	const sbuf_t *sbuf = sp.sbuf;
 	feature_recorder &exif_recorder = sp.named_feature_recorder("exif");
 	feature_recorder &gps_recorder  = sp.named_feature_recorder("gps");
 
@@ -127,23 +129,23 @@ void scan_exiv2(struct scanner_params &sp)
 #endif
 
 	size_t pos_max = 1;		// by default, just scan 1 byte
-	if(sbuf.bufsize > min_exif_size){
-	    pos_max = sbuf.bufsize - min_exif_size; //  we can scan more!
+	if(sbuf->bufsize > min_exif_size){
+	    pos_max = sbuf->bufsize - min_exif_size; //  we can scan more!
 	}
 
 	/* Loop through all possible locations in the buffer */
 	for(size_t pos=0;pos<pos_max;pos++){
 	    size_t count = exif_gulp_size;
-	    count = min(count,sbuf.bufsize-pos);
-	    //size_t count = sbuf.bufsize-pos; // use all to end
+	    count = min(count,sbuf->bufsize-pos);
+	    //size_t count = sbuf->bufsize-pos; // use all to end
 
 	    /* Explore the beginning of each 512-byte block as well as the starting location
 	     * of any JPEG on any boundary. This will cause processing of any multimedia file
 	     * that Exiv2 recognizes (for which I do not know all the headers.
 	     */
-	    if(pos%512==0 || jpeg_start(sbuf+pos)){
+	    if(pos%512==0 || jpeg_start(sbuf->slice(pos))){
 		try {
-		    Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(sbuf.buf+pos,count);
+		    Exiv2::Image::UniquePtr image = Exiv2::ImageFactory::open(sbuf->slice(pos).get_buf(),count);
 		    if(image->good()){
 			image->readMetadata();
 
@@ -153,8 +155,8 @@ void scan_exiv2(struct scanner_params &sp)
 			/*
 			 * Create the MD5 of the first 4K to use as a unique identifier.
 			 */
-			sbuf_t tohash(sbuf,0,4096);
-			string md5_hex = exif_recorder->fs.hasher.func(tohash.buf,tohash.bufsize);
+			sbuf_t tohash(*sbuf,0,4096);
+			string md5_hex = exif_recorder.hash(tohash.slice(0, tohash.bufsize));
 
 			char xmlbuf[1024];
 			snprintf(xmlbuf,sizeof(xmlbuf),
@@ -250,10 +252,10 @@ void scan_exiv2(struct scanner_params &sp)
 				gps_lat = fix_gps(i->value().toString());
 			    } else if(key=="Exif.GPSInfo.GPSAltitude"){
                                 has_gps = true;
-				gps_ele   = dtos(rational(i->value().toString()));
+				gps_ele   = std::to_string(rational(i->value().toString()));
 			    } else if(key=="Exif.GPSInfo.GPSSpeed"){
                                 has_gps = true;
-				gps_speed = dtos(rational(i->value().toString()));
+				gps_speed = std::to_string(rational(i->value().toString()));
 			    } else if(key=="Exif.GPSInfo.GPSTrack"){
                                 has_gps = true;
 				gps_course = i->value().toString();
@@ -262,20 +264,20 @@ void scan_exiv2(struct scanner_params &sp)
 			xml.append("</exiv2>");
 
                         // record EXIF
-			exif_recorder->write(sp.sbuf.pos0+pos,md5_hex,xml);
+			exif_recorder.write(sp.sbuf->pos0+pos,md5_hex,xml);
 
                         // record GPS
                         if (has_gps) {
                             if (has_gps_date) {
                                 // record the GPS entry using the GPS date
-                                gps_recorder->write(sp.sbuf.pos0+pos,md5_hex,
+                                gps_recorder.write(sp.sbuf->pos0+pos,md5_hex,
 					    gps_date+"T"+gps_time+","+gps_lat_ref+gps_lat+","
 					    +gps_lon_ref+gps_lon+","
 					    +gps_ele+","+gps_speed+","+gps_course);
 
                             } else {
                                 // record the GPS entry using the date obtained from Photo
-                                gps_recorder->write(sp.sbuf.pos0+pos,md5_hex,
+                                gps_recorder.write(sp.sbuf->pos0+pos,md5_hex,
 					    photo_time+","+gps_lat_ref+gps_lat+","
 					    +gps_lon_ref+gps_lon+","
 					    +gps_ele+","+gps_speed+","+gps_course);
@@ -283,7 +285,7 @@ void scan_exiv2(struct scanner_params &sp)
 			}
 		    }
 		}
-		catch (Exiv2::AnyError &e) { }
+		catch (Exiv2::Error &e) { }
 		catch (std::exception &e) { }
 	    }
 	}
