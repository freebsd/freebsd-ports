--- src/settingsdlg.cpp	Mon Jul 18 21:54:08 2005
+++ src/settingsdlg.cpp	Sun Sep 18 21:21:08 2005
@@ -400,7 +400,7 @@
 		settings->setSoundType(static_cast<Sound::SoundType>(opt_snddev->id(opt_snddev->selected())));
 		sndcfgchanged = true;
 	}
-	settings->setEncodingName(l_enc->currentItem() ? l_enc->currentText() : "");
+	settings->setEncodingName(l_enc->currentItem() ? l_enc->currentText() : QString(""));
 	if (b_useutf->isChecked() != settings->getUseUTF())
 		settings->setUseUTF(b_useutf->isChecked());
 	settings->setHideChannels(b_hide->isChecked());
