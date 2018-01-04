# $FreeBSD$

PORTNAME=	plone.app.upgrade
PORTVERSION=	1.3.22
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Upgrade machinery for Plone

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}borg.localrole>=0:security/py-borg.localrole@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}five.localsitemanager>=0:devel/py-five.localsitemanager@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.portlets>=0:www/py-plone.portlets@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.session>=0:security/py-plone.session@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.folder>=0:www/py-plone.app.folder@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.portlets>=0:www/py-plone.app.portlets@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}transaction>=0:devel/py-transaction@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.location>=0:devel/py-zope.location@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.ramcache>=0:devel/py-zope.ramcache@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.site>=0:devel/py-zope.site@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:devel/py-Acquisition@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.Archetypes>=0:devel/py-Products.Archetypes@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.contentmigration>=0:devel/py-Products.contentmigration@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:devel/py-Products.CMFCore@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFDiffTool>=0:devel/py-Products.CMFDiffTool@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFEditions>=0:devel/py-Products.CMFEditions@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFFormController>=0:devel/py-Products.CMFFormController@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFQuickInstallerTool>=0:devel/py-Products.CMFQuickInstallerTool@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFUid>=0:devel/py-Products.CMFUid@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.DCWorkflow>=0:devel/py-Products.DCWorkflow@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>=0:devel/py-Products.GenericSetup@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.MimetypesRegistry>=0:devel/py-Products.MimetypesRegistry@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.PlonePAS>=0:security/py-Products.PlonePAS@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.PluggableAuthService>=0:security/py-Products.PluggableAuthService@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.PortalTransforms>=0:devel/py-Products.PortalTransforms@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.ResourceRegistries>=0:devel/py-Products.ResourceRegistries@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.SecureMailHost>=0:mail/py-Products.SecureMailHost@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.ZCatalog>=2.13.4:devel/py-Products.ZCatalog@${FLAVOR}

NO_ARCH=	yes
USES=		python:2.7 zope
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
