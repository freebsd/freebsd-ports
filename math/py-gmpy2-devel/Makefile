# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	gmpy2
DISTVERSIONPREFIX=	gmpy2-
DISTVERSION=	2.1.0b4
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-devel

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	GMP, MPFR, and MPC interface to Python - devel version

LICENSE=	GPLv3

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpc.so:math/mpc \
		libmpfr.so:math/mpfr

USE_GITHUB=	yes
GH_ACCOUNT=	aleaxit
GH_PROJECT=	gmpy

USES=		localbase python:3.7+
USE_PYTHON=	distutils

CONFLICTS=	${PYTHON_PKGNAMEPREFIX}gmpy2-2.0*

OPTIONS_DEFINE=		DOCS
DOCS_BUILD_DEPENDS=	${PY_SPHINX}
DOCS_USES=		gmake
PORTDOCS=		*

PLIST_SUB=	VER=${DISTVERSION}

do-build-DOCS-on:
	(cd ${WRKSRC}/docs && ${GMAKE} html)

post-build-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/_build/html/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
