# $FreeBSD$

PORTNAME=	gensim
DISTVERSION=	3.8.1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python framework for fast Vector Space Modelling

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.18.1:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.5.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}smart_open>=1.8.1:net/py-smart_open@${PY_FLAVOR}

USES=		compiler:c++11-lang python:3.5+
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
