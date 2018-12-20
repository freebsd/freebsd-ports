# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scikit-learn
DISTVERSION=	0.20.2
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Machine learning algorithms for python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_SITELIBDIR}/scipy/version.py:science/py-scipy@${PY_FLAVOR}
LIB_DEPENDS=	libcblas.so:math/cblas
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		fortran python
USE_PYTHON=	distutils autoplist

LDFLAGS+=	-shared

POST_PLIST=	fix-plist

fix-plist: # https://github.com/scikit-learn/scikit-learn/issues/12681
	@${REINPLACE_CMD} -e "s|lib/python.*/sklearn/datasets/tests/data/openml$$||" ${TMPPLIST}

.include <bsd.port.mk>
