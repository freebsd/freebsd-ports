# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scikit-learn
DISTVERSION=	0.22
PORTREVISION=	1
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Machine learning algorithms for python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}joblib>=0.11.0:devel/py-joblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.17.0:science/py-scipy@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		fortran python:3.5+ localbase
USE_PYTHON=	distutils autoplist cython

POST_PLIST=	fix-plist

fix-plist: # https://github.com/scikit-learn/scikit-learn/issues/12681
	@${REINPLACE_CMD} -e "s|lib/python.*/sklearn/datasets/tests/data/openml$$||" ${TMPPLIST}

.include <bsd.port.mk>
