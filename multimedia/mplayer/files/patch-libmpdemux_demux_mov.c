--- libmpdemux/demux_mov.c.orig	Thu Mar 31 00:10:07 2005
+++ libmpdemux/demux_mov.c	Mon Jan  9 17:09:03 2006
@@ -865,6 +865,7 @@
 		   // ([int32_t size,int32_t type,some data ],repeat)
 		} my_stdata;		  
 #endif		
+		int version, adjust;
 		sh_audio_t* sh=new_sh_audio(demuxer,priv->track_db);
 		sh->format=trak->fourcc;
 
@@ -911,8 +912,27 @@
 //      32  char[4]	atom type (fourc charater code -> esds)		
 //      36  char[]  	atom data (len=size-8)
 
+		version=char2short(trak->stdata,8);
+		if (version > 1)
+		  mp_msg(MSGT_DEMUX, MSGL_WARN, "MOV: version %d sound atom may not parse correctly!\n", version);
 		trak->samplebytes=sh->samplesize=char2short(trak->stdata,18)/8;
-		trak->nchannels=sh->channels=char2short(trak->stdata,16);
+
+		/* I can't find documentation, but so far this is the case. -Corey */
+		switch (char2short(trak->stdata,16)) {
+		  case 1:
+		    trak->nchannels = 1; break;
+		  case 2:
+		    trak->nchannels = 2; break;
+		  case 3:
+		    trak->nchannels = 6; break;
+		  default:
+		    mp_msg(MSGT_DEMUX, MSGL_WARN,
+			"MOV: unable to determine audio channels, assuming 2 (got %d)\n",
+			char2short(trak->stdata,16));
+		    trak->nchannels = 2;
+		}
+		sh->channels = trak->nchannels;
+
 		/*printf("MOV: timescale: %d samplerate: %d durmap: %d (%d) -> %d (%d)\n",
 		    trak->timescale, char2short(trak->stdata,24), trak->durmap[0].dur,
 		    trak->durmap[0].num, trak->timescale/trak->durmap[0].dur,
@@ -966,8 +986,18 @@
 		  }
 		}
 
-		if((trak->stdata[9]==0 || trak->stdata[9]==1) && trak->stdata_len >= 36) { // version 0 with extra atoms
-        int adjust = (trak->stdata[9]==1)?48:0;
+		switch (version) {
+		  case 0:
+		    adjust =  0; break;
+		  case 1:
+		    adjust = 48; break;
+		  case 2:
+		    adjust = 68; break;
+		  default:
+		    mp_msg(MSGT_DEMUX, MSGL_WARN, "MOV: unknown sound atom version (%d); may not work!\n", version);
+		    adjust = 68;
+		}
+		if (trak->stdata_len >= 36 + adjust) {
 		    int atom_len = char2int(trak->stdata,28+adjust);
 		    switch(char2int(trak->stdata,32+adjust)) { // atom type
 		      case MOV_FOURCC('e','s','d','s'): {
