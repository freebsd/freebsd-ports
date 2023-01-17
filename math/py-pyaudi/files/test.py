# from http://darioizzo.github.io/audi/notebooks/example00.html

from pyaudi import gdual_double as gdual
from pyaudi import sin, cos, tan

# Define some variables (gduals)
x,y,z = [gdual(0.,_,3) for _ in "xyz"]

# Create a function of these variables
f = x*x+2*tan(x/(y+1))-sin(z)
print(f)

# Extracting the derivatives
print(f.get_derivative([0,0,1]))
print(f.get_derivative({"dz": 1}))
print(f.get_derivative({"dx":1, "dy":1}))

# Changing the point
x = gdual(1.,"x",3)
y = gdual(2.,"y",3)
z = gdual(3.,"z",3)
f = x*x+2*tan(x/(y+1))-sin(z)
print(f)

print(f.get_derivative([0,0,1]))

print(-cos(3.))

# Encapsulating f in a function call

def f(x,y,z):
    return x*x+2*tan(x/(y+1))-sin(z)


x = gdual(1.,"x",3)
y = gdual(2.,"y",3)
z = gdual(3.,"z",3)
print(f(x,y,z)) #Call with gduals
print(f(1.,2.,3.))     #Call with floats
