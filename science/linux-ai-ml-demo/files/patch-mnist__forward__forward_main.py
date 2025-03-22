--- mnist_forward_forward/main.py.orig	2025-02-09 16:56:58 UTC
+++ mnist_forward_forward/main.py
@@ -9,6 +9,7 @@ from torch.optim import Adam
 from torchvision.transforms import Compose, ToTensor, Normalize, Lambda
 from torch.utils.data import DataLoader
 from torch.optim import Adam
+import os
 
 
 def get_y_neg(y):
@@ -161,11 +162,12 @@ if __name__ == "__main__":
             Lambda(lambda x: torch.flatten(x)),
         ]
     )
+    data_dir = os.path.expanduser("~/pytorch-examples-temp/mnist/data")
     train_loader = DataLoader(
-        MNIST("./data/", train=True, download=True, transform=transform), **train_kwargs
+        MNIST(data_dir, train=True, download=True, transform=transform), **train_kwargs
     )
     test_loader = DataLoader(
-        MNIST("./data/", train=False, download=True, transform=transform), **test_kwargs
+        MNIST(data_dir, train=False, download=True, transform=transform), **test_kwargs
     )
     net = Net([784, 500, 500])
     x, y = next(iter(train_loader))
