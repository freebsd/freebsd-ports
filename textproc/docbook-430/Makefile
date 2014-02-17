# Created by: hrs
# $FreeBSD$

PORTNAME=	docbook
PORTVERSION=	4.3
CATEGORIES=	textproc
MASTER_SITES=	http://www.oasis-open.org/docbook/sgml/${PORTVERSION}/
PKGNAMESUFFIX=	-430
EXTRACT_SUFX=	.zip

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	DocBook/SGML DTD V4.3, designed for technical documentation

RUN_DEPENDS=	${ISOCAT}:${PORTSDIR}/textproc/iso8879 \
		${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr

NO_BUILD=	yes
EXTRACT_AFTER_ARGS=	-s ,^,${DISTNAME}/,

DTDDIR=		${PREFIX}/share/sgml/${PORTNAME}/${PORTVERSION}
SGMLCAT=	${PREFIX}/share/sgml/catalog.ports
ISOCAT=		${PREFIX}/share/sgml/iso8879/catalog
XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr

PLIST_SUB+=	XMLCATMGR=${XMLCATMGR} SGMLCAT=${SGMLCAT} \
		DTDDIR=${DTDDIR:S/${PREFIX}\///}

PORTDOCS=	ChangeLog README
DTD_FILES=	calstblx.dtd catalog.xml dbcentx.mod dbgenent.mod \
		dbhierx.mod dbnotnx.mod dbpoolx.mod docbook.cat docbook.dcl \
		docbook.dtd docbookx.dtd htmltblx.mod soextblx.dtd catalog
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}/${PORTVERSION}

post-extract:
	${CP} ${WRKSRC}/docbook.cat ${WRKSRC}/catalog

post-patch:
	${ECHO_CMD} 'CATALOG "${LOCALBASE}/${ISOCAT}"' >> ${WRKSRC}/catalog

do-install:
	@${MKDIR} ${STAGEDIR}${DTDDIR}
	${INSTALL_DATA} ${DTD_FILES:S,^,${WRKSRC}/,} ${STAGEDIR}${DTDDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
