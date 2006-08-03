--- filetype.bak.c	Sat May 13 22:51:32 2006
+++ filetype.c	Thu Aug  3 09:23:35 2006
@@ -66,8 +66,9 @@
                                                     }
 
 #define CHECK_SIZE(db,array,type,size)   if(db->array##_num >= db->array##_size){\
-	                                           if((newdata=realloc(db->array,db->array##_size+size*sizeof(type)))==NULL)\
+	                                           if((newdata=realloc(db->array,(db->array##_size+size)*sizeof(type)))==NULL)\
 	                                                     return -1;\
+                                                    db->array##_size +=size; \
 	                                            db->array =newdata;\
                                         }
 
@@ -80,7 +81,7 @@
      struct ci_data_type *newdata;
      int indx,i;
 
-     CHECK_SIZE(db,types,struct ci_data_type,50);
+     CHECK_SIZE(db,types,struct ci_data_type,50)
      
      indx=db->types_num;
      db->types_num++;
@@ -113,7 +114,7 @@
      int indx;
 
      CHECK_SIZE(db,magics,struct ci_magic,50)
-
+	  
      indx=db->magics_num;
      db->magics_num++;
 
@@ -308,6 +309,10 @@
 	       }
 	       groups[i]=-1;
 	       type=types_add(db,record.type,record.descr,groups);
+	       if(type<0){
+		    ret=-2;
+		    break;
+	       }
 	  }
 	  
 	  magics_add(db,record.offset,record.magic,record.len,type);
@@ -459,10 +464,13 @@
      int endian=0;
      /*check for utf8 ........*/
      for(i=0;i<buflen;i+=ret){ 
-	  if(!(ret=isUTF8(buf+i,buflen-i)))
+	  if((ret=isUTF8(buf+i,buflen-i)) <= 0)
 	       break;
      }
 
+     if(ret < 0 && i == 0)
+	 ret=0;/*Not enough data to check*/
+
      if(ret) /*Even if the last char is unknown ret!=0 mean is utf*/
 	  return CI_UTF_DATA; /*... but what about if buflen is about 2 or 3 bytes long ?*/
      
@@ -500,7 +508,7 @@
 
      if((ret=check_magics(db,buf,buflen))>=0)
 	  return ret;
-     
+
 /*At the feature the check_ascii and check_unicode must be merged ....*/
      if((ret=check_ascii((unsigned char *)buf,buflen))>0)
 	  return ret;
@@ -508,7 +516,7 @@
      if((ret=check_unicode((unsigned char *)buf,buflen))>0){
 	  return CI_UTF_DATA;
      }
-     
+
      return CI_BIN_DATA; /*binary data*/
 }
 
