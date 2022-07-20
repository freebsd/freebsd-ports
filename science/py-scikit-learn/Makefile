PORTNAME=	scikit-learn
DISTVERSION=	1.1.1
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Machine learning algorithms for python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.1.0:science/py-scipy@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		fortran python:3.7+ localbase
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
