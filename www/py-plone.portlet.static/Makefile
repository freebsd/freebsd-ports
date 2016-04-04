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

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.portlets>=0:www/py-plone.portlets \
		${PYTHON_PKGNAMEPREFIX}plone.app.portlets>=0:www/py-plone.app.portlets \
		${PYTHON_PKGNAMEPREFIX}plone.app.form>=0:www/py-plone.app.form \
		${PYTHON_PKGNAMEPREFIX}plone.i18n>=0:www/py-plone.i18n \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.formlib>=0:devel/py-zope.formlib \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:devel/py-zope.schema

NO_ARCH=	yes
USES=		python zip
USE_PYTHON=	autoplist distutils
#USES=		zope

.include <bsd.port.mk>
