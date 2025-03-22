--- mnist/main.py.orig	2025-02-09 16:56:58 UTC
+++ mnist/main.py
@@ -5,6 +5,7 @@ from torch.optim.lr_scheduler import StepLR
 import torch.optim as optim
 from torchvision import datasets, transforms
 from torch.optim.lr_scheduler import StepLR
+import os
 
 
 class Net(nn.Module):
@@ -120,9 +121,10 @@ def main():
         transforms.ToTensor(),
         transforms.Normalize((0.1307,), (0.3081,))
         ])
-    dataset1 = datasets.MNIST('../data', train=True, download=True,
+    data_dir = os.path.expanduser("~/pytorch-examples-temp/mnist/data")
+    dataset1 = datasets.MNIST(data_dir, train=True, download=True,
                        transform=transform)
-    dataset2 = datasets.MNIST('../data', train=False,
+    dataset2 = datasets.MNIST(data_dir, train=False,
                        transform=transform)
     train_loader = torch.utils.data.DataLoader(dataset1,**train_kwargs)
     test_loader = torch.utils.data.DataLoader(dataset2, **test_kwargs)
