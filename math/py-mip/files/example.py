from mip import Model, xsum, maximize, BINARY

# 1. Define the problem data
profits = [10, 13, 18, 31, 7, 15]
weights = [11, 15, 20, 35, 10, 33]
capacity = 47
item_indices = range(len(weights))

# 2. Initialize the Model
model = Model(name="knapsack")

# 3. Create Binary Decision Variables (0 = skip item, 1 = take item)
x = [model.add_var(var_type=BINARY) for i in item_indices]

# 4. Define the Objective Function (Maximize total profit)
model.objective = maximize(xsum(profits[i] * x[i] for i in item_indices))

# 5. Add Constraints (Total weight must be less than or equal to capacity)
model += xsum(weights[i] * x[i] for i in item_indices) <= capacity

# 6. Optimize the model
model.optimize()

# 7. Extract and print the results
selected_items = [i for i in item_indices if x[i].x >= 0.99]

print(f"Optimization Status: {model.status}")
print(f"Total Profit: {model.objective_value}")
print(f"Selected Item Indices: {selected_items}")

