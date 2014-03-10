# $FreeBSD$

PORTNAME=	plone.app.collection
PORTVERSION=	1.0.11
PORTREVISION=	1
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Tools for constructing navigation and site sections

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}archetypes.querywidget>=1.0.2:${PORTSDIR}/devel/py-archetypes.querywidget \
		${PYTHON_PKGNAMEPREFIX}plone.app.contentlisting>=0:${PORTSDIR}/www/py-plone.app.contentlisting \
		${PYTHON_PKGNAMEPREFIX}plone.app.form>=0:${PORTSDIR}/www/py-plone.app.form \
		${PYTHON_PKGNAMEPREFIX}plone.app.portlets>=0:${PORTSDIR}/www/py-plone.app.portlets \
		${PYTHON_PKGNAMEPREFIX}plone.app.vocabularies>=0:${PORTSDIR}/www/py-plone.app.vocabularies \
		${PYTHON_PKGNAMEPREFIX}plone.portlet.collection>0:${PORTSDIR}/www/py-plone.portlet.collection \
		${PYTHON_PKGNAMEPREFIX}plone.portlets>=0:${PORTSDIR}/www/py-plone.portlets \
		${PYTHON_PKGNAMEPREFIX}Products.Archetypes>=0:${PORTSDIR}/devel/py-Products.Archetypes \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:${PORTSDIR}/devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}Products.CMFQuickInstallerTool>=0:${PORTSDIR}/devel/py-Products.CMFQuickInstallerTool \
		${PYTHON_PKGNAMEPREFIX}Products.validation>=0:${PORTSDIR}/devel/py-Products.validation \
		${PYTHON_PKGNAMEPREFIX}transaction>=0:${PORTSDIR}/devel/py-transaction \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:${PORTSDIR}/devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:${PORTSDIR}/devel/py-zope.configuration \
		${PYTHON_PKGNAMEPREFIX}zope.formlib>=0:${PORTSDIR}/devel/py-zope.formlib \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:${PORTSDIR}/textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:${PORTSDIR}/devel/py-zope.schema

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
USES=			zope zip

.include <bsd.port.mk>
