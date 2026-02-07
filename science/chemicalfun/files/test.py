# test from README

import chemicalfun as cf

formulas = ['Ca+2', 'CO3-2', 'H+', 'OH-', 'HCO3-', 'CaCO3', 'H2O']

chemicalReactions = cf.ChemicalReactions(formulas)

reactions = chemicalReactions.generateReactions() # returns the reactions list as a list of tuples ('substance', coefficient)

# can be transformed to a list of dictionaries, with reaction substances as keys and the reaction coefficients as values
reactions_dic = [{el[0]: el[1] for el in r} for r in reactions] 

print(chemicalReactions.printReactions())
print(reactions_dic)
