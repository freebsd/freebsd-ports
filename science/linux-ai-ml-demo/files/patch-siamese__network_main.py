--- siamese_network/main.py.orig	2025-02-09 16:56:58 UTC
+++ siamese_network/main.py
@@ -11,6 +11,7 @@ from torch.optim.lr_scheduler import StepLR
 from torchvision import datasets
 from torchvision import transforms as T
 from torch.optim.lr_scheduler import StepLR
+import os
 
 
 class SiameseNetwork(nn.Module):
@@ -282,8 +283,9 @@ def main():
         train_kwargs.update(cuda_kwargs)
         test_kwargs.update(cuda_kwargs)
 
-    train_dataset = APP_MATCHER('../data', train=True, download=True)
-    test_dataset = APP_MATCHER('../data', train=False)
+    data_dir = os.path.expanduser("~/pytorch-examples-temp/mnist/data")
+    train_dataset = APP_MATCHER(data_dir, train=True, download=True)
+    test_dataset = APP_MATCHER(data_dir, train=False)
     train_loader = torch.utils.data.DataLoader(train_dataset,**train_kwargs)
     test_loader = torch.utils.data.DataLoader(test_dataset, **test_kwargs)
 
