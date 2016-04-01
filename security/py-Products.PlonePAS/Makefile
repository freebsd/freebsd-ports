# $FreeBSD$

PORTNAME=	Products.PlonePAS
PORTVERSION=	4.1.6
CATEGORIES=	security python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Adapts the PluggableAuthService for use by Plone

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.memoize>=0:www/py-plone.memoize \
		${PYTHON_PKGNAMEPREFIX}plone.session>=0:security/py-plone.session \
		${PYTHON_PKGNAMEPREFIX}plone.i18n>0:www/py-plone.i18n \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}Products.CMFDefault>0:devel/py-Products.CMFDefault \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>=0:devel/py-Products.GenericSetup \
		${PYTHON_PKGNAMEPREFIX}Products.PluggableAuthService>=0:security/py-Products.PluggableAuthService

NO_ARCH=	yes
USES=		python:2.7 zope
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
