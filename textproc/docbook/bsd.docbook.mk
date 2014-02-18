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

XMLCATMGR=	bin/xmlcatmgr
SGMLCAT=	share/sgml/catalog.ports
ISOCAT=		share/sgml/iso8879/catalog
XMLCAT=		share/xml/catalog.ports
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}/${PORTVERSION}
DTD_SUBDIR?=	${PORTNAME}
DTD_VERSION?=	${PORTVERSION}
DTDDIR?=	share/${XML_SGML}/${DTD_SUBDIR}/${DTD_VERSION}/dtd
PLIST_SUB+=	XMLCATMGR=${XMLCATMGR} SGMLCAT=${SGMLCAT} XMLCAT=${XMLCAT} \
		DTDDIR=${DTDDIR}

.if !defined(PORTDOCS)
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
SUB_FILES=	catalog
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${DTDDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${DTDDIR}
.if !defined(HAS_CATALOG_FILE) && !defined(HAS_MANUAL_CATALOG_FILE)
	${INSTALL_DATA} ${WRKDIR}/catalog ${STAGEDIR}${PREFIX}/${DTDDIR}
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.if defined(PORTDOCS) && !defined(MANUAL_DOCS)
.  for f in ${PORTDOCS}
	${MV} ${STAGEDIR}${PREFIX}/${DTDDIR}/${f} ${STAGEDIR}${DOCSDIR}
.  endfor
.endif
	@${ECHO_CMD} "@dirrm share/${XML_SGML}/${DTD_SUBDIR}/${DTD_VERSION}" >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrmtry share/${XML_SGML}/${DTD_SUBDIR}" >> ${TMPPLIST}
.if defined(PORTDOCS)
	@${ECHO_CMD} "@dirrmtry share/doc/${PORTNAME}" >> ${TMPPLIST}
.endif

