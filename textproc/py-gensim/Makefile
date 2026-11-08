PORTNAME=	gensim
DISTVERSION=	4.4.0
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python framework for fast Vector Space Modelling
WWW=		https://radimrehurek.com/gensim/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.7.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.7.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}smart-open>=1.8.1:net/py-smart-open@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}testfixtures>0:devel/py-testfixtures@${PY_FLAVOR}

USES=		compiler:c++11-lang python
USE_PYTHON=	autoplist cython pep517 pytest

USE_GITHUB=	yes
GH_ACCOUNT=	RaRe-Technologies

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/gensim/test
TEST_ARGS=	-k 'not (test_multipart_load or test_load_dataset)'

# tests as of 4.4.0: 993 passed, 120 skipped, 2 deselected, 1 xfailed in 578.71s

# Force regeneration of C/C++ sources from Cython; bundled .c/.cpp files are
# stale and fail to compile with current Python.
post-patch:
	@${FIND} ${WRKSRC}/gensim \( -name "*.c" -o -name "*.cpp" \) -delete

pre-test:
	@for so in `${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/gensim -name '*.so'`; do \
		target="$${so#${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/}" ; \
		${CP} "$$so" "${WRKSRC}/$$target" ; \
	done

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name "*.so" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
