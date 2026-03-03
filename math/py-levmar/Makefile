# levmar library (math/levmar) is bundled

PORTNAME=	levmar
DISTVERSION=	0.3.0.dev0+git # version is hardcoded in the project
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Binding to levmar library (Levenberg-Marquardt optimization algorithm)
WWW=		https://github.com/bjodah/levmar

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack
TEST_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	pep517 cython autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	bjodah
GH_TAGNAME=	9291962

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--pyargs levmar
TEST_WRKSRC=	${WRKDIR}

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

# tests as of 0.3.0.dev0+git (9291962):
# Results (0.22s):
#         63 passed

.include <bsd.port.post.mk>
