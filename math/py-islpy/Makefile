PORTNAME=	islpy
DISTVERSION=	2026.1
CATEGORIES=	math
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Wrapper around isl, an integer set library
WWW=		https://documen.tician.de/islpy/

LICENSE=	MIT

BUILD_DEPENDS=	cmake:devel/cmake-core \
		${PYTHON_PKGNAMEPREFIX}scikit-build>0:devel/py-scikit-build@${PY_FLAVOR} \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nanobind>=2.7:devel/py-nanobind@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pcpp>0:devel/py-pcpp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0.9.3:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.5:devel/py-typing-extensions@${PY_FLAVOR}
LIB_DEPENDS=	libbarvinok.so:math/barvinok \
		libisl.so:devel/isl \
		libpolylibgmp.so:math/polylib

USES=		cmake:indirect llvm:15 python # w/out llvm:* the build fails to find LLVMgold.so
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/test

# tests as of 2026.1: 101 passed, 1 skipped, 7 warnings in 19.98s

.include <bsd.port.mk>
