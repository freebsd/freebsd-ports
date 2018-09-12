--- Mixing_H.c.orig	2018-08-29 05:53:55 UTC
+++ Mixing_H.c
@@ -74,7 +74,7 @@ void Pulay_Mixing_H_MultiSecant(int MD_i
   double sum,my_sum,tmp1,tmp2,alpha;
   double r,r10,r11,r12,r13,r20,r21,r22;
   double h,h10,h11,h12,h13,h20,h21,h22;
-  double my_sy,my_yy,sy,yy,norm,s,y,or,al,be;
+  double my_sy,my_yy,sy,yy,norm,s,y,orx,al,be;
   double **A,**IA,*coes,*coes2,*ror;
   char nanchar[300];
 
@@ -635,44 +635,44 @@ void Pulay_Mixing_H_MultiSecant(int MD_i
 	      s = HisH1[m][0][Mc_AN][h_AN][i][j] - HisH1[m+1][0][Mc_AN][h_AN][i][j];           /* s */
 	      y = ResidualH1[m][0][Mc_AN][h_AN][i][j] - ResidualH1[m+1][0][Mc_AN][h_AN][i][j]; /* y */
 	      r = s - al*y;                                                                    /* r */
-              or = ResidualH1[dim+1][0][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
-	      my_sum += r*or; 
+              orx = ResidualH1[dim+1][0][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
+	      my_sum += r*orx; 
 
 	      s = HisH1[m][1][Mc_AN][h_AN][i][j] - HisH1[m+1][1][Mc_AN][h_AN][i][j];           /* s */
 	      y = ResidualH1[m][1][Mc_AN][h_AN][i][j] - ResidualH1[m+1][1][Mc_AN][h_AN][i][j]; /* y */
 	      r = s - al*y;                                                                    /* r */
-              or = ResidualH1[dim+1][1][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
-	      my_sum += r*or; 
+              orx = ResidualH1[dim+1][1][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
+	      my_sum += r*orx; 
 
 	      s = HisH1[m][2][Mc_AN][h_AN][i][j] - HisH1[m+1][2][Mc_AN][h_AN][i][j];           /* s */
 	      y = ResidualH1[m][2][Mc_AN][h_AN][i][j] - ResidualH1[m+1][2][Mc_AN][h_AN][i][j]; /* y */
 	      r = s - al*y;                                                                    /* r */
-              or = ResidualH1[dim+1][2][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
-	      my_sum += r*or; 
+              orx = ResidualH1[dim+1][2][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
+	      my_sum += r*orx; 
 
 	      s = HisH1[m][3][Mc_AN][h_AN][i][j] - HisH1[m+1][3][Mc_AN][h_AN][i][j];           /* s */
 	      y = ResidualH1[m][3][Mc_AN][h_AN][i][j] - ResidualH1[m+1][3][Mc_AN][h_AN][i][j]; /* y */
 	      r = s - al*y;                                                                    /* r */
-              or = ResidualH1[dim+1][3][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
-	      my_sum += r*or; 
+              orx = ResidualH1[dim+1][3][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
+	      my_sum += r*orx; 
 
 	      s = HisH2[m][0][Mc_AN][h_AN][i][j] - HisH2[m+1][0][Mc_AN][h_AN][i][j];           /* s */
 	      y = ResidualH2[m][0][Mc_AN][h_AN][i][j] - ResidualH2[m+1][0][Mc_AN][h_AN][i][j]; /* y */
 	      r = s - al*y;                                                                    /* r */
-              or = ResidualH2[dim+1][0][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
-	      my_sum += r*or; 
+              orx = ResidualH2[dim+1][0][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
+	      my_sum += r*orx; 
 
 	      s = HisH2[m][1][Mc_AN][h_AN][i][j] - HisH2[m+1][1][Mc_AN][h_AN][i][j];           /* s */
 	      y = ResidualH2[m][1][Mc_AN][h_AN][i][j] - ResidualH2[m+1][1][Mc_AN][h_AN][i][j]; /* y */
 	      r = s - al*y;                                                                    /* r */
-              or = ResidualH2[dim+1][1][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
-	      my_sum += r*or; 
+              orx = ResidualH2[dim+1][1][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
+	      my_sum += r*orx; 
 
 	      s = HisH2[m][2][Mc_AN][h_AN][i][j] - HisH2[m+1][2][Mc_AN][h_AN][i][j];           /* s */
 	      y = ResidualH2[m][2][Mc_AN][h_AN][i][j] - ResidualH2[m+1][2][Mc_AN][h_AN][i][j]; /* y */
 	      r = s - al*y;                                                                    /* r */
-              or = ResidualH2[dim+1][2][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
-	      my_sum += r*or; 
+              orx = ResidualH2[dim+1][2][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
+	      my_sum += r*orx; 
 
 	    }
 	  }
@@ -696,8 +696,8 @@ void Pulay_Mixing_H_MultiSecant(int MD_i
 		s = HisH1[m][spin][Mc_AN][h_AN][i][j] - HisH1[m+1][spin][Mc_AN][h_AN][i][j];           
 		y = ResidualH1[m][spin][Mc_AN][h_AN][i][j] - ResidualH1[m+1][spin][Mc_AN][h_AN][i][j]; 
 		r = s - al*y;                                                                          
-		or = ResidualH1[dim+1][spin][Mc_AN][h_AN][i][j];                                   
-		my_sum += r*or; 
+		orx = ResidualH1[dim+1][spin][Mc_AN][h_AN][i][j];                                   
+		my_sum += r*orx; 
 	      }
 	    }
 	  }
@@ -986,7 +986,7 @@ void Pulay_Mixing_H_with_One_Shot_Hessia
   double my_sum,tmp1,tmp2,alpha;
   double r,r10,r11,r12,r13,r20,r21,r22;
   double h,h10,h11,h12,h13,h20,h21,h22;
-  double my_sy,my_yy,sy,yy,norm,s,y,or,al,be;
+  double my_sy,my_yy,sy,yy,norm,s,y,orx,al,be;
   double **A,**IA,*coes;
   char nanchar[300];
 
@@ -1427,38 +1427,38 @@ void Pulay_Mixing_H_with_One_Shot_Hessia
 
 	    s = HisH1[0][0][Mc_AN][h_AN][i][j] - HisH1[1][0][Mc_AN][h_AN][i][j];           /* s */
 	    y = ResidualH1[0][0][Mc_AN][h_AN][i][j] - ResidualH1[1][0][Mc_AN][h_AN][i][j]; /* y */
-            or = ResidualH1[dim][0][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
-	    my_sum += (s-al*y)*or;
+            orx = ResidualH1[dim][0][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
+	    my_sum += (s-al*y)*orx;
 
 	    s = HisH1[0][1][Mc_AN][h_AN][i][j] - HisH1[1][1][Mc_AN][h_AN][i][j];           /* s */
 	    y = ResidualH1[0][1][Mc_AN][h_AN][i][j] - ResidualH1[1][1][Mc_AN][h_AN][i][j]; /* y */
-            or = ResidualH1[dim][1][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
-	    my_sum += (s-al*y)*or;
+            orx = ResidualH1[dim][1][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
+	    my_sum += (s-al*y)*orx;
 
 	    s = HisH1[0][2][Mc_AN][h_AN][i][j] - HisH1[1][2][Mc_AN][h_AN][i][j];           /* s */
 	    y = ResidualH1[0][2][Mc_AN][h_AN][i][j] - ResidualH1[1][2][Mc_AN][h_AN][i][j]; /* y */
-            or = ResidualH1[dim][2][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
-	    my_sum += (s-al*y)*or;
+            orx = ResidualH1[dim][2][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
+	    my_sum += (s-al*y)*orx;
 
 	    s = HisH1[0][3][Mc_AN][h_AN][i][j] - HisH1[1][3][Mc_AN][h_AN][i][j];           /* s */
 	    y = ResidualH1[0][3][Mc_AN][h_AN][i][j] - ResidualH1[1][3][Mc_AN][h_AN][i][j]; /* y */
-            or = ResidualH1[dim][3][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
-	    my_sum += (s-al*y)*or;
+            orx = ResidualH1[dim][3][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
+	    my_sum += (s-al*y)*orx;
 
 	    s = HisH2[0][0][Mc_AN][h_AN][i][j] - HisH2[1][0][Mc_AN][h_AN][i][j];           /* s */
 	    y = ResidualH2[0][0][Mc_AN][h_AN][i][j] - ResidualH2[1][0][Mc_AN][h_AN][i][j]; /* y */
-            or = ResidualH2[dim][0][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
-	    my_sum += (s-al*y)*or;
+            orx = ResidualH2[dim][0][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
+	    my_sum += (s-al*y)*orx;
 
 	    s = HisH2[0][1][Mc_AN][h_AN][i][j] - HisH2[1][1][Mc_AN][h_AN][i][j];           /* s */
 	    y = ResidualH2[0][1][Mc_AN][h_AN][i][j] - ResidualH2[1][1][Mc_AN][h_AN][i][j]; /* y */
-            or = ResidualH2[dim][1][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
-	    my_sum += (s-al*y)*or;
+            orx = ResidualH2[dim][1][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
+	    my_sum += (s-al*y)*orx;
 
 	    s = HisH2[0][2][Mc_AN][h_AN][i][j] - HisH2[1][2][Mc_AN][h_AN][i][j];           /* s */
 	    y = ResidualH2[0][2][Mc_AN][h_AN][i][j] - ResidualH2[1][2][Mc_AN][h_AN][i][j]; /* y */
-            or = ResidualH2[dim][2][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
-	    my_sum += (s-al*y)*or;
+            orx = ResidualH2[dim][2][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
+	    my_sum += (s-al*y)*orx;
 	  }
 	}
       }
@@ -1479,8 +1479,8 @@ void Pulay_Mixing_H_with_One_Shot_Hessia
 	    for (j=0; j<Spe_Total_NO[Hwan]; j++){
 	      s = HisH1[0][spin][Mc_AN][h_AN][i][j] - HisH1[1][spin][Mc_AN][h_AN][i][j];           /* s */
 	      y = ResidualH1[0][spin][Mc_AN][h_AN][i][j] - ResidualH1[1][spin][Mc_AN][h_AN][i][j]; /* y */
-	      or = ResidualH1[dim][spin][Mc_AN][h_AN][i][j];                                       /* OptResidualH */
-	      my_sum += (s-al*y)*or;
+	      orx = ResidualH1[dim][spin][Mc_AN][h_AN][i][j];                                       /* OptResidualH */
+	      my_sum += (s-al*y)*orx;
 	    }
 	  }
 	}
@@ -1541,38 +1541,38 @@ void Pulay_Mixing_H_with_One_Shot_Hessia
 
 	    s = HisH1[0][0][Mc_AN][h_AN][i][j] - HisH1[1][0][Mc_AN][h_AN][i][j];           /* s */
 	    y = ResidualH1[0][0][Mc_AN][h_AN][i][j] - ResidualH1[1][0][Mc_AN][h_AN][i][j]; /* y */
-            or = ResidualH1[dim][0][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
-	    H[0][Mc_AN][h_AN][i][j] = h10 - alpha*(al*or + (s-al*y)*be);
+            orx = ResidualH1[dim][0][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
+	    H[0][Mc_AN][h_AN][i][j] = h10 - alpha*(al*orx + (s-al*y)*be);
 
 	    s = HisH1[0][1][Mc_AN][h_AN][i][j] - HisH1[1][1][Mc_AN][h_AN][i][j];           /* s */
 	    y = ResidualH1[0][1][Mc_AN][h_AN][i][j] - ResidualH1[1][1][Mc_AN][h_AN][i][j]; /* y */
-            or = ResidualH1[dim][1][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
-	    H[1][Mc_AN][h_AN][i][j] = h11 - alpha*(al*or + (s-al*y)*be);
+            orx = ResidualH1[dim][1][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
+	    H[1][Mc_AN][h_AN][i][j] = h11 - alpha*(al*orx + (s-al*y)*be);
 
 	    s = HisH1[0][2][Mc_AN][h_AN][i][j] - HisH1[1][2][Mc_AN][h_AN][i][j];           /* s */
 	    y = ResidualH1[0][2][Mc_AN][h_AN][i][j] - ResidualH1[1][2][Mc_AN][h_AN][i][j]; /* y */
-            or = ResidualH1[dim][2][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
-	    H[2][Mc_AN][h_AN][i][j] = h12 - alpha*(al*or + (s-al*y)*be);
+            orx = ResidualH1[dim][2][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
+	    H[2][Mc_AN][h_AN][i][j] = h12 - alpha*(al*orx + (s-al*y)*be);
 
 	    s = HisH1[0][3][Mc_AN][h_AN][i][j] - HisH1[1][3][Mc_AN][h_AN][i][j];           /* s */
 	    y = ResidualH1[0][3][Mc_AN][h_AN][i][j] - ResidualH1[1][3][Mc_AN][h_AN][i][j]; /* y */
-            or = ResidualH1[dim][3][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
-	    H[3][Mc_AN][h_AN][i][j] = h13 - alpha*(al*or + (s-al*y)*be);
+            orx = ResidualH1[dim][3][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
+	    H[3][Mc_AN][h_AN][i][j] = h13 - alpha*(al*orx + (s-al*y)*be);
 
 	    s = HisH2[0][0][Mc_AN][h_AN][i][j] - HisH2[1][0][Mc_AN][h_AN][i][j];           /* s */
 	    y = ResidualH2[0][0][Mc_AN][h_AN][i][j] - ResidualH2[1][0][Mc_AN][h_AN][i][j]; /* y */
-            or = ResidualH2[dim][0][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
-	    iHNL[0][Mc_AN][h_AN][i][j] = h20 - alpha*(al*or + (s-al*y)*be);
+            orx = ResidualH2[dim][0][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
+	    iHNL[0][Mc_AN][h_AN][i][j] = h20 - alpha*(al*orx + (s-al*y)*be);
 
 	    s = HisH2[0][1][Mc_AN][h_AN][i][j] - HisH2[1][1][Mc_AN][h_AN][i][j];           /* s */
 	    y = ResidualH2[0][1][Mc_AN][h_AN][i][j] - ResidualH2[1][1][Mc_AN][h_AN][i][j]; /* y */
-            or = ResidualH2[dim][1][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
-	    iHNL[1][Mc_AN][h_AN][i][j] = h21 - alpha*(al*or + (s-al*y)*be);
+            orx = ResidualH2[dim][1][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
+	    iHNL[1][Mc_AN][h_AN][i][j] = h21 - alpha*(al*orx + (s-al*y)*be);
 
 	    s = HisH2[0][2][Mc_AN][h_AN][i][j] - HisH2[1][2][Mc_AN][h_AN][i][j];           /* s */
 	    y = ResidualH2[0][2][Mc_AN][h_AN][i][j] - ResidualH2[1][2][Mc_AN][h_AN][i][j]; /* y */
-            or = ResidualH2[dim][2][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
-	    iHNL[2][Mc_AN][h_AN][i][j] = h22 - alpha*(al*or + (s-al*y)*be);
+            orx = ResidualH2[dim][2][Mc_AN][h_AN][i][j];                                    /* OptResidualH */
+	    iHNL[2][Mc_AN][h_AN][i][j] = h22 - alpha*(al*orx + (s-al*y)*be);
 	  }
 	}
       }
@@ -1599,8 +1599,8 @@ void Pulay_Mixing_H_with_One_Shot_Hessia
 
 	      s = HisH1[0][spin][Mc_AN][h_AN][i][j] - HisH1[1][spin][Mc_AN][h_AN][i][j];           /* s */
 	      y = ResidualH1[0][spin][Mc_AN][h_AN][i][j] - ResidualH1[1][spin][Mc_AN][h_AN][i][j]; /* y */
-              or = ResidualH1[dim][spin][Mc_AN][h_AN][i][j];                                       /* OptResidualH */
-	      H[spin][Mc_AN][h_AN][i][j] = h - alpha*(al*or + (s-al*y)*be);
+              orx = ResidualH1[dim][spin][Mc_AN][h_AN][i][j];                                       /* OptResidualH */
+	      H[spin][Mc_AN][h_AN][i][j] = h - alpha*(al*orx + (s-al*y)*be);
 
 	    }
 	  }
