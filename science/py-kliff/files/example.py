from kliff.dataset import Dataset
from kliff.models import NeuralNetwork
from kliff.utils import download_dataset

# 1. Using the legacy/imperative modules for custom configuration setup
from kliff.legacy import nn
from kliff.legacy.calculators import CalculatorTorch
from kliff.legacy.descriptors import SymmetryFunction
from kliff.legacy.loss import Loss

# 2. Define a descriptor to featurize atomic environments (e.g., for Silicon)
descriptor = SymmetryFunction(
    cut_name="cos",
    cut_dists={"Si-Si": 5.0},
    hyperparams="set51",
    normalize=True
)

# 3. Create a multi-layer Neural Network potential using the descriptor
model = NeuralNetwork(descriptor)
model.add_layers(
    nn.Linear(descriptor.get_size(), 10),  # First hidden layer (10 units)
    nn.Tanh(),
    nn.Linear(10, 10),                     # Second hidden layer (10 units)
    nn.Tanh(),
    nn.Linear(10, 1),                      # Output layer (Energy prediction)
)

# 4. Download and parse a crystal structure training dataset
dataset_path = download_dataset(dataset_name="Si_training_set")
dataset_path = dataset_path.joinpath("varying_alat")
train_set = Dataset.from_path(dataset_path)
configs = train_set.get_configs()

# 5. Initialize the calculator (using PyTorch backend) to compute energy/forces
calc = CalculatorTorch(model, gpu=False)
calc.create(configs)

# 6. Define the optimizer loss function
loss = Loss(calc)

print(f"Total configurations loaded: {len(configs)}")
print("KLIFF environment successfully configured for potential fitting.")

