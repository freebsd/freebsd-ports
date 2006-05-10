# New ports collection makefile for: plone
# Date created:		09 Jan 2003
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	plone
PORTVERSION=	2.1.2
PORTREVISION=	1
CATEGORIES=	www zope
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S/$/plone\/:src/g} \
		http://plone.org/products/plonehotfix20060410/releases/1.0/:hotfix
DISTFILES=	Plone-${PORTVERSION}.tar.gz:src ${HOTFIX}.tar.gz:hotfix
DIST_SUBDIR=	zope

MAINTAINER=	filippo.natali@gmail.com
COMMENT=	A user friendly implementation of the CMF written on top of ZOPE

WRKSRC=	${WRKDIR}/Plone-${PORTVERSION}
USE_ZOPE=	yes
USE_PYTHON=	yes
HOTFIX=	PloneHotfix20060410
PLIST=	${WRKDIR}/pkg-plist

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

PLIST_SUB=	ZOPEPRODUCTDIR=${SZOPEBASEDIR}/${ZOPEPRODUCTDIR}

_MODULES=	ATContentTypes ATReferenceBrowserWidget Archetypes \
		BTreeFolder2 CMFActionIcons CMFCalendar CMFCore CMFDefault \
		CMFDynamicViewFTI CMFFormController CMFPlone \
		CMFQuickInstallerTool CMFSetup CMFTopic CMFUid DCWorkflow \
		ExtendedPathIndex ExternalEditor GroupUserFolder \
		MimetypesRegistry PlacelessTranslationService \
		PloneErrorReporting PloneLanguageTool PloneTranslations \
		PortalTransforms ResourceRegistries SecureMailHost generator \
		kupu validation

pre-everything::
.if !defined(BATCH)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you are upgrading from an earlier version"
	@${ECHO_MSG} "backup your site before proceeding."
	@${ECHO_MSG} "If you haven't done so, please press CTRL-C now."
	@${ECHO_MSG} ""
.endif

do-build:
.for m in ${_MODULES}
	-${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/$m
.endfor
	-${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKDIR}/${HOTFIX}

pre-install:
	@${RM} -f ${PLIST}
	@${TOUCH} ${PLIST}
	@for m in ${_MODULES}; do \
		cd ${WRKSRC}; \
		for i in `${FIND} $${m} -type f`; do \
			${ECHO_CMD} %%ZOPEBASEDIR%%/Products/$${i} >> ${PLIST}; \
		done; \
		for i in `${FIND} -d $${m} -type d`; do \
			${ECHO_CMD} @dirrm %%ZOPEBASEDIR%%/Products/$${i} >> ${PLIST}; \
		done; \
	done
	@cd ${WRKDIR}; \
	for i in `${FIND} ${HOTFIX} -type f`; do \
		${ECHO_CMD} %%ZOPEBASEDIR%%/Products/$${i} >> ${PLIST}; \
	done; \
	for i in `${FIND} -d ${HOTFIX} -type d`; do \
		${ECHO_CMD} @dirrm %%ZOPEBASEDIR%%/Products/$${i} >> ${PLIST}; \
	done

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}
.for m in ${_MODULES}
	@${CP} -R ${WRKSRC}/$m ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}
	@${FIND} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/$m -type f -print0 \
		| ${XARGS} -0 -- ${CHMOD} a-w
.endfor
	@${CP} -R ${WRKDIR}/${HOTFIX} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}
	@${FIND} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${HOTFIX} -type f -print0 \
		| ${XARGS} -0 -- ${CHMOD} a-w

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
