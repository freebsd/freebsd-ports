--- mnist_hogwild/main.py.orig	2025-02-09 16:56:58 UTC
+++ mnist_hogwild/main.py
@@ -6,6 +6,7 @@ from torchvision import datasets, transforms
 import torch.multiprocessing as mp
 from torch.utils.data.sampler import Sampler
 from torchvision import datasets, transforms
+import os
 
 from train import train, test
 
@@ -71,9 +72,10 @@ if __name__ == '__main__':
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
     kwargs = {'batch_size': args.batch_size,
               'shuffle': True}
