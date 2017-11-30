# $FreeBSD$

PORTNAME=	plone.portlet.static
PORTVERSION=	2.0.4
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Simple static HTML portlet for Plone

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.portlets>=0:www/py-plone.portlets@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.portlets>=0:www/py-plone.app.portlets@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.form>=0:www/py-plone.app.form@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.i18n>=0:www/py-plone.i18n@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.formlib>=0:devel/py-zope.formlib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:textproc/py-zope.i18nmessageid@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:devel/py-zope.schema@${FLAVOR}

NO_ARCH=	yes
USES=		python:2.7 zip
USE_PYTHON=	autoplist distutils
#USES=		zope

.include <bsd.port.mk>
