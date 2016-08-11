# $FreeBSD$

PORTNAME=	plone.app.caching
PORTVERSION=	1.1.11
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Plone UI and default rules for plone.caching/z3c.caching

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}plone.caching>=0:www/py-plone.caching \
		${PYTHON_PKGNAMEPREFIX}plone.cachepurging>=0:www/py-plone.cachepurging \
		${PYTHON_PKGNAMEPREFIX}plone.app.registry>=1.0:www/py-plone.app.registry \
		${PYTHON_PKGNAMEPREFIX}zope.browserresource>0:devel/py-zope.browserresource \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.pagetemplate>=0:devel/py-zope.pagetemplate \
		${PYTHON_PKGNAMEPREFIX}plone.memoize>=0:www/py-plone.memoize \
		${PYTHON_PKGNAMEPREFIX}plone.protect>=0:security/py-plone.protect \
		${PYTHON_PKGNAMEPREFIX}plone.registry>=1.0:www/py-plone.registry \
		${PYTHON_PKGNAMEPREFIX}Products.CMFDynamicViewFTI>=0:devel/py-Products.CMFDynamicViewFTI \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>=0:devel/py-Products.GenericSetup \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}Products.statusmessages>=0:devel/py-Products.statusmessages \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:devel/py-Acquisition \
		${PYTHON_PKGNAMEPREFIX}plone.app.z3cform>=0:www/py-plone.app.z3cform \
		${PYTHON_PKGNAMEPREFIX}z3c.form>=0:devel/py-z3c.form \
		${PYTHON_PKGNAMEPREFIX}z3c.zcmlhook>=0:devel/py-z3c.zcmlhook

NO_ARCH=	yes
USES=		python zope
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
