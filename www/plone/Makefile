# New ports collection makefile for: plone
# Date created:		09 Jan 2003
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	plone
PORTVERSION=	2.0.4
CATEGORIES=	www zope
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	plone
DISTNAME=	Plone-${PORTVERSION}
DIST_SUBDIR=	zope

MAINTAINER=	filippo@widestore.net
COMMENT=	A user friendly implementation of the CMF written on top of ZOPE

RUN_DEPENDS=	${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/CMFDefault/__init__.py:${PORTSDIR}/www/zope-cmf

USE_ZOPE=	yes
USE_PYTHON=	yes

WRKSRC=		${WRKDIR}/Plone-${PORTVERSION}
PLIST=		${WRKDIR}/pkg-plist
MODULES=	CMFPlone

OPTIONS=	FORMULATOR "Install Formulator port" off \
		BTREEFOLDER2 "Install BTreeFolder2 port" off \
		CMFQUICKINSTALLER "Install CMFQuickInstallerTool port" off \
		CMFACTIONICONS "Install CMFActionIcons port" off \
		CMFFORMCONTROLLER "Install CMFFormController port" off \
		GROUPUSERFOLDER "Install GroupUserFolder port" off \
		PLTRANSSERVICE "Install PlacelessTranslationService port" off

.include <bsd.port.pre.mk>

.if defined(WITH_FORMULATOR)
RUN_DEPENDS+=	${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/Formulator/__init__.py:${PORTSDIR}/www/zope-formulator
.else
MODULES+=	Formulator
.endif

.if defined(WITH_BTREEFOLDER2)
RUN_DEPENDS+=	${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/BTreeFolder2/__init__.py:${PORTSDIR}/www/zope-btreefolder2
.else
MODULES+=	BTreeFolder2
.endif

.if defined(WITH_CMFQUICKINSTALLER)
RUN_DEPENDS+=	${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/CMFQuickInstallerTool/__init__.py:${PORTSDIR}/www/zope-cmfquickinstaller
.else
MODULES+=	CMFQuickInstallerTool
.endif

.if defined(WITH_CMFACTIONICONS)
RUN_DEPENDS+=	${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/CMFActionIcons/__init__.py:${PORTSDIR}/www/zope-cmfactionicons
.else
MODULES+=	CMFActionIcons
.endif

.if defined(WITH_CMFFORMCONTROLLER)
RUN_DEPENDS+=   ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/CMFFormController/__init__.py:${PORTSDIR}/www/zope-cmfformcontroller
.else
MODULES+=   CMFFormController
.endif

.if defined(WITH_GROUPUSERFOLDER)
RUN_DEPENDS+=	${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/GroupUserFolder/__init__.py:${PORTSDIR}/www/zope-groupuserfolder
.else
MODULES+=	GroupUserFolder
.endif

.if defined(WITH_PLTRANSSERVICE)
RUN_DEPENDS+=	${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/PlacelessTranslationService/__init__.py:${PORTSDIR}/www/zope-placelesstranslationservice
.else
MODULES+=	PlacelessTranslationService
.endif

pre-everything::
.if !defined(BATCH)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you are upgrading from an earlier version"
	@${ECHO_MSG} "backup your site before proceeding."
	@${ECHO_MSG} "If you haven't done so, please press CTRL-C now."
	@${ECHO_MSG} ""
.endif

do-build:
	-@for m in ${MODULES}; do \
		${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/$$m; \
	done

pre-install:
	@${RM} -f ${PLIST}
	@${TOUCH} ${PLIST}
	@for m in ${MODULES}; do \
		if [ ! -f ${ZOPEBASEDIR}/Products/$${m}/__init__.py ]; then \
			cd ${WRKSRC}; \
			for i in `${FIND} $${m} -type f`; do \
				${ECHO_CMD} %%ZOPEBASEDIR%%/Products/$${i} >> ${PLIST}; \
			done; \
			for i in `${FIND} -d $${m} -type d`; do \
				${ECHO_CMD} @dirrm %%ZOPEBASEDIR%%/Products/$${i} >> ${PLIST}; \
			done; \
		fi;\
	done

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}
	@cd ${WRKSRC}; \
	for m in ${MODULES}; do \
		if [ ! -f ${ZOPEBASEDIR}/Products/$${m}/__init__.py ]; then \
			${CP} -R $${m} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}; \
		fi; \
	done
#fix permissions when bundled CMFFormController
#is installed
.if !defined(WITH_CMFFORMCONTROLLER)
	@${CHMOD} -R a+rX ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/CMFFormController/
.endif

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
