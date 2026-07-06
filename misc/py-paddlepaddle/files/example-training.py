import numpy as np
import paddle
import paddle.nn as nn

# 1. Force PaddlePaddle to use CPU
paddle.set_device('cpu')

# 2. Create a small synthetic dataset (100 samples, 10 features)
np.random.seed(42)
X_data = np.random.randn(100, 10).astype('float32')
y_data = np.random.randint(0, 2, size=(100, 1)).astype('int64')

class SyntheticDataset(paddle.io.Dataset):
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def __getitem__(self, idx):
        return self.x[idx], self.y[idx]
    def __len__(self):
        return len(self.x)

dataset = SyntheticDataset(X_data, y_data)
loader = paddle.io.DataLoader(dataset, batch_size=16, shuffle=True)

# 3. Define a simple Multi-Layer Perceptron (MLP)
class SimpleMLP(nn.Layer):
    def __init__(self):
        super(SimpleMLP, self).__init__()
        self.fc1 = nn.Linear(in_features=10, out_features=8)
        self.relu = nn.ReLU()
        self.fc2 = nn.Linear(in_features=8, out_features=2)
        
    def forward(self, x):
        x = self.fc1(x)
        x = self.relu(x)
        x = self.fc2(x)
        return x

model = SimpleMLP()

# 4. Set up Optimizer and Loss Function
optimizer = paddle.optimizer.Adam(learning_rate=0.01, parameters=model.parameters())
criterion = nn.CrossEntropyLoss()

# 5. Run a 5-epoch training loop
print("Starting CPU training loop...")
for epoch in range(1, 6):
    total_loss = 0
    for batch_id, (features, labels) in enumerate(loader()):
        # Forward pass
        predictions = model(features)
        loss = criterion(predictions, labels)
        
        # Backward pass and optimization
        loss.backward()
        optimizer.step()
        optimizer.clear_grad()
        
        # FIX: Remove [0] because the array is a 0D scalar
        total_loss += loss.numpy()
        
    print(f"Epoch {epoch}/5 - Average Loss: {total_loss / len(loader):.4f}")

print("\nTraining completed successfully on CPU!")

# 6. Save the model parameters and optimizer state
print("\nSaving model...")
paddle.save(model.state_dict(), "simple_mlp.pdparams")
paddle.save(optimizer.state_dict(), "simple_mlp.pdopt")
print("Saved parameters to 'simple_mlp.pdparams'")
print("Saved optimizer state to 'simple_mlp.pdopt'")

# 7. Verification: Load the saved model back into memory
print("\nVerifying saved files by reloading...")
new_model = SimpleMLP()
new_optimizer = paddle.optimizer.Adam(learning_rate=0.01, parameters=new_model.parameters())

# Load the states
model_state = paddle.load("simple_mlp.pdparams")
optimizer_state = paddle.load("simple_mlp.pdopt")

# Apply the states to your new instances
new_model.set_state_dict(model_state)
new_optimizer.set_state_dict(optimizer_state)

print("Model and optimizer reloaded successfully!")

