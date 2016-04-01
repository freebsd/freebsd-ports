# $FreeBSD$

PORTNAME=	plone.app.openid
PORTVERSION=	2.0.4
CATEGORIES=	security python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Plone OpenID authentication support

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.openid>=0:security/py-plone.openid \
		${PYTHON_PKGNAMEPREFIX}plone.portlets>=0:www/py-plone.portlets \
		${PYTHON_PKGNAMEPREFIX}plone.app.portlets>=0:www/py-plone.app.portlets \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}Products.PlonePAS>=2.0.10:security/py-Products.PlonePAS \
		${PYTHON_PKGNAMEPREFIX}Products.PluggableAuthService>=0:security/py-Products.PluggableAuthService

NO_ARCH=	yes
USES=		python zip
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
