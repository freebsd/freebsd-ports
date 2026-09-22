#!/usr/bin/env python3
"""Smoke test for the onnxruntime Python wheel.

Loads a tiny Add model, runs inference, and verifies the output.
This script is run by the port's do-test target against the staged package.
"""

import sys

import numpy as np
import onnxruntime


def main() -> int:
    print(f"onnxruntime version: {onnxruntime.__version__}")

    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <model.onnx>", file=sys.stderr)
        return 1

    session = onnxruntime.InferenceSession(sys.argv[1])
    a = np.array([[1.0, 2.0], [3.0, 4.0]], dtype=np.float32)
    b = np.array([[2.0, 3.0], [4.0, 5.0]], dtype=np.float32)
    outputs = session.run(None, {"a": a, "b": b})

    expected = np.array([[3.0, 5.0], [7.0, 9.0]], dtype=np.float32)
    if not np.allclose(outputs[0], expected):
        print(f"Output mismatch: got {outputs[0]}, expected {expected}", file=sys.stderr)
        return 1

    print("python smoke test: succeeded")
    return 0


if __name__ == "__main__":
    sys.exit(main())
