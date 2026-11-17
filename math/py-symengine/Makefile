PORTNAME=	symengine
DISTVERSIONPREFIX=	v
DISTVERSION=	0.15.1
CATEGORIES=	math python
#MASTER_SITES=	PYPI # latest release isn't compatible with math/symengine
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python library providing wrappers to SymEngine
WWW=		https://symengine.org/ \
		https://github.com/symengine/symengine.py

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cython>=0.29.14:lang/cython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cython-cmake>0:devel/py-cython-cmake@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>0:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR}
LIB_DEPENDS=	libarb.so:math/arb \
		libecm.so:math/gmp-ecm \
		libflint.so:math/flint2 \
		libgmp.so:math/gmp \
		libmpc.so:math/mpc \
		libmpfr.so:math/mpfr \
		libsymengine.so:math/symengine
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sympy>0:math/py-sympy@${PY_FLAVOR} # see https://github.com/symengine/symengine.py/issues/416

USES=		cmake:indirect compiler:c++11-lang llvm:lib python
USE_PYTHON=	pep517 autoplist flavors pytest

USE_GITHUB=	yes
GH_PROJECT=	symengine.py

MAKE_ENV=	SETUPTOOLS_SCM_PRETEND_VERSION=${DISTVERSION}

TEST_WRKSRC=	${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} # the source directory has no compiled module
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload

POST_PLIST=	fix-plist

fix-plist:
	@${REINPLACE_CMD} -E '/CMakeLists\.txt$$|pywrapper\.cpp$$|\.in\.py[x]?$$|\.in\.pxd$$/d' ${TMPPLIST}

post-install: # remove build-only sources that scikit-build-core copies into the wheel
	@${RM} ${STAGEDIR}${PYTHON_SITELIBDIR}/symengine/CMakeLists.txt \
		${STAGEDIR}${PYTHON_SITELIBDIR}/symengine/lib/CMakeLists.txt \
		${STAGEDIR}${PYTHON_SITELIBDIR}/symengine/lib/pywrapper.cpp \
		${STAGEDIR}${PYTHON_SITELIBDIR}/symengine/lib/symengine_wrapper.in.pxd \
		${STAGEDIR}${PYTHON_SITELIBDIR}/symengine/lib/symengine_wrapper.in.pyx \
		${STAGEDIR}${PYTHON_SITELIBDIR}/symengine/tests/CMakeLists.txt

# cmake scripts copy build type and flags from math/symengine, and ignore all local variables of that kind

# tests as of 0.15.1: 365 passed, 2 skipped, 2 warnings in 1.51s

.include <bsd.port.mk>
