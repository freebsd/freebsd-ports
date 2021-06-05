from pyscf import gto, scf
mol = gto.M(atom='H 0 0 0; H 0 0 1.2', basis='cc-pvdz')
mf = scf.RHF(mol)
mf.kernel()
