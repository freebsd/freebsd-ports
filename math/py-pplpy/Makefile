# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	pplpy
PORTVERSION=	0.8.4
PORTREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Python wrapper to the C++ Parma Polyhedra Library (PPL)

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gmpy2-devel>0:math/py-gmpy2-devel@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}cysignals>0:devel/py-cysignals@${PY_FLAVOR}
LIB_DEPENDS=	libgmp.so:math/gmp	\
		libmpfr.so:math/mpfr	\
		libmpc.so:math/mpc	\
		libpari.so:math/pari	\
		libppl.so:devel/ppl
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gmpy2-devel>0:math/py-gmpy2-devel@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}cysignals>0:devel/py-cysignals@${PY_FLAVOR}

USES=		compiler:c++11-lang localbase python:3.6+
USE_PYTHON=	cython distutils

OPTIONS_DEFINE=		DOCS
DOCS_BUILD_DEPENDS=	${PY_SPHINX}
DOCS_USES=		gmake
PORTDOCS=		*

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == "clang" && ${COMPILER_VERSION} >= 110
# error: cannot initialize a parameter of type 'bool' with an rvalue of type 'nullptr_t'
BUILD_DEPENDS+=	${LOCALBASE}/bin/clang10:devel/llvm10
CPP=	${LOCALBASE}/bin/clang-cpp10
CC=	${LOCALBASE}/bin/clang10
CXX=	${LOCALBASE}/bin/clang++10
.endif

do-build-DOCS-on:
	(cd ${WRKSRC}/docs && ${GMAKE} html)

post-build-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/build/html/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
