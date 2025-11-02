PORTNAME=	scikit-learn
DISTVERSION=	1.7.2
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	scikit_learn-${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Machine learning algorithms for python
WWW=		https://scikit-learn.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}joblib>=1.3.0:devel/py-joblib@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.10.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}threadpoolctl>=3.2.0:devel/py-threadpoolctl@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}meson-python>=0.17.1:devel/meson-python@${PY_FLAVOR}

USES=		fortran python localbase shebangfix
USE_PYTHON=	autoplist cython3 pep517 pytest

TEST_ARGS=	sklearn
TEST_WRKSRC=	${STAGEDIR}${PYTHON_SITELIBDIR}

SHEBANG_FILES=	sklearn/_build_utils/version.py

post-install: # strip binaries
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/sklearn/*.cpython*.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/sklearn/*/*.cpython*.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/sklearn/*/*/*.cpython*.so

.include <bsd.port.mk>
