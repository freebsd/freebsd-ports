# New ports collection makefile for:   abinit
# Date Created:                18 March 2004
# Whom:                        NAKATA Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	abinit
PORTVERSION=	5.2.4
CATEGORIES=	science
MASTER_SITES=	${MASTER_SITE_LOCAL:S|%SUBDIR%|maho/abinit|} \
		ftp://ftp.abinit.org/pub/abinitio/ABINIT_v${PORTVERSION}/

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Abinit calculates electronic structure of systems

WANT_FORTRAN=	yes #dummy but future use
BUILD_DEPENDS+= gfortran42:${PORTSDIR}/lang/gcc42
FC=		gfortran42
F77=		gfortran42
CONFIGURE_ENV+=	FC="${FC}" F77="${F77}" FFLAGS="${FFLAGS}"

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:259
GNU_HOST=	${ARCH}-portbld-freebsd${OSREL}
PLIST_SUB=	GNU_HOST=${GNU_HOST}

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=     yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=   atlas.2:${PORTSDIR}/math/atlas
BLAS=		-lf77blas -latlas
LAPACK=		-lalapack
.else
LIB_DEPENDS+=   blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=   lapack.4:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.endif

test:
	cd ${WRKSRC}/tests ; ${GMAKE} tests

.include <bsd.port.post.mk>
