# $FreeBSD$
#

# Make sure we cannot define both DRUPAL4_MODULE and DRUPAL5_MODULE
.if defined(DRUPAL4_MODULE) && defined(DRUPAL5_MODULE)
BROKEN=		cannot define both DRUPAL4_MODULE and DRUPAL5_MODULE in module Makefile
.endif

# Make sure DRUPAL_MODULE is defined.  If no DRUPAL*_module defined, then define DRUPAL4_MODULE
.if defined(DRUPAL4_MODULE) || defined(DRUPAL5_MODULE)
DRUPAL_MODULE?=	yes
.else
.if defined(DRUPAL_MODULE)
DRUPAL4_MODULE=	yes
.endif
.endif

# Make sure DRUPAL_PORT is defined.  If no DRUPAL*_module defined, then define DRUPAL4_PORT
.if defined(DRUPAL4_PORT) || defined(DRUPAL5_PORT)
DRUPAL_PORT?=	yes
.else
.if defined(DRUPAL_PORT)
DRUPAL4_PORT=	yes
.endif
.endif

.if defined(DRUPAL5_MODULE) || defined(DRUPAL5_PORT)
DRUPAL_BASE?=	www/drupal5
.else
DRUPAL_BASE?=	www/drupal4
.endif
DRUPAL_DIR=	${PREFIX}/${DRUPAL_BASE}
DRUPAL_DOCSDIR?=	${PREFIX}/${DRUPAL_BASE}/doc
PLIST_SUB+=	DRUPAL_BASE=${DRUPAL_BASE}
SUB_LIST+=	DRUPAL_BASE=${DRUPAL_BASE} DRUPAL_DIR=${DRUPAL_DIR}

.if defined(DRUPAL_PORT)
DOCSDIR?=	${DRUPAL_DOCSDIR}
.endif

.if defined(DRUPAL_MODULE)

.if defined(DRUPAL4_MODULE)
PKGNAMEPREFIX=	drupal4-
DRUPAL_VERSION?=	4.7.0
.if defined(DRUPAL_MODSUBDIR)
DRUPAL_MODDIR?= ${DRUPAL_BASE}/modules/${DRUPAL_MODSUBDIR}
.else 
DRUPAL_MODDIR?= ${DRUPAL_BASE}/modules
.endif
.endif

.if defined(DRUPAL5_MODULE)
PKGNAMEPREFIX=	drupal5-
DRUPAL_VERSION?=	5.0
.if defined(DRUPAL_MODSUBDIR)
DRUPAL_MODDIR?= ${DRUPAL_BASE}/sites/all/modules/${DRUPAL_MODSUBDIR}
.else
DRUPAL_MODDIR?= ${DRUPAL_BASE}/sites/all/modules/${PORTNAME}
.endif
.endif

DOCSDIR?=	${DRUPAL_DOCSDIR}/${PORTNAME}

MASTER_SITES?=	http://ftp.osuosl.org/pub/drupal/files/projects/
DIST_SUBDIR=	drupal

NO_BUILD?=	yes

WRKSRC?=	${WRKDIR}/${PORTNAME}
RUN_DEPENDS+=	${LOCALBASE}/${DRUPAL_BASE}/index.php:${PORTSDIR}/${DRUPAL_BASE}

.if defined(MODULE_CONF_FILES)
SUB_FILES=	pkg-install
SUB_LIST+=	CONF_FILES="${MODULE_CONF_FILES:C|^|${DRUPAL_MODDIR}/|}" \
		CONF_DIRS="${MODULE_CONF_DIRS:C|^|${DRUPAL_MODDIR}/|}"
# XXX: where?
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${PKGINSTALL}
.endif

PLIST_SUB+=	DRUPAL_MODDIR=${DRUPAL_MODDIR}
PLIST_FILES+=	${MODULE_FILES:C|^|%%DRUPAL_MODDIR%%/|}
PLIST_FILES+=	${MODULE_CONF_FILES:C|^|%%DRUPAL_MODDIR%%/|:C|$|-dist|}
PLIST_DIRS+=	${MODULE_DIRS:C|^|%%DRUPAL_MODDIR%%/|}
.if defined(DRUPAL5_MODULE)
PLIST_DIRS+=	${DRUPAL_MODDIR}
.endif
.if defined(DRUPAL_MODSUBDIR)
PLIST_DIRS+=	${DRUPAL_MODDIR}
.endif
.if !defined(NOPORTDOCS)
PLIST_FILES+=	${DOC_FILES:C|^|%%DOCSDIR%%/|}
PLIST_DIRS+=	${DOC_DIRS:C|^|%%DOCSDIR%%/|}
PLIST_DIRS+=	%%DOCSDIR%%
.endif

do-install:
.if defined(DRUPAL5_MODULE)
	@${MKDIR} ${DRUPAL_MODDIR:C|^|${PREFIX}/|}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${DRUPAL_MODDIR:C|^|${PREFIX}/|}
.endif
.if defined(MODULE_CONF_DIRS)
	@${MKDIR} ${MODULE_CONF_DIRS:C|^|${PREFIX}/${DRUPAL_MODDIR}/|}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${MODULE_CONF_DIRS:C|^|${PREFIX}/${DRUPAL_MODDIR}/|}
.endif
.if defined(MODULE_DIRS)
	@${MKDIR} ${MODULE_DIRS:C|^|${PREFIX}/${DRUPAL_MODDIR}/|}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${MODULE_DIRS:C|^|${PREFIX}/${DRUPAL_MODDIR}/|}
.endif
.for f in ${MODULE_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${DRUPAL_MODDIR}/${f}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${DRUPAL_MODDIR}/${f}
.endfor
.for f in ${MODULE_CONF_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${DRUPAL_MODDIR}/${f}-dist
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${DRUPAL_MODDIR}/${f}-dist
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
