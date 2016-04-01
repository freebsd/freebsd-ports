# $FreeBSD$

PORTNAME=	wicked
PORTVERSION=	1.1.12
CATEGORIES=	textproc python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Compact syntax for doing wiki-like content linking and creation

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.container>=0:devel/py-zope.container \
		${PYTHON_PKGNAMEPREFIX}zope.lifecycleevent>=0:devel/py-zope.lifecycleevent \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>=0:devel/py-zope.traversing

USES=		python zip
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
