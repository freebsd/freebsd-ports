from keras.models import Sequential
from keras.layers import Dense
import numpy as np

# 1. Generate dummy data (replace with your actual data)
# For binary classification, let's create a simple dataset
X = np.random.rand(100, 5)  # 100 samples, 5 features
y = (X.sum(axis=1) > 2.5).astype(int) # Binary labels based on feature sum

# 2. Define the Keras Sequential model
model = Sequential()

# Add a Dense (fully connected) hidden layer
# 12 nodes, 'relu' activation, input_shape specifies the number of features in your input
model.add(Dense(12, input_shape=(5,), activation='relu'))

# Add another Dense hidden layer
model.add(Dense(8, activation='relu'))

# Add the output layer
# 1 node for binary classification, 'sigmoid' activation for probabilities
model.add(Dense(1, activation='sigmoid'))

# 3. Compile the Keras model
# 'adam' optimizer is a good general-purpose optimizer
# 'binary_crossentropy' is suitable for binary classification
# 'accuracy' is a common metric to monitor during training
model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])

# 4. Train the model
# epochs: number of times to iterate over the entire dataset
# batch_size: number of samples per gradient update
model.fit(X, y, epochs=50, batch_size=32, verbose=0) # verbose=0 suppresses training output

# 5. Evaluate the model (optional)
loss, accuracy = model.evaluate(X, y, verbose=0)
print(f"Model Loss: {loss:.4f}, Accuracy: {accuracy:.4f}")

# 6. Make predictions (optional)
predictions = model.predict(X)
