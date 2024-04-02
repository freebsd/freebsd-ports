# example from https://www.openvdb.org/documentation/doxygen/python.html

import pyopenvdb as vdb

# A grid comprises a sparse tree representation of voxel data,
# user-supplied metadata and a voxel space to world space transform,
# which defaults to the identity transform.
# A FloatGrid stores one single-precision floating point value per voxel.
# Other grid types include BoolGrid and Vec3SGrid.  The module-level
# attribute pyopenvdb.GridTypes gives the complete list.
cube = vdb.FloatGrid()
cube.fill(min=(100, 100, 100), max=(199, 199, 199), value=1.0)

# Name the grid "cube".
cube.name = 'cube'

# Populate another FloatGrid with a sparse, narrow-band level set
# representation of a sphere with radius 50 voxels, located at
# (1.5, 2, 3) in index space.
sphere = vdb.createLevelSetSphere(radius=50, center=(1.5, 2, 3))

# Associate some metadata with the grid.
sphere['radius'] = 50.0

# Associate a scaling transform with the grid that sets the voxel size
# to 0.5 units in world space.
sphere.transform = vdb.createLinearTransform(voxelSize=0.5)

# Name the grid "sphere".
sphere.name = 'sphere'

# Write both grids to a VDB file.
vdb.write('mygrids.vdb', grids=[cube, sphere])
