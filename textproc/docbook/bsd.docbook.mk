# MAINTAINER: portmgr@FreeBSD.org
#
# $FreeBSD$

.ifdef XML_DTD
XML_SGML=	xml
.else
XML_SGML=	sgml
.endif

PORTNAME?=	docbook
CATEGORIES=	textproc
.ifndef MASTER_SITES
.  ifdef HAS_OASIS_MASTER_SITE
MASTER_SITES=	http://www.oasis-open.org/docbook/${XML_SGML}/${PORTVERSION}/
.  else
MASTER_SITES=	http://www.docbook.org/${XML_SGML}/${PORTVERSION}/
.  endif
.endif
EXTRACT_SUFX?=	.zip

.ifndef NO_ISOCAT
RUN_DEPENDS+=	${LOCALBASE}/${ISOCAT}:${PORTSDIR}/textproc/iso8879
.endif
RUN_DEPENDS+=	${LOCALBASE}/${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr

NO_MTREE=	yes
NO_BUILD=	yes
.ifndef NO_DISTNAME_FIX
EXTRACT_AFTER_ARGS=	-s ,^,${DISTNAME}/,
.endif

CATALOG_FILES?=	catalog
XMLCATMGR=	bin/xmlcatmgr
SGMLCAT=	share/sgml/catalog.ports
ISOCAT=		share/sgml/iso8879/catalog
XMLCAT=		share/xml/catalog.ports
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}/${PORTVERSION}
DTD_NAME?=	${PORTNAME}
DTD_VERSION?=	${PORTVERSION}
.ifndef NO_DTD_SUBDIR
DTD_SUBDIR?=	/dtd
.endif
DTDDIR?=	share/${XML_SGML}/${DTD_NAME}/${DTD_VERSION}${DTD_SUBDIR}
PLIST_SUB+=	XMLCATMGR=${XMLCATMGR} SGMLCAT=${SGMLCAT} XMLCAT=${XMLCAT} \
		DTDDIR=${DTDDIR}
SUB_LIST+=	DTDDIR=${PREFIX}/${DTDDIR}


.if !defined(PORTDOCS) && !defined(MANUAL_DOCS)
PORTDOCS=	*.txt
.endif

.if defined(PORTDOCS) && !defined(MANUAL_DOCS)
OPTIONS_DEFINE+=	DOCS
.endif

.ifdef HAS_CATALOG_FILE
post-extract:
	@${CP} ${WRKSRC}/docbook.cat ${WRKSRC}/catalog

post-patch:
	@${ECHO_CMD} 'CATALOG "${LOCALBASE}/${ISOCAT}"' >> ${WRKSRC}/catalog
	@${RM} ${WRKSRC}/catalog.orig
.elifndef HAS_MANUAL_CATALOG_FILE
SUB_FILES=	${CATALOG_FILES}
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${DTDDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${DTDDIR}
.if !defined(HAS_CATALOG_FILE) && !defined(HAS_MANUAL_CATALOG_FILE)
.  for f in ${CATALOG_FILES}
	${INSTALL_DATA} ${WRKDIR}/${f} ${STAGEDIR}${PREFIX}/${DTDDIR}
.  endfor
.endif
.if defined(PORTDOCS) && !defined(MANUAL_DOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.  for f in ${PORTDOCS}
	${MV} ${STAGEDIR}${PREFIX}/${DTDDIR}/${f} ${STAGEDIR}${DOCSDIR}
.  endfor
.endif
.ifndef NO_DTD_SUBDIR
	@${ECHO_CMD} "@dirrm share/${XML_SGML}/${DTD_NAME}/${DTD_VERSION}" >> ${TMPPLIST}
.endif
	@${ECHO_CMD} "@unexec rmdir share/${XML_SGML}/${DTD_NAME} || :" >> ${TMPPLIST}
.if defined(PORTDOCS)
	@${ECHO_CMD} "@unexec rmdir share/doc/${PORTNAME} || :" >> ${TMPPLIST}
.endif

