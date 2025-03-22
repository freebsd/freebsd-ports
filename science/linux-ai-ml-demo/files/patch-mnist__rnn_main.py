--- mnist_rnn/main.py.orig	2025-02-09 16:56:58 UTC
+++ mnist_rnn/main.py
@@ -8,6 +8,7 @@ from torchvision import datasets, transforms
 import torch.optim as optim
 from torch.optim.lr_scheduler import StepLR
 from torchvision import datasets, transforms
+import os
 
 
 class Net(nn.Module):
@@ -117,15 +118,16 @@ def main():
     torch.manual_seed(args.seed)
 
     kwargs = {'num_workers': 1, 'pin_memory': True} if args.cuda else {}
+    data_dir = os.path.expanduser("~/pytorch-examples-temp/mnist/data")
     train_loader = torch.utils.data.DataLoader(
-        datasets.MNIST('../data', train=True, download=True,
+        datasets.MNIST(data_dir, train=True, download=True,
                        transform=transforms.Compose([
                            transforms.ToTensor(),
                            transforms.Normalize((0.1307,), (0.3081,))
                        ])),
         batch_size=args.batch_size, shuffle=True, **kwargs)
     test_loader = torch.utils.data.DataLoader(
-        datasets.MNIST('../data', train=False, transform=transforms.Compose([
+        datasets.MNIST(data_dir, train=False, transform=transforms.Compose([
             transforms.ToTensor(),
             transforms.Normalize((0.1307,), (0.3081,))
         ])),
