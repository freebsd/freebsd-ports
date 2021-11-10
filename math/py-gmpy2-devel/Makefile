# Created by: Yuri Victorovich <yuri@rawbw.com>

PORTNAME=	gmpy2
DISTVERSIONPREFIX=	gmpy2-
DISTVERSION=	2.1.0b5
PORTREVISION=	1
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-devel

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	GMP, MPFR, and MPC interface to Python - devel version

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpc.so:math/mpc \
		libmpfr.so:math/mpfr

USE_GITHUB=	yes
GH_ACCOUNT=	aleaxit
GH_PROJECT=	gmpy

USES=		localbase python:3.7-3.9
USE_PYTHON=	distutils

CONFLICTS=	${PYTHON_PKGNAMEPREFIX}gmpy2-2.0*

OPTIONS_DEFINE=		DOCS
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}
DOCS_USES=		gmake
PORTDOCS=		*

PLIST_SUB=	VER=${DISTVERSION}

do-build-DOCS-on:
	(cd ${WRKSRC}/docs && ${GMAKE} SPHINXBUILD=sphinx-build-${PYTHON_VER} html)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/_build/html/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
