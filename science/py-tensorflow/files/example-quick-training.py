import tensorflow as tf

# 1. Load and prepare the MNIST dataset
mnist = tf.keras.datasets.mnist
(x_train, y_train), (x_test, y_test) = mnist.load_data()
x_train, x_test = x_train / 255.0, x_test / 255.0  # Normalize pixel values

# 2. Build the Sequential model
model = tf.keras.models.Sequential([
  tf.keras.layers.Flatten(input_shape=(28, 28)),    # Flatten 2D image to 1D array
  tf.keras.layers.Dense(128, activation='relu'),    # Hidden layer with ReLU activation
  tf.keras.layers.Dropout(0.2),                     # Regularization to prevent overfitting
  tf.keras.layers.Dense(10)                         # Output layer for 10 classes
])

# 3. Compile the model
model.compile(optimizer='adam',
              loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),
              metrics=['accuracy'])

# 4. Train the model
model.fit(x_train, y_train, epochs=5)

# 5. Evaluate accuracy
model.evaluate(x_test,  y_test, verbose=2)
