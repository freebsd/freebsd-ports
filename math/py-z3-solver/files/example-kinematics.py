# example from https://ericpony.github.io/z3py-tutorial/guide-examples.htm

from z3 import Reals, set_option, solve


d, a, t, v_i, v_f = Reals('d a t v__i v__f')

equations = [
   d == v_i * t + (a*t**2)/2,
   v_f == v_i + a*t,
]

# Given v_i, t and a, find d
problem = [
    v_i == 0,
    t   == 4.10,
    a   == 6
]

solve(equations + problem)

# Display rationals in decimal notation
set_option(rational_to_decimal=True)

solve(equations + problem)
