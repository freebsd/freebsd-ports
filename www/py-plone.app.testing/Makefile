# $FreeBSD$

PORTNAME=	plone.app.testing
PORTVERSION=	4.2.5
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Testing tools for Plone-the-application, based on plone.testing

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:devel/py-zope.configuration@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.dottedname>=0:devel/py-zope.dottedname@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.site>=0:devel/py-zope.site@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.testing>=0:devel/py-zope.testing@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}five.localsitemanager>=0:devel/py-five.localsitemanager@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.memoize>=0:www/py-plone.memoize@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.testing>=0:www/py-plone.testing@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>=0:devel/py-Products.GenericSetup@${FLAVOR}

NO_ARCH=	yes
USES=		python:2.7 zip zope
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
