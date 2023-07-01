PORTNAME=	scikit-learn
DISTVERSION=	1.3.0
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Machine learning algorithms for python
WWW=		https://scikit-learn.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}joblib>0:devel/py-joblib@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.3.2:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}threadpoolctl>=0:devel/py-threadpoolctl@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		fortran python localbase
USE_PYTHON=	distutils autoplist cython

POST_PLIST=	fix-plist

fix-plist: # https://github.com/scikit-learn/scikit-learn/issues/12681
	@${REINPLACE_CMD} -e "s|lib/python.*/sklearn/datasets/tests/data/openml$$||" ${TMPPLIST}

post-install: # strip binaries
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/sklearn/*.cpython*.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/sklearn/*/*.cpython*.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/sklearn/*/*/*.cpython*.so

.include <bsd.port.mk>
