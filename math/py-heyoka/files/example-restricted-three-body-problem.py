import heyoka as hy
import numpy as np

# Create the symbolic variables.
# from https://bluescarni.github.io/heyoka.py/notebooks/The%20restricted%20three-body%20problem.html

x, y, z, px, py, pz = hy.make_vars("x", "y", "z", "px", "py", "pz")

# Fix mu to 0.01.
mu = 0.01

rps_32 = ((x - mu)**2 + y**2 + z**2)**(-3/2.)
rpj_32 = ((x - mu  + 1.)**2 + y**2 + z**2)**(-3/2.)

# The equations of motion.
dxdt = px + y
dydt = py - x
dzdt = pz
dpxdt = py - (1. - mu) * rps_32 * (x - mu) - mu * rpj_32 * (x - mu + 1.)
dpydt = -px -((1. - mu) * rps_32 + mu * rpj_32) * y
dpzdt = -((1. - mu) * rps_32 + mu * rpj_32) * z

# create the integrator object
ta = hy.taylor_adaptive(
    # The ODEs.
    [(x, dxdt), (y, dydt), (z, dzdt),
     (px, dpxdt), (py, dpydt), (pz, dpzdt)],
    # The initial conditions.
    [-0.45, 0.80, 0.00, -0.80, -0.45, 0.58],
    # Operate below machine precision
    # and in high-accuracy mode.
    tol = 1e-18, high_accuracy = True
)

# integrate the RTBP up to time unit
t_grid = np.linspace(0, 200, 2500)
out = ta.propagate_grid(t_grid)
print(out)

# plot
from matplotlib.pylab import plt
plt.rcParams["figure.figsize"] = (12,6)

plt.subplot(1,2,1)
plt.plot(out[4][:, 0], out[4][:, 1])
plt.xlabel("x")
plt.ylabel("y")
plt.subplot(1,2,2)
plt.plot(out[4][:, 0], out[4][:, 2])
plt.xlabel("x")
plt.ylabel("z");

plt.show();
