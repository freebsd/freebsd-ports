PORTNAME=	islpy
DISTVERSION=	2023.2.5
CATEGORIES=	math
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Wrapper around isl, an integer set library
WWW=		https://documen.tician.de/islpy/

LICENSE=	MIT

BUILD_DEPENDS=	cmake:devel/cmake-core \
		${PYTHON_PKGNAMEPREFIX}nanobind>0:devel/py-nanobind@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pcpp>0:devel/py-pcpp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build>0:devel/py-scikit-build@${PY_FLAVOR} \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libbarvinok.so:math/barvinok \
		libisl.so:devel/isl \
		libpolylibgmp.so:math/polylib

USES=		llvm:15 python shebangfix # w/out llvm:* the build fails to find LLVMgold.so
USE_PYTHON=	pep517 autoplist pytest

SHEBANG_FILES=	configure.py

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/test

do-configure:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ./configure.py \
			--enable-shared \
			--python-exe=${PYTHON_CMD} \
			--isl-inc-dir=${PREFIX}/include \
			--isl-lib-dir=${PREFIX}/lib \
			--no-use-shipped-imath \
			--no-use-shipped-isl \
			--use-barvinok \
			--prefix=${PREFIX}

.include <bsd.port.mk>
