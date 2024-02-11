import numpy as np
import spglib

lattice = np.array([[0.0, 0.5, 0.5],
                    [0.5, 0.0, 0.5],
                    [0.5, 0.5, 0.0]]) * 5.4
positions = [[0.875, 0.875, 0.875],
            [0.125, 0.125, 0.125]]
numbers= [1,] * 2
cell = (lattice, positions, numbers)
print(spglib.get_spacegroup(cell, symprec=1e-5))
mesh = [8, 8, 8]

#
# Gamma centre mesh
#
mapping, grid = spglib.get_ir_reciprocal_mesh(mesh, cell, is_shift=[0, 0, 0])

# All k-points and mapping to ir-grid points
for i, (ir_gp_id, gp) in enumerate(zip(mapping, grid)):
    print("%3d ->%3d %s" % (i, ir_gp_id, gp.astype(float) / mesh))

# Irreducible k-points
print("Number of ir-kpoints: %d" % len(np.unique(mapping)))
print(grid[np.unique(mapping)] / np.array(mesh, dtype=float))

#
# With shift
#
mapping, grid = spglib.get_ir_reciprocal_mesh(mesh, cell, is_shift=[1, 1, 1])

# All k-points and mapping to ir-grid points
for i, (ir_gp_id, gp) in enumerate(zip(mapping, grid)):
    print("%3d ->%3d %s" % (i, ir_gp_id, (gp + [0.5, 0.5, 0.5]) / mesh))

# Irreducible k-points
print("Number of ir-kpoints: %d" % len(np.unique(mapping)))
print((grid[np.unique(mapping)] + [0.5, 0.5, 0.5]) / mesh)

