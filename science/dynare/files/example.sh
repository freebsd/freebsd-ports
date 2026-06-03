#!/bin/sh
# Run a Dynare example model (neo-classical Ramsey deterministic).
# Dynare does not allow periods in directory names, so we copy the
# .mod file to a temporary directory before running.
tmpdir=$(mktemp -d)
trap 'rm -rf "$tmpdir"' EXIT
cp ./work/dynare-7.0/tests/optimal_policy/neo_ramsey_det_bytecode.mod "$tmpdir/"
cd "$tmpdir"
octave --eval 'dynare neo_ramsey_det_bytecode.mod'
