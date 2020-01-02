# $FreeBSD$

PORTNAME=	Products.CMFPlone
PORTVERSION=	4.3.9
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Plone Content Management System (core)

DEPRECATED=	Outdated version of plone 4.3 (legacy), uses EOLed python27
EXPIRATION_DATE=	2020-02-03

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Acquisition>=0:devel/py-Acquisition@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}DateTime>=0:devel/py-DateTime@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ExtensionClass>=0:devel/py-ExtensionClass@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.ATContentTypes>=2.1.3:devel/py-Products.ATContentTypes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.Archetypes>=0:devel/py-Products.Archetypes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFActionIcons>=0:devel/py-Products.CMFActionIcons@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCalendar>=0:devel/py-Products.CMFCalendar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:devel/py-Products.CMFCore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFDefault>=0:devel/py-Products.CMFDefault@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFDiffTool>=0:devel/py-Products.CMFDiffTool@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFDynamicViewFTI>=0:devel/py-Products.CMFDynamicViewFTI@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFEditions>=0:devel/py-Products.CMFEditions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFFormController>=0:devel/py-Products.CMFFormController@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFQuickInstallerTool>=0:devel/py-Products.CMFQuickInstallerTool@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFUid>=0:devel/py-Products.CMFUid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.DCWorkflow>=0:devel/py-Products.DCWorkflow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.ExtendedPathIndex>=0:devel/py-Products.ExtendedPathIndex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.ExternalEditor>=0:devel/py-Products.ExternalEditor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>=1.8.0:devel/py-Products.GenericSetup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.MimetypesRegistry>=0:devel/py-Products.MimetypesRegistry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.PasswordResetTool>=0:devel/py-Products.PasswordResetTool@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.PlacelessTranslationService>=0:devel/py-Products.PlacelessTranslationService@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.PloneLanguageTool>=0:devel/py-Products.PloneLanguageTool@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.PlonePAS>=0:security/py-Products.PlonePAS@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.PluggableAuthService>=0:security/py-Products.PluggableAuthService@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.PluginRegistry>=0:devel/py-Products.PluginRegistry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.PortalTransforms>=0:devel/py-Products.PortalTransforms@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.ResourceRegistries>=0:devel/py-Products.ResourceRegistries@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.TinyMCE>=0:www/py-Products.TinyMCE@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.statusmessages>=0:devel/py-Products.statusmessages@${PY_FLAVOR} \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:databases/zodb3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}archetypes.querywidget>0:devel/py-archetypes.querywidget@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}archetypes.referencebrowserwidget>=0:devel/py-archetypes.referencebrowserwidget@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}borg.localrole>=0:security/py-borg.localrole@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}five.customerize>=0:devel/py-five.customerize@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}five.localsitemanager>=0:devel/py-five.localsitemanager@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.blob>=0:www/py-plone.app.blob@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.collection>0:www/py-plone.app.collection@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.content>=0:www/py-plone.app.content@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.contentlisting>0:www/py-plone.app.contentlisting@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.contentmenu>=1.1.6:www/py-plone.app.contentmenu@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.contentrules>=0:www/py-plone.app.contentrules@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.controlpanel>=0:www/py-plone.app.controlpanel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.customerize>=0:www/py-plone.app.customerize@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.discussion>=0:www/py-plone.app.discussion@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.folder>=0:www/py-plone.app.folder@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.form>=0:www/py-plone.app.form@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.i18n>=0:www/py-plone.app.i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.jquery>0:www/py-plone.app.jquery@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.jquerytools>=0:www/py-plone.app.jquerytools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.layout>=1.1.7:www/py-plone.app.layout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.linkintegrity>=1.0.3:www/py-plone.app.linkintegrity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.locales>=0:www/py-plone.app.locales@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.portlets>=0:www/py-plone.app.portlets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.redirector>=0:www/py-plone.app.redirector@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.registry>=0:www/py-plone.app.registry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.search>0:www/py-plone.app.search@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.upgrade>=0:www/py-plone.app.upgrade@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.users>=0:www/py-plone.app.users@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.uuid>=0:www/py-plone.app.uuid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.viewletmanager>=0:www/py-plone.app.viewletmanager@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.vocabularies>=0:www/py-plone.app.vocabularies@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.workflow>=0:www/py-plone.app.workflow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.batching>0:www/py-plone.batching@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.browserlayer>=1.0rc4:www/py-plone.browserlayer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.contentrules>=0:www/py-plone.contentrules@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.fieldsets>=0:www/py-plone.fieldsets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.i18n>=0:www/py-plone.i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.indexer>=0:www/py-plone.indexer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.intelligenttext>=0:www/py-plone.intelligenttext@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.locking>=0:www/py-plone.locking@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.memoize>=0:www/py-plone.memoize@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.portlet.collection>=0:www/py-plone.portlet.collection@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.portlet.static>=0:www/py-plone.portlet.static@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.portlets>=0:www/py-plone.portlets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.protect>1.0:security/py-plone.protect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.registry>=0:www/py-plone.registry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.session>=0:security/py-plone.session@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.theme>=0:www/py-plone.theme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plonetheme.classic>=0:www/py-plonetheme.classic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plonetheme.sunburst>=0:www/py-plonetheme.sunburst@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}transaction>=0:devel/py-transaction@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}z3c.autoinclude>=0:devel/py-z3c.autoinclude@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.locales>=3.6.0:textproc/py-zope.app.locales@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.container>=0:devel/py-zope.container@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.deferredimport>=0:devel/py-zope.deferredimport@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.deprecation>=0:devel/py-zope.deprecation@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.dottedname>=0:devel/py-zope.dottedname@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.event>=0:devel/py-zope.event@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.i18n>=0:devel/py-zope.i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:textproc/py-zope.i18nmessageid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.location>=0:devel/py-zope.location@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.pagetemplate>=0:devel/py-zope.pagetemplate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:devel/py-zope.publisher@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.site>=0:devel/py-zope.site@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.structuredtext>=0:textproc/py-zope.structuredtext@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.tal>=0:textproc/py-zope.tal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.tales>=0:devel/py-zope.tales@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>=0:devel/py-zope.traversing@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
