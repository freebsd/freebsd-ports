--- reinforcement_learning/reinforce.py.orig	2025-02-09 16:56:58 UTC
+++ reinforcement_learning/reinforce.py
@@ -9,6 +9,9 @@ from torch.distributions import Categorical
 import torch.optim as optim
 from torch.distributions import Categorical
 
+# numpy.bool8 is deprecated since version 1.24.0
+if not hasattr(np, 'bool8'):
+    np.bool8 = np.bool_
 
 parser = argparse.ArgumentParser(description='PyTorch REINFORCE example')
 parser.add_argument('--gamma', type=float, default=0.99, metavar='G',
