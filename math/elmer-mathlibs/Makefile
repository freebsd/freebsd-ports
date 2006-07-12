# New ports collection makefile for:	Elmer-mathlibs
# Date created:		5 Jan 2006
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	mathlibs
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.funet.fi/pub/sci/physics/elmer/
PKGNAMEPREFIX=	elmer-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Math libraries build with F90 for used in ELMER FEM

BUILD_DEPENDS=	${FC}:${PORTSDIR}/lang/gfortran
.ifdef WITH_MPI
BUILD_DEPENDS+=	${LOCALBASE}/mpich/include/mpif.h:${PORTSDIR}/net/mpich
.endif

CONFLICTS=	atlas-[0-9]* blas-[0-9]* arpack-[0-9]* lapack-[0-9]*
.ifdef WITH_MPI
CONFLICTS+=	scalapack-[0-9]*
.endif

USE_GCC=	4.1+
WITH_FORTRAN=	yes
FC=	${LOCALBASE}/bin/gfortran41
F77=	${FC}

.ifdef WITH_OPTIMIZED_FLAGS
FFLAGS+=	-O3 -ffast-math -funroll-loops
.endif

CONFIGURE_ENV+=	F77=${FC} FFLAGS="${FFLAGS}"
GNU_CONFIGURE=	yes
.ifdef WITH_MPI
CONFIGURE_ARGS+=	--with-mpi=yes --with-mpi-dir=${LOCALBASE}/mpich
.endif

ALL_TARGET=

PLIST_FILES=	lib/libarpack.a lib/libblas.a lib/liblapack.a
.ifdef WITH_MPI
PLIST_FILES+=	lib/libparpack.a
.endif

.include <bsd.port.mk>
