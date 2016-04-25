# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	xhtml
PORTVERSION=	1.1.${RECDATE}
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.w3.org/TR/2010/REC-xhtml11-${RECDATE}/
PKGNAMESUFFIX=	-11
DISTNAME=	xhtml11
DIST_SUBDIR=	${DISTNAME}-${RECDATE}

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	W3C's XHTML 1.1 DTD

RUN_DEPENDS=	${XMLCATMGR}:textproc/xmlcatmgr

USES=		tar:tgz

RECDATE=	20101123

WRKSRC=		${WRKDIR}/xhtml11-${RECDATE}
NO_BUILD=	yes
PLIST_SUB+=	XMLCAT_ADD="${XMLCAT_ADD}" \
		XMLCAT_RM="${XMLCAT_RM}" \
		SGMLCAT_ADD="${SGMLCAT_ADD}" \
		SGMLCAT_RM="${SGMLCAT_RM}"

XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
SGMLCAT=	${PREFIX}/share/sgml/catalog.ports
XMLCAT=		${PREFIX}/share/xml/catalog.ports

XMLCAT_ADD=	${XMLCATMGR} -c ${XMLCAT} add nextCatalog \
		    ${PREFIX}/${DTDDIR}/catalog.xml
XMLCAT_RM=	${XMLCATMGR} -c ${XMLCAT} remove \
		    ${PREFIX}/${DTDDIR}/catalog.xml
SGMLCAT_ADD=	${XMLCATMGR} -sc ${SGMLCAT} add CATALOG \
		    ${PREFIX}/${DTDDIR}/xhtml11.cat
SGMLCAT_RM=	${XMLCATMGR} -sc ${SGMLCAT} remove \
		    ${PREFIX}/${DTDDIR}/xhtml11.cat

DTDDIR=		share/xml/${PORTNAME}/1.1/dtd
XSDDIR=		share/xml/${PORTNAME}/1.1/xsd

post-patch:
	${REINPLACE_CMD} -i '' 's|SGMLDECL "xml1.dcl"|-- SGMLDECL "xml1.dcl" --|g' \
		 ${WRKSRC}/DTD/xhtml11.cat

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${DTDDIR}
	${INSTALL_DATA} ${WRKSRC}/DTD/* ${STAGEDIR}${PREFIX}/${DTDDIR}
	${INSTALL_DATA} ${FILESDIR}/catalog.xml ${STAGEDIR}${PREFIX}/${DTDDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/${XSDDIR}
	${INSTALL_DATA} ${WRKSRC}/SCHEMA/* ${STAGEDIR}${PREFIX}/${XSDDIR}

.include <bsd.port.mk>
