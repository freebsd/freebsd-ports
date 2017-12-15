--- libmpcodecs/ae_faac.c.orig	2011-07-27 15:33:03 UTC
+++ libmpcodecs/ae_faac.c
@@ -183,7 +183,9 @@ int mpae_init_faac(audio_encoder_t *enco
 	if(MAIN==0) config->aacObjectType--;
 	config->mpegVersion = (param_mpeg == 4 ? MPEG4 : MPEG2);
 	config->useTns = param_tns;
-	config->allowMidside = 1;
+	//Do not set allowMidside for API compatibility with faac,
+	//see https://github.com/knik0/faac/issues/8 for details
+	//config->allowMidside = 1;
 	config->shortctl = SHORTCTL_NORMAL;
 	param_cutoff = param_cutoff ? param_cutoff : encoder->params.sample_rate / 2;
 	if(param_cutoff > encoder->params.sample_rate / 2)
