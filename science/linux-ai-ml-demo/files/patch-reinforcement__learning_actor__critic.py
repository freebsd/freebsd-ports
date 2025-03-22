--- reinforcement_learning/actor_critic.py.orig	2025-02-09 16:56:58 UTC
+++ reinforcement_learning/actor_critic.py
@@ -10,6 +10,10 @@ from torch.distributions import Categorical
 import torch.optim as optim
 from torch.distributions import Categorical
 
+# numpy.bool8 is deprecated since version 1.24.0
+if not hasattr(np, 'bool8'):
+    np.bool8 = np.bool_
+
 # Cart Pole
 
 parser = argparse.ArgumentParser(description='PyTorch actor-critic example')
