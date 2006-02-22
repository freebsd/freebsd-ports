# $FreeBSD$
#

DRUPAL_BASE?=	www/drupal
DRUPAL_DIR=	${PREFIX}/${DRUPAL_BASE}
DRUPAL_DOCSDIR?=	${PREFIX}/${DRUPAL_BASE}/doc
PLIST_SUB+=	DRUPAL_BASE=${DRUPAL_BASE}
SUB_LIST+=	DRUPAL_BASE=${DRUPAL_BASE} DRUPAL_DIR=${DRUPAL_DIR}

.if defined(DRUPAL_PORT)
DOCSDIR?=	${DRUPAL_DOCSDIR}
.endif

.if defined(DRUPAL_MODULE)
DRUPAL_VERSION?=	4.6.0
DRUPAL_MODDIR?=	${DRUPAL_BASE}/modules
DOCSDIR?=	${DRUPAL_DOCSDIR}/${PORTNAME}

# We have to mirror the distfiles because they are automaticly
# regenerated snapshots that change size even when nothing changes in the
# files themselves so they will generally be MASTER_SITE_LOCAL
MASTER_SITES?=	${MASTER_SITE_LOCAL}
PKGNAMEPREFIX=	drupal-
DIST_SUBDIR=	drupal

RUN_DEPENDS=	${LOCALBASE}/${DRUPAL_BASE}/index.php:${PORTSDIR}/www/drupal

NO_BUILD?=	yes

WRKSRC?=	${WRKDIR}/${PORTNAME}

.if defined(MODULE_CONF_FILES)
SUB_FILES=	pkg-install
SUB_LIST+=	CONF_FILES=${MODULE_CONF_FILES:C|^|${DRUPAL_MODDIR}/|} \
		CONF_DIRS=${MODULE_CONF_DIRS:C|^|${DRUPAL_MODDIR}/|}
# XXX: where?
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${PKGINSTALL}
.endif

PLIST_SUB+=	DRUPAL_MODDIR=${DRUPAL_MODDIR}
PLIST_FILES+=	${MODULE_FILES:C|^|%%DRUPAL_MODDIR%%/|}
PLIST_FILES+=	${MODULE_CONF_FILES:C|^|%%DRUPAL_MODDIR%%/|:C|$|-dist|}
PLIST_DIRS+=	${MODULE_DIRS:C|^|%%DRUPAL_MODDIR%%/|}
.if !defined(NOPORTDOCS)
PLIST_FILES+=	${DOC_FILES:C|^|%%DOCSDIR%%/|}
PLIST_DIRS+=	${DOC_DIRS:C|^|%%DOCSDIR%%/|}
PLIST_DIRS+=	%%DOCSDIR%%
.endif

do-install:
.if defined(MODULE_CONF_DIRS)
	@${MKDIR} ${MODULE_CONF_DIRS:C|^|${PREFIX}/${DRUPAL_MODDIR}/|}
.endif
.if defined(MODULE_DIRS)
	@${MKDIR} ${MODULE_DIRS:C|^|${PREFIX}/${DRUPAL_MODDIR}/|}
.endif
.for f in ${MODULE_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${DRUPAL_MODDIR}/${f}
.endfor
.for f in ${MODULE_CONF_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${DRUPAL_MODDIR}/${f}-dist
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} ${DOC_DIRS:C|^|${DOCSDIR}/|}
.for f in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/${f}
.endfor
.endif

.if defined(MODULE_CONF_FILES)
post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
.endif
