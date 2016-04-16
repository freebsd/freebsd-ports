# $FreeBSD$

PORTNAME=	plone.registry
PORTVERSION=	1.0.3
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Registry for storing application settings

LICENSE=	GPLv2

RUN_DEPENDS=	zodb${PYTHON_PKGNAMESUFFIX}>=0:databases/zodb3 \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.dottedname>=0:devel/py-zope.dottedname \
		${PYTHON_PKGNAMEPREFIX}zope.event>=0:devel/py-zope.event

NO_ARCH=	yes
USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
