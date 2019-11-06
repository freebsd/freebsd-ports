# $FreeBSD$

PORTNAME=	slepc
DISTVERSION=	3.10.1
PORTREVISION=	3
CATEGORIES=	math devel
MASTER_SITES=	http://slepc.upv.es/download/distrib/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scalable Library for Eigenvalue Problem Computations

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack \
		libmpich.so:net/mpich \
		libpetsc.so:science/PETSc

USES=		gmake fortran python:2.7 shebangfix xorg
SHEBANG_FILES=	configure
SHEBANG_GLOB=	*.py
MAKEFILE=	makefile
MAKE_ENV=	PETSC_DIR=${LOCALBASE} PETSC_ARCH="" SLEPC_DIR=${WRKSRC} PYTHON=${PYTHON_CMD}
USE_XORG=	x11 # not really needed, but is inherited from the PETSc setup
USE_LDCONFIG=	yes

OS_VER=		${OPSYS:tl}${OSVERSION:C/(.*)...../\\1/}

BINARY_ALIAS=	python=${PYTHON_CMD}

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	*

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./configure
	@${REINPLACE_CMD} -e 's|^SLEPC_DESTDIR *=.*|SLEPC_DESTDIR = ${PREFIX}|' \
		${WRKSRC}/installed-arch-${OS_VER}-c-debug/lib/slepc/conf/slepcvariables # otherwise it fills a wrong value for some reason

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libslepc.so.${PORTVERSION}
	@${REINPLACE_CMD} -i '' -e 's|#!/usr/bin/env python|#!${PYTHON_CMD}|' \
		${STAGEDIR}${PREFIX}/lib/slepc/conf/reconfigure-installed-arch-${OS_VER}-c-debug.py

.include <bsd.port.mk>
