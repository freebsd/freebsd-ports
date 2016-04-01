# $FreeBSD$

PORTNAME=	plone.app.controlpanel
PORTVERSION=	2.3.9
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Formlib-based controlpanels for Plone

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.app.form>=0:www/py-plone.app.form \
		${PYTHON_PKGNAMEPREFIX}plone.app.vocabularies>=0:www/py-plone.app.vocabularies \
		${PYTHON_PKGNAMEPREFIX}plone.app.workflow>=0:www/py-plone.app.workflow \
		${PYTHON_PKGNAMEPREFIX}plone.fieldsets>=0:www/py-plone.fieldsets \
		${PYTHON_PKGNAMEPREFIX}plone.memoize>=0:www/py-plone.memoize \
		${PYTHON_PKGNAMEPREFIX}plone.protect>=0:security/py-plone.protect \
		${PYTHON_PKGNAMEPREFIX}plone.locking>=0:www/py-plone.locking \
		${PYTHON_PKGNAMEPREFIX}zope.annotation>=0:devel/py-zope.annotation \
		${PYTHON_PKGNAMEPREFIX}zope.cachedescriptors>=0:devel/py-zope.cachedescriptors \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.event>=0:devel/py-zope.event \
		${PYTHON_PKGNAMEPREFIX}zope.formlib>=0:devel/py-zope.formlib \
		${PYTHON_PKGNAMEPREFIX}zope.i18n>=0:devel/py-zope.i18n \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.ramcache>=0:devel/py-zope.ramcache \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>0:devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.site>=0:devel/py-zope.site \
		${PYTHON_PKGNAMEPREFIX}zope.testing>=0:devel/py-zope.testing \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:devel/py-Acquisition \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}Products.CMFDefault>=0:devel/py-Products.CMFDefault \
		${PYTHON_PKGNAMEPREFIX}Products.PlonePAS>=0:security/py-Products.PlonePAS \
		${PYTHON_PKGNAMEPREFIX}Products.PortalTransforms>=0:devel/py-Products.PortalTransforms \
		${PYTHON_PKGNAMEPREFIX}Products.statusmessages>=0:devel/py-Products.statusmessages \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:databases/zodb3

NO_ARCH=	yes
USES=		python:2.7 zip zope
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
