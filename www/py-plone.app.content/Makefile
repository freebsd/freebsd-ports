# $FreeBSD$

PORTNAME=	plone.app.content
PORTVERSION=	2.1.5
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Content Views for Plone

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.memoize>=0:www/py-plone.memoize \
		${PYTHON_PKGNAMEPREFIX}plone.batching>0:www/py-plone.batching \
		${PYTHON_PKGNAMEPREFIX}plone.i18n>=0:www/py-plone.i18n \
		${PYTHON_PKGNAMEPREFIX}zope.i18n>=0:devel/py-zope.i18n \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.container>=0:devel/py-zope.container \
		${PYTHON_PKGNAMEPREFIX}zope.event>=0:devel/py-zope.event \
		${PYTHON_PKGNAMEPREFIX}zope.lifecycleevent>=0:devel/py-zope.lifecycleevent \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.viewlet>=0:devel/py-zope.viewlet \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:devel/py-Acquisition \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=2.2.0:devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}Products.CMFDefault>=0:devel/py-Products.CMFDefault

NO_ARCH=	yes
USES=		python:2.7 zope zip
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
