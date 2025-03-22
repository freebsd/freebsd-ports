--- vae/main.py.orig	2025-03-19 12:19:55 UTC
+++ vae/main.py
@@ -6,6 +6,7 @@ from torchvision.utils import save_image
 from torch.nn import functional as F
 from torchvision import datasets, transforms
 from torchvision.utils import save_image
+import os
 
 
 parser = argparse.ArgumentParser(description='VAE MNIST Example')
@@ -35,12 +36,13 @@ kwargs = {'num_workers': 1, 'pin_memory': True} if arg
     device = torch.device("cpu")
 
 kwargs = {'num_workers': 1, 'pin_memory': True} if args.cuda else {}
+data_dir = os.path.expanduser("~/pytorch-examples-temp/mnist/data")
 train_loader = torch.utils.data.DataLoader(
-    datasets.MNIST('../data', train=True, download=True,
+    datasets.MNIST(data_dir, train=True, download=True,
                    transform=transforms.ToTensor()),
     batch_size=args.batch_size, shuffle=True, **kwargs)
 test_loader = torch.utils.data.DataLoader(
-    datasets.MNIST('../data', train=False, transform=transforms.ToTensor()),
+    datasets.MNIST(data_dir, train=False, transform=transforms.ToTensor()),
     batch_size=args.batch_size, shuffle=False, **kwargs)
 
 
@@ -124,7 +126,7 @@ def test(epoch):
                 comparison = torch.cat([data[:n],
                                       recon_batch.view(args.batch_size, 1, 28, 28)[:n]])
                 save_image(comparison.cpu(),
-                         'results/reconstruction_' + str(epoch) + '.png', nrow=n)
+                         os.path.expanduser("~/pytorch-examples-temp/vae") + '/reconstruction_' + str(epoch) + '.png', nrow=n)
 
     test_loss /= len(test_loader.dataset)
     print('====> Test set loss: {:.4f}'.format(test_loss))
@@ -137,4 +139,4 @@ if __name__ == "__main__":
             sample = torch.randn(64, 20).to(device)
             sample = model.decode(sample).cpu()
             save_image(sample.view(64, 1, 28, 28),
-                       'results/sample_' + str(epoch) + '.png')
+                       os.path.expanduser("~/pytorch-examples-temp/vae") + '/sample_' + str(epoch) + '.png')
