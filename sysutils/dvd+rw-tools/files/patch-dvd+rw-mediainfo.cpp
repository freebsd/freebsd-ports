error: invalid suffix on literal; C++11 requires a space between literal and identifier
    [-Wreserved-user-defined-literal]
                printf("%"LLU"\n",(unsigned long long)capacity*blocksize);

--- dvd+rw-mediainfo.cpp.orig	2018-01-17 11:02:12 UTC
+++ dvd+rw-mediainfo.cpp
@@ -621,7 +621,7 @@ legacy:
 	if (phys_end>0)	phys_end -= phys_start;
 	if (phys_end>0) phys_end += 1;
 
-	printf (" %s    %u*2KB=%"LLU"\n",
+	printf (" %s    %u*2KB=%" LLU "\n",
 		dvd_dash>=0?"Legacy lead-out at:":"Last border-out at:",
 		phys_end,phys_end*2048LL);
 
@@ -941,14 +941,14 @@ legacy:
 	    printf(" %s:\t\t%u*%u=",type[formats[8]&3],
 	        capacity=formats[4]<<24|formats[5]<<16|formats[6]<<8|formats[7],
 		blocksize);
-	    printf("%"LLU"\n",(unsigned long long)capacity*blocksize);
+	    printf("%" LLU "\n",(unsigned long long)capacity*blocksize);
 
 	    for(i=12;i<len;i+=8)
 	    {	printf(" %02Xh(%x):\t\t%u*%u=",formats[i+4]>>2,
 			formats[i+5]<<16|formats[i+6]<<8|formats[i+7],
 	    		capacity=formats[i]<<24|formats[i+1]<<16|formats[i+2]<<8|formats[i+3],
 			blocksize);
-		printf("%"LLU"\n",(unsigned long long)capacity*blocksize);
+		printf("%" LLU "\n",(unsigned long long)capacity*blocksize);
 	    }
 	    break;
 	}
@@ -1121,7 +1121,7 @@ legacy:
 	if (ccity) ccity++;
 	bsize = header[4]<<24|header[5]<<16|header[6]<<8|header[7];
 
-	printf ("READ CAPACITY:          %u*%u=%"LLU"\n",
+	printf ("READ CAPACITY:          %u*%u=%" LLU "\n",
 					ccity,bsize,
 					(unsigned long long)ccity*bsize);
     } while (0);
