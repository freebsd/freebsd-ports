--- time_sequence_prediction/train.py.orig	2025-02-09 16:56:58 UTC
+++ time_sequence_prediction/train.py
@@ -7,6 +7,7 @@ import matplotlib.pyplot as plt
 import matplotlib
 matplotlib.use('Agg')
 import matplotlib.pyplot as plt
+import os
 
 class Sequence(nn.Module):
     def __init__(self):
@@ -44,7 +45,7 @@ if __name__ == '__main__':
     np.random.seed(0)
     torch.manual_seed(0)
     # load data and make training set
-    data = torch.load('traindata.pt')
+    data = torch.load(os.path.join(os.path.expanduser("~/pytorch-examples-temp/time_sequence_prediction"), 'traindata.pt'), weights_only=False)
     input = torch.from_numpy(data[3:, :-1])
     target = torch.from_numpy(data[3:, 1:])
     test_input = torch.from_numpy(data[:3, :-1])
@@ -86,5 +87,5 @@ if __name__ == '__main__':
         draw(y[0], 'r')
         draw(y[1], 'g')
         draw(y[2], 'b')
-        plt.savefig('predict%d.pdf'%i)
+        plt.savefig(os.path.join(os.path.expanduser("~/pytorch-examples-temp/time_sequence_prediction"), f"predict{i}.pdf"))
         plt.close()
