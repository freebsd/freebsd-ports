# Makefile of Sample program
# Written by NAKATA, Maho <maho@FreeBSD.org>
# $FreeBSD$

all: densg densg2

densg: example1.f   # f77 version
	mpif77 -o densg example1.f -L/usr/local/lib -lscalapack -lblacs -lblacsf77 -lblacs -lf77blas -latlas
	
densg2: example1.cc # C++ version
	mpiCC -o densg2 example1.cc -I/usr/local/mpich/include -I/usr/local/include -L/usr/local/lib -lscalapack -lblacs -lblacsf77 -lblacs -lf77blas -latlas -lg2c -lm
