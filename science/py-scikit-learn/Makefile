# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scikit-learn
PORTVERSION=	0.19.1
PORTREVISION=	1
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Machine learning algorithms for python

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_SITELIBDIR}/scipy/version.py:science/py-scipy@${FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		fortran python
USE_PYTHON=	distutils autoplist

LDFLAGS+=	-shared

.include <bsd.port.mk>
