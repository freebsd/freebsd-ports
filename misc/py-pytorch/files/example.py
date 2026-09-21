import torch
import torch.nn as nn
import torch.optim as optim
import numpy as np

# Set random seed for reproducibility
torch.manual_seed(42)
np.random.seed(42)

# Define the target mathematical function
def target_function(a, b, c):
    return 18*a*b*c - 4*(a**3)*c + (a**2)*(b**2) - 4*(b**3) - 27*(c**2)

# ==========================================
# (1) Define Neural Network and Train
# ==========================================

# A deep network with architectural modifications to easily map polynomial boundaries
class DiscriminantNN(nn.Module):
    def __init__(self):
        super(DiscriminantNN, self).__init__()
        self.net = nn.Sequential(
            nn.Linear(3, 128),
            nn.GELU(),
            nn.Linear(128, 128),
            nn.GELU(),
            nn.Linear(128, 64),
            nn.GELU(),
            nn.Linear(64, 1)
        )
        
    def forward(self, x):
        return self.net(x)

# Generate dense grid data for the 0..1 interval with 0.05 step to cover the domain topology
grid_steps = np.linspace(0.0, 1.0, 21)
a_grid, b_grid, c_grid = np.meshgrid(grid_steps, grid_steps, grid_steps)
X_train_np = np.stack([a_grid.ravel(), b_grid.ravel(), c_grid.ravel()], axis=1)
y_train_np = target_function(X_train_np[:, 0], X_train_np[:, 1], X_train_np[:, 2]).reshape(-1, 1)

X_train = torch.tensor(X_train_np, dtype=torch.float32)
y_train = torch.tensor(y_train_np, dtype=torch.float32)

# Model initialization
model = DiscriminantNN()
criterion = nn.MSELoss()
optimizer = optim.AdamW(model.parameters(), lr=0.005, weight_decay=1e-5)
scheduler = optim.lr_scheduler.ReduceLROnPlateau(optimizer, mode='min', factor=0.5, patience=100)

print("Training started...")
epoch = 0
max_epochs = 10000

while epoch < max_epochs:
    #print(f"Epoch {epoch:04d} | Learning Rate: {optimizer.param_groups[0]['lr']:.6f}")
    model.train()
    optimizer.zero_grad()
    predictions = model(X_train)
    loss = criterion(predictions, y_train)
    loss.backward()
    optimizer.step()
    
    # Calculate absolute errors on the training set
    with torch.no_grad():
        abs_errors = torch.abs(predictions - y_train)
        max_error = torch.max(abs_errors).item()
        mean_error = torch.mean(abs_errors).item()
        scheduler.step(loss)
        
    if epoch % 500 == 0 or max_error < 0.001:
        print(f"Epoch {epoch:04d} | Loss: {loss.item():.2e} | Max Abs Error: {max_error:.5f} | Mean Abs Error: {mean_error:.5f}")
        
    # Stop explicitly once the entire domain satisfies the 0.001 precision threshold
    if max_error < 0.001:
        print(f"\nTarget precision of 0.001 achieved globally across training domain at epoch {epoch}!")
        break
        
    epoch += 1

# ==========================================
# (2) Evaluate within the 0..1 range
# ==========================================
print("\n--- Evaluation Inside [0, 1]^3 Domain ---")
model.eval()

# Generate 10,000 completely random uniform points inside the unit cube
X_inside_np = np.random.uniform(0.0, 1.0, (10000, 3))
y_inside_exact = target_function(X_inside_np[:, 0], X_inside_np[:, 1], X_inside_np[:, 2]).reshape(-1, 1)

X_inside = torch.tensor(X_inside_np, dtype=torch.float32)
y_inside_exact = torch.tensor(y_inside_exact, dtype=torch.float32)

with torch.no_grad():
    y_inside_pred = model(X_inside)
    errors_inside = torch.abs(y_inside_pred - y_inside_exact)
    within_precision_inside = torch.sum(errors_inside <= 0.001).item()

print(f"Total validation points evaluated: {len(X_inside_np)}")
print(f"Points within 0.001 precision: {within_precision_inside} / 10,000 ({within_precision_inside/100:.2f}%)")

# ==========================================
# (3) Evaluate Outside the 0..1 Range
# ==========================================
print("\n--- Evaluation Outside [0, 1]^3 Domain (Extrapolation) ---")

X_outside_list = []
# Rejection sampling loop to get 10,000 points strictly within [-0.5, 1.5] but outside [0, 1]
while len(X_outside_list) < 10000:
    candidates = np.random.uniform(-0.5, 1.5, (20000, 3))
    # A point is outside if any coordinate falls outside [0, 1]
    is_outside = np.any((candidates < 0.0) | (candidates > 1.0), axis=1)
    filtered = candidates[is_outside]
    X_outside_list.extend(filtered)

X_outside_np = np.array(X_outside_list[:10000])
y_outside_exact = target_function(X_outside_np[:, 0], X_outside_np[:, 1], X_outside_np[:, 2]).reshape(-1, 1)

X_outside = torch.tensor(X_outside_np, dtype=torch.float32)
y_outside_exact = torch.tensor(y_outside_exact, dtype=torch.float32)

with torch.no_grad():
    y_outside_pred = model(X_outside)
    errors_outside = torch.abs(y_outside_pred - y_outside_exact)
    within_precision_outside = torch.sum(errors_outside <= 0.001).item()
    failed_precision_outside = 10000 - within_precision_outside

print(f"Total extrapolation points evaluated: {len(X_outside_np)}")
print(f"Points within 0.001 precision: {within_precision_outside}")
print(f"Points outside 0.001 precision: {failed_precision_outside}")

