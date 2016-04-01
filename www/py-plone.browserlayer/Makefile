# $FreeBSD$

PORTNAME=	plone.browserlayer
PORTVERSION=	2.1.6
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Browser layer management for Zope 2 applications

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>=3.9.0:devel/py-zope.traversing \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>=1.4:devel/py-Products.GenericSetup \

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils
#USES=		zope

.include <bsd.port.mk>
