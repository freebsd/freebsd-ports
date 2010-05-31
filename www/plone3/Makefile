# New ports collection makefile for: plone
# Date created:		09 Jan 2003
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	plone3
PORTVERSION=	3.1.7
PORTREVISION=	2
CATEGORIES=	www zope
MASTER_SITES=	https://launchpad.net/plone/3.1/${PORTVERSION}/+download/
DISTNAME=	Plone-${PORTVERSION}
DIST_SUBDIR=	zope

MAINTAINER=	nakaji@jp.FreeBSD.org
COMMENT=	A user friendly implementation of the CMF written on top of ZOPE

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_SITELIBDIR}/elementtree/__init__.py:${PORTSDIR}/devel/py-elementtree

WRKSRC=	${WRKDIR}/Plone-${PORTVERSION}
USE_ZOPE=	yes
ZOPE_VERSION=	2.10
USE_PYTHON=	2.4
USE_GETTEXT=	yes
CONFLICTS=	zope-archetypes-[0-9]* \
		zope-btreefolder2-[0-9]* \
		zope-cmf-[0-9]* \
		zope-cmfactionicons-[0-9]* \
		zope-cmfformcontroller-[0-9]* \
		zope-cmfquickinstaller-[0-9]* \
		zope-generator-[0-9]* \
		zope-groupuserfolder-[0-9]* \
		zope-kupu-[0-9]* \
		zope-mimetypesregistry-[0-9]* \
		zope-placelesstranslationservice-[0-9]* \
		zope-plonelanguagetool-[0-9]* \
		zope-portaltransforms-[0-9]* \
		zope-validation-[0-9]*

PLIST_SUB=	ZOPEPRODUCTDIR=${SZOPEBASEDIR}/${ZOPEPRODUCTDIR} \
		ZOPELIBPYTHONDIR=${SZOPEBASEDIR}/lib/python

_MODULES=	ATContentTypes ATReferenceBrowserWidget AdvancedQuery \
		Archetypes CMFActionIcons CMFCalendar CMFCore CMFDefault \
		CMFDiffTool CMFDynamicViewFTI CMFEditions CMFFormController \
		CMFPlacefulWorkflow CMFPlone CMFQuickInstallerTool \
		CMFTestCase CMFTopic CMFUid DCWorkflow ExtendedPathIndex \
		ExternalEditor GenericSetup GroupUserFolder Marshall \
		MimetypesRegistry NuPlone PasswordResetTool \
		PlacelessTranslationService PloneLanguageTool \
		PlonePAS PloneTestCase PloneTranslations \
		PluggableAuthService PluginRegistry PortalTransforms \
		ResourceRegistries SecureMailHost ZopeVersionControl \
		kupu statusmessages validation

_PY_MODULES=	archetypes borg five kss plone wicked

PLONE_PODIRS=	PlacelessTranslationService/locales PloneTranslations \
		kupu/i18n kupu/mmbase/i18n

MSGFMTPY=	${PYTHON_CMD} ${PYTHONBASE}/share/${PYTHON_VERSION}/Tools/i18n/msgfmt.py

pre-everything::
.if !defined(BATCH)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you are upgrading from an earlier version"
	@${ECHO_MSG} "backup your site before proceeding."
	@${ECHO_MSG} "If you haven't done so, please press CTRL-C now."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Also, if you are fetching tarball from behind a proxy"
	@${ECHO_MSG} "server, you may fail even if environment variables"
	@${ECHO_MSG} "http_proxy and https_proxy are set correctly."
	@${ECHO_MSG} "If this happens, fetch tarball manually with wget (ftp/wget)"
	@${ECHO_MSG} "or curl (ftp/curl)."
	@${ECHO_MSG} ""
.endif

do-build:
.for m in ${_MODULES}
	-${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/Products/$m
.endfor
.for m in ${_PY_MODULES}
	-${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/lib/python/$m
.endfor
	cd ${WRKSRC}/Products; \
		${FIND} ${PLONE_PODIRS} -xdev -type f -name '*.po' -print | \
		while read f; do \
			mo=`${ECHO} $$f | ${SED} -e 's|\.po$$|.mo|'`; \
			${MSGFMTPY} -o $$mo $$f; \
		done

do-install:
	@${MKDIR} ${PREFIX}/${SZOPEBASEDIR}/${ZOPEPRODUCTDIR}
.for m in ${_MODULES}
	@${CP} -R ${WRKSRC}/Products/$m ${PREFIX}/${SZOPEBASEDIR}/${ZOPEPRODUCTDIR}
	@${FIND} ${PREFIX}/${SZOPEBASEDIR}/${ZOPEPRODUCTDIR}/$m -type f -print0 \
		| ${XARGS} -0 -- ${CHMOD} a-w
.endfor
	@${MKDIR} ${PREFIX}/${SZOPEBASEDIR}/${ZOPEPRODUCTDIR}/../lib/python
.for m in ${_PY_MODULES}
	@${CP} -R ${WRKSRC}/lib/python/$m ${PREFIX}/${SZOPEBASEDIR}/${ZOPEPRODUCTDIR}/../lib/python
	@${FIND} ${PREFIX}/${SZOPEBASEDIR}/${ZOPEPRODUCTDIR}/../lib/python/$m -type f -print0 \
		| ${XARGS} -0 -- ${CHMOD} a-w
.endfor

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.pre.mk>

.if ${PYTHON_VERSION} != ${PYTHON_DEFAULT_VERSION} && defined(PACKAGE_BUILDING)
IGNORE=	can't be built: the default Python version should be ${PYTHON_VERSION} in order to build a package in the build cluster
.endif

.include <bsd.port.post.mk>
