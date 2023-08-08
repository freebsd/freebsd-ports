PORTNAME=	fastcluster
PORTVERSION=	1.2.6
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast hierarchical clustering routines for R and Python
WWW=		http://danifold.net/fastcluster.html \
		https://github.com/dmuellner/fastcluster

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.9,1:math/py-numpy@${PY_FLAVOR}

USES=		compiler python
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.pre.mk>

.if ${ARCH:Mpowerpc*} && ${COMPILER_VERSION} == 140
BUILD_DEPENDS+=	clang15:devel/llvm15
CPP=            clang-cpp15
CC=             clang15
CXX=            clang++15
.endif

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.post.mk>
