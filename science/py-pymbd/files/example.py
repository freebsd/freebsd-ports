from pymbd import mbd_energy_species
from pymbd.fortran import MBDGeom

energy = mbd_energy_species([(0, 0, 0), (0, 0, 7.5)], ['Ar', 'Ar'], [1, 1], 0.83)

print("energy="+str(energy))
