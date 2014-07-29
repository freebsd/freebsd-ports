*** src/graph.c.org	Wed Jan 31 15:15:27 2001
--- src/graph.c	Wed Jan 31 15:22:39 2001
***************
*** 66,71 ****
--- 66,95 ----
    fprintf(f,"  fill\n");
    fprintf(f,"  } def\n");
  
+   fprintf(f,"/REDBOX\n");
+   fprintf(f,"  {\n");
+   fprintf(f,"  /y2 exch def /y1 exch def /x2 exch def /x1 exch def\n");
+   fprintf(f,"  x1 y1 moveto\n");
+   fprintf(f,"  x2 y1 lineto\n");
+   fprintf(f,"  x2 y2 lineto\n");
+   fprintf(f,"  x1 y2 lineto\n");
+   fprintf(f,"  closepath\n");
+   fprintf(f,"  1 %f %f setrgbcolor\n",tg_gray,tg_gray);
+   fprintf(f,"  fill\n");
+   fprintf(f,"  } def\n");
+ 
+   fprintf(f,"/BLUEBOX\n");
+   fprintf(f,"  {\n");
+   fprintf(f,"  /y2 exch def /y1 exch def /x2 exch def /x1 exch def\n");
+   fprintf(f,"  x1 y1 moveto\n");
+   fprintf(f,"  x2 y1 lineto\n");
+   fprintf(f,"  x2 y2 lineto\n");
+   fprintf(f,"  x1 y2 lineto\n");
+   fprintf(f,"  closepath\n");
+   fprintf(f,"  %f %f 1 setrgbcolor\n",tg_gray,tg_gray);
+   fprintf(f,"  fill\n");
+   fprintf(f,"  } def\n");
+   
    fprintf(f,"/OUTLINE\n");
    fprintf(f,"  {\n");
    fprintf(f,"  /y2 exch def /y1 exch def /x2 exch def /x1 exch def\n");
***************
*** 267,273 ****
        for( i=tb->start; i<=tb->finish; ++i )
          {
          tb_x1 = MapX( i, start, finish );
!         fprintf(f,"%d %d %d %d BOX\n", tb_x1, tb_x1+tg_width, tb_y1, tb_y2);
          }
        }
  
--- 291,303 ----
        for( i=tb->start; i<=tb->finish; ++i )
          {
          tb_x1 = MapX( i, start, finish );
!         if (t->children > 0)
!           fprintf(f,"%d %d %d %d REDBOX\n",
!                   tb_x1, tb_x1+tg_width, tb_y1, tb_y2);
!         else
!           fprintf(f,"%d %d %d %d BLUEBOX\n",
!                   tb_x1, tb_x1+tg_width, tb_y1, tb_y2);
!         
          }
        }
  
