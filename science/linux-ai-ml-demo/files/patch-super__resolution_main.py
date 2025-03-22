--- super_resolution/main.py.orig	2025-02-09 16:56:58 UTC
+++ super_resolution/main.py
@@ -8,6 +8,7 @@ from data import get_training_set, get_test_set
 from torch.utils.data import DataLoader
 from model import Net
 from data import get_training_set, get_test_set
+from os.path import join, expanduser
 
 # Training settings
 parser = argparse.ArgumentParser(description='PyTorch Super Res Example')
@@ -82,7 +83,7 @@ def checkpoint(epoch):
 
 
 def checkpoint(epoch):
-    model_out_path = "model_epoch_{}.pth".format(epoch)
+    model_out_path = join(expanduser("~/pytorch-examples-temp/super_resolution"), "model_epoch_{}.pth".format(epoch))
     torch.save(model, model_out_path)
     print("Checkpoint saved to {}".format(model_out_path))
 
