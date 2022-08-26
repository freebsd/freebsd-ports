##
## Tree Decomposition example from README
##

from dwave.samplers import TreeDecompositionSolver
solver = TreeDecompositionSolver()

import dimod
import networkx as nx

tree = nx.balanced_tree(2, 5)  # binary tree with a height of five
bqm = dimod.BinaryQuadraticModel('SPIN')
bqm.set_linear(0, .5)
for u, v in tree.edges:
    bqm.set_quadratic(u, v, 1)
sampleset = solver.sample(bqm)

print(sampleset)
