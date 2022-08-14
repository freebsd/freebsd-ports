import neal

sampler = neal.SimulatedAnnealingSampler()

h = {0: -1, 1: -1}
J = {(0, 1): -1}
sampleset = sampler.sample_ising(h, J)

print(sampleset)
