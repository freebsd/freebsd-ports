# $FreeBSD$

PORTNAME=	Products.PlonePAS
PORTVERSION=	5.0.9
CATEGORIES=	security python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Adapts the PluggableAuthService for use by Plone

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.memoize>=0:www/py-plone.memoize \
		${PYTHON_PKGNAMEPREFIX}plone.session>=0:security/py-plone.session \
		${PYTHON_PKGNAMEPREFIX}plone.protect>0:security/py-plone.protect \
		${PYTHON_PKGNAMEPREFIX}plone.i18n>0:www/py-plone.i18n \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>=0:devel/py-Products.GenericSetup \
		${PYTHON_PKGNAMEPREFIX}Products.PluggableAuthService>=0:security/py-Products.PluggableAuthService \
		${PYTHON_PKGNAMEPREFIX}zope.deprecation>0:devel/py-zope.deprecation

NO_ARCH=	yes
USES=		python:2.7 zip zope
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
