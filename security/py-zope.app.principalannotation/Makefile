# $FreeBSD$

PORTNAME=	zope.app.principalannotation
PORTVERSION=	3.7.0
PORTREVISION=	1
CATEGORIES=	security python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Bootstrap subscriber and browser menu item for zope.principalannotation

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}transaction>=0:devel/py-transaction@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.appsetup>=3.11.0:devel/py-zope.app.appsetup@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.processlifetime>=0:devel/py-zope.processlifetime@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.principalannotation>=0:security/py-zope.principalannotation@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
