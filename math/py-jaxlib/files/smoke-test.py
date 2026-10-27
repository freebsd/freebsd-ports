import ctypes  # noqa: F401 -- must precede numpy, see libgcc_s versioning on the ports gcc runtime
import numpy as np

import jax
import jax.numpy as jnp
import jaxlib

assert jax.devices()[0].platform == "cpu", jax.devices()

a = np.arange(12, dtype=np.float32).reshape(3, 4)
b = np.arange(8, dtype=np.float32).reshape(4, 2)
np.testing.assert_allclose(jax.jit(jnp.dot)(a, b), a @ b)
np.testing.assert_allclose(jnp.sum(a), a.sum())

m = np.array([[4.0, 1.0], [2.0, 3.0]], dtype=np.float32)
np.testing.assert_allclose(jnp.linalg.inv(m), np.linalg.inv(m), rtol=1e-5)
np.testing.assert_allclose(jnp.linalg.eigvalsh(m + m.T),
                           np.linalg.eigvalsh(m + m.T), rtol=1e-5)
np.testing.assert_allclose(jax.grad(lambda x: jnp.sum(x ** 3))(a), 3 * a ** 2)
np.testing.assert_allclose(jax.vmap(jnp.cumsum)(a), np.cumsum(a, axis=1))

print("jaxlib", jaxlib.__version__, "OK")
