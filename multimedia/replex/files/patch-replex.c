--- replex.c.orig	2007-06-19 09:30:08 UTC
+++ replex.c
@@ -442,7 +442,7 @@ static int analyze_audio_loop( pes_in_t *p, struct rep
 			}
 
 			if( iu->err!= JUMP_ERR && !rx->keep_pts && diff > 40*CLOCK_MS){
-					if (!rx->allow_jump || abs((int)diff) > rx->allow_jump){
+					if (!rx->allow_jump || labs((int)diff) > rx->allow_jump){
 						fprintf(stderr,"audio PTS inconsistent: ");
 						printpts(dpts);
 						printpts(iu->pts);
@@ -698,7 +698,7 @@ void analyze_video( pes_in_t *p, struct replex *rx, in
 							       + newpts);
 						
 						if (rx->allow_jump &&  
-						    abs(diff) > rx->allow_jump)
+						    labs(diff) > rx->allow_jump)
 						{
 							if (audio_jump(rx)){
 								fprintf(stderr,"AUDIO JUMPED\n");
@@ -716,7 +716,7 @@ void analyze_video( pes_in_t *p, struct replex *rx, in
 						}
 
 						if (!rx->keep_pts &&
-						    abs((int)(diff)) > 3*SEC_PER/2){
+						    labs((int)(diff)) > 3*SEC_PER/2){
 							fprintf(stderr,"video PTS inconsistent: ");
 							printpts(trans_pts_dts(p->pts));
 							printpts(iu->pts);
@@ -735,7 +735,7 @@ void analyze_video( pes_in_t *p, struct replex *rx, in
 							       newdts + 
 							       rx->first_vpts); 
 						if (!rx->keep_pts && !keep_now &&
-						    abs((int)diff) > 3*SEC_PER/2){
+						    labs((int)diff) > 3*SEC_PER/2){
 							fprintf(stderr,"video DTS inconsistent: ");
 							printpts(trans_pts_dts(p->dts));
 							printpts(iu->dts);
