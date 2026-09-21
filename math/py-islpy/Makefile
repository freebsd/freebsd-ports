PORTNAME=	islpy
DISTVERSION=	2026.2.2
CATEGORIES=	math
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Wrapper around isl, an integer set library
WWW=		https://documen.tician.de/islpy/

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nanobind>=3.0:devel/py-nanobind@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pcpp>0:devel/py-pcpp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0.9.3:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.5:devel/py-typing-extensions@${PY_FLAVOR}
LIB_DEPENDS=	libbarvinok.so:math/barvinok \
		libisl.so:devel/isl \
		libpolylibgmp.so:math/polylib

USES=		cmake:indirect llvm:min=16 python # w/out llvm:* the build fails to find LLVMgold.so
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload
TEST_WRKSRC=	${WRKSRC}/test

# tests as of 2026.2.2: 32 passed, 1 skipped

.include <bsd.port.mk>
