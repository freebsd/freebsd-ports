# Import relevant modules 
import daqp
import numpy as np
from ctypes import * 
import ctypes.util

# Define the problem
H = np.array([[1, 0], [0, 1]],dtype=c_double)
f = np.array([1, 1],dtype=c_double)
A = np.array([[1, 2], [1, -1]],dtype=c_double)
bupper = np.array([1,2,3,4],dtype=c_double)
blower = np.array([-1,-2,-3,-4],dtype=c_double)
sense = np.array([0,0,0,0],dtype=c_int)

print('solving ...')
(xstar,fval,exitflag,info) = daqp.solve(H,f,A,bupper,blower,sense)

print(f'solution: xstar={xstar} fval={fval} exitflag={exitflag} info={info}')
