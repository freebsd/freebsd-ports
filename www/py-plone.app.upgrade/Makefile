# $FreeBSD$

PORTNAME=	plone.app.upgrade
PORTVERSION=	1.3.4
PORTREVISION=	2
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Upgrade machinery for Plone

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}borg.localrole>=0:${PORTSDIR}/security/py-borg.localrole \
		${PYTHON_PKGNAMEPREFIX}five.localsitemanager>=0:${PORTSDIR}/devel/py-five.localsitemanager \
		${PYTHON_PKGNAMEPREFIX}plone.portlets>=0:${PORTSDIR}/www/py-plone.portlets \
		${PYTHON_PKGNAMEPREFIX}plone.session>=0:${PORTSDIR}/security/py-plone.session \
		${PYTHON_PKGNAMEPREFIX}plone.app.folder>=0:${PORTSDIR}/www/py-plone.app.folder \
		${PYTHON_PKGNAMEPREFIX}plone.app.portlets>=0:${PORTSDIR}/www/py-plone.app.portlets \
		${PYTHON_PKGNAMEPREFIX}transaction>=0:${PORTSDIR}/devel/py-transaction \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:${PORTSDIR}/devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.location>=0:${PORTSDIR}/devel/py-zope.location \
		${PYTHON_PKGNAMEPREFIX}zope.ramcache>=0:${PORTSDIR}/devel/py-zope.ramcache \
		${PYTHON_PKGNAMEPREFIX}zope.site>=0:${PORTSDIR}/devel/py-zope.site \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:${PORTSDIR}/devel/py-Acquisition \
		${PYTHON_PKGNAMEPREFIX}Products.Archetypes>=0:${PORTSDIR}/devel/py-Products.Archetypes \
		${PYTHON_PKGNAMEPREFIX}Products.contentmigration>=0:${PORTSDIR}/devel/py-Products.contentmigration \
		${PYTHON_PKGNAMEPREFIX}Products.CMFActionIcons>=0:${PORTSDIR}/devel/py-Products.CMFActionIcons \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCalendar>=0:${PORTSDIR}/devel/py-Products.CMFCalendar \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:${PORTSDIR}/devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}Products.CMFDefault>=0:${PORTSDIR}/devel/py-Products.CMFDefault \
		${PYTHON_PKGNAMEPREFIX}Products.CMFDiffTool>=0:${PORTSDIR}/devel/py-Products.CMFDiffTool \
		${PYTHON_PKGNAMEPREFIX}Products.CMFEditions>=0:${PORTSDIR}/devel/py-Products.CMFEditions \
		${PYTHON_PKGNAMEPREFIX}Products.CMFFormController>=0:${PORTSDIR}/devel/py-Products.CMFFormController \
		${PYTHON_PKGNAMEPREFIX}Products.CMFQuickInstallerTool>=0:${PORTSDIR}/devel/py-Products.CMFQuickInstallerTool \
		${PYTHON_PKGNAMEPREFIX}Products.CMFUid>=0:${PORTSDIR}/devel/py-Products.CMFUid \
		${PYTHON_PKGNAMEPREFIX}Products.DCWorkflow>=0:${PORTSDIR}/devel/py-Products.DCWorkflow \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>=0:${PORTSDIR}/devel/py-Products.GenericSetup \
		${PYTHON_PKGNAMEPREFIX}Products.MimetypesRegistry>=0:${PORTSDIR}/devel/py-Products.MimetypesRegistry \
		${PYTHON_PKGNAMEPREFIX}Products.PloneLanguageTool>=0:${PORTSDIR}/devel/py-Products.PloneLanguageTool \
		${PYTHON_PKGNAMEPREFIX}Products.PlonePAS>=0:${PORTSDIR}/security/py-Products.PlonePAS \
		${PYTHON_PKGNAMEPREFIX}Products.PluggableAuthService>=0:${PORTSDIR}/security/py-Products.PluggableAuthService \
		${PYTHON_PKGNAMEPREFIX}Products.PortalTransforms>=0:${PORTSDIR}/devel/py-Products.PortalTransforms \
		${PYTHON_PKGNAMEPREFIX}Products.ResourceRegistries>=0:${PORTSDIR}/devel/py-Products.ResourceRegistries \
		${PYTHON_PKGNAMEPREFIX}Products.SecureMailHost>=0:${PORTSDIR}/mail/py-Products.SecureMailHost \
		${PYTHON_PKGNAMEPREFIX}Products.ZCatalog>=2.13.4:${PORTSDIR}/devel/py-Products.ZCatalog

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
USES=			zope zip

.include <bsd.port.mk>
