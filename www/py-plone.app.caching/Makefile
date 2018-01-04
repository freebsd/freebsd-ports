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

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.caching>=0:www/py-plone.caching@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.cachepurging>=0:www/py-plone.cachepurging@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.registry>=1.0:www/py-plone.app.registry@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.browserresource>0:devel/py-zope.browserresource@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:devel/py-zope.publisher@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.pagetemplate>=0:devel/py-zope.pagetemplate@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.memoize>=0:www/py-plone.memoize@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.protect>=0:security/py-plone.protect@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.registry>=1.0:www/py-plone.registry@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFDynamicViewFTI>=0:devel/py-Products.CMFDynamicViewFTI@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>=0:devel/py-Products.GenericSetup@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:devel/py-Products.CMFCore@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.statusmessages>=0:devel/py-Products.statusmessages@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:devel/py-Acquisition@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.z3cform>=0:www/py-plone.app.z3cform@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}z3c.form>=0:devel/py-z3c.form@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}z3c.zcmlhook>=0:devel/py-z3c.zcmlhook@${FLAVOR}

NO_ARCH=	yes
USES=		python:2.7 zope
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
