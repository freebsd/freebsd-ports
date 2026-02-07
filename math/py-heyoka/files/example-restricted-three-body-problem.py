# Create the symbolic variables.
# from https://bluescarni.github.io/heyoka.py/notebooks/The%20restricted%20three-body%20problem.html



import heyoka as hy
import numpy as np

# Create the symbolic variables.
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


t_grid = np.linspace(0, 200, 2500)

out = ta.propagate_grid(t_grid)

from matplotlib.pylab import plt

fig = plt.figure(figsize = (12, 6))

plt.subplot(1,2,1)
plt.plot(out[5][:, 0], out[5][:, 1])
plt.xlabel("x")
plt.ylabel("y")
plt.subplot(1,2,2)
plt.plot(out[5][:, 0], out[5][:, 2])
plt.xlabel("x")
plt.ylabel("z");
plt.show()


def ham(s):
    x, y, z, px, py, pz = s

    rps = ((x - mu)**2 + y**2 + z**2)**0.5
    rpj = ((x - mu  + 1.)**2 + y**2 + z**2)**0.5

    return .5 * (px**2 + py**2 + pz**2) + y*px - x*py - (1-mu)/rps - mu/rpj


fig = plt.figure(figsize = (8, 5))

plt.plot(t_grid, abs((ham(out[5][0]) - ham(out[5].transpose())) / ham(out[5][0])), 'x')
plt.xlabel('Time')
plt.ylabel('Relative error');
plt.show()

ta.time = 0
ta.state[:] = [-0.80, 0.0, 0.0, 0.0, -0.6276410653920693, 0.0]

t_grid = np.linspace(0, 2000, 100000)

out = ta.propagate_grid(t_grid)

fig = plt.figure(figsize = (12, 6))

ax = plt.subplot(1,1,1)

plt.axis('equal')
plt.plot(out[5][:, 0], out[5][:, 1])

cc0 = plt.Circle((0.01 , 0.), 0.012, ec='black', fc='orange', zorder=2)
cc1 = plt.Circle((-0.99 , 0.), 0.012, ec='black', fc='orange', zorder=2)

ax.add_artist(cc0)
ax.add_artist(cc1)

plt.xlabel("x")
plt.ylabel("y");


plt.show()

fig = plt.figure(figsize = (12, 6))

plt.semilogy(t_grid, abs((ham(out[5][0]) - ham(out[5].transpose()))))
plt.ylim(1e-16, 1e-11)
plt.xlabel('Time')
plt.ylabel('Relative error');
plt.show()
