# New ports collection makefile for:	Elmer-mathlibs
# Date created:		5 Jan 2006
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	mathlibs
PORTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.funet.fi/pub/sci/physics/elmer/src/
PKGNAMEPREFIX=	elmer-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Math libraries build with F90 for used in ELMER FEM

DEPRECATED=	No ports depends on this as migrated to gfortran
IGNORE=		No ports depends on this as migrated to gfortran

.ifdef WITH_MPI
BUILD_DEPENDS+=	${LOCALBASE}/mpich/include/mpif.h:${PORTSDIR}/net/mpich
.endif

CONFLICTS=	atlas-[0-9]* blas-[0-9]* arpack-[0-9]* lapack-[0-9]*
.ifdef WITH_MPI
CONFLICTS+=	scalapack-[0-9]*
.endif

WANT_FORTRAN=yes #dummy but future use
BUILD_DEPENDS+= gfortran42:${PORTSDIR}/lang/gcc42
FC=	gfortran42
F77=	gfortran42
.ifdef WITH_OPTIMIZED_FLAGS
FFLAGS+=	-O3 -ffast-math
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
