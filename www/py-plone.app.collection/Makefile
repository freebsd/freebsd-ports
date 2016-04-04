# $FreeBSD$

PORTNAME=	plone.app.collection
PORTVERSION=	1.0.14
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Tools for constructing navigation and site sections

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}archetypes.querywidget>=1.0.2:devel/py-archetypes.querywidget \
		${PYTHON_PKGNAMEPREFIX}plone.app.contentlisting>=0:www/py-plone.app.contentlisting \
		${PYTHON_PKGNAMEPREFIX}plone.app.form>=0:www/py-plone.app.form \
		${PYTHON_PKGNAMEPREFIX}plone.app.portlets>=0:www/py-plone.app.portlets \
		${PYTHON_PKGNAMEPREFIX}plone.app.vocabularies>=0:www/py-plone.app.vocabularies \
		${PYTHON_PKGNAMEPREFIX}plone.portlet.collection>0:www/py-plone.portlet.collection \
		${PYTHON_PKGNAMEPREFIX}plone.portlets>=0:www/py-plone.portlets \
		${PYTHON_PKGNAMEPREFIX}Products.Archetypes>=0:devel/py-Products.Archetypes \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}Products.CMFQuickInstallerTool>=0:devel/py-Products.CMFQuickInstallerTool \
		${PYTHON_PKGNAMEPREFIX}Products.validation>=0:devel/py-Products.validation \
		${PYTHON_PKGNAMEPREFIX}transaction>=0:devel/py-transaction \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:devel/py-zope.configuration \
		${PYTHON_PKGNAMEPREFIX}zope.formlib>=0:devel/py-zope.formlib \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:devel/py-zope.schema

NO_ARCH=	yes
USES=		python zope
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
