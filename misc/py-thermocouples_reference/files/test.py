from thermocouples_reference import thermocouples

typeK = thermocouples['K']
print(f"typeK={typeK}")

t1 = typeK.emf_mVC(42, Tref=0)
print(f"t1={t1}")

t2 = typeK.emf_mVC([-3.14159, 42, 54], Tref=0)
print(f"t2={t2}")
