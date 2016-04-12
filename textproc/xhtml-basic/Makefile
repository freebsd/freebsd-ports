# Created by: nectar
# $FreeBSD$

PORTNAME=	xhtml-basic
PORTVERSION=	1.0.${RECDATE}
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.w3.org/TR/2000/REC-${PORTNAME}-${RECDATE}/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	W3C's XHTML Basic DTD

RUN_DEPENDS=	${XMLCATMGR}:textproc/xmlcatmgr \
		${LOCALBASE}/share/xml/dtd/xhtml-modularization/catalog.xml:textproc/xhtml-modularization

RECDATE=	20001219

NO_MTREE=	YES
NO_BUILD=	YES
WRKSRC=		${WRKDIR}/REC-${PORTNAME}-${RECDATE}

PLIST=		${WRKDIR}/PLIST
dir_DTD=	share/xml/dtd/xhtml-basic
dir_DOC=	share/doc/xhtml-basic

XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
SGMLCAT=	${PREFIX}/share/sgml/catalog.ports
XMLCAT=		${PREFIX}/share/xml/catalog.ports

XMLCAT_ADD=	${XMLCATMGR} -c ${XMLCAT} add nextCatalog \
		    ${PREFIX}/${dir_DTD}/catalog.xml
XMLCAT_RM=	${XMLCATMGR} -c ${XMLCAT} remove \
		    ${PREFIX}/${dir_DTD}/catalog.xml
SGMLCAT_ADD=	${XMLCATMGR} -sc ${SGMLCAT} add CATALOG \
		    ${PREFIX}/${dir_DTD}/xhtml-basic10.cat
SGMLCAT_RM=	${XMLCATMGR} -sc ${SGMLCAT} remove \
		    ${PREFIX}/${dir_DTD}/xhtml-basic10.cat

CATALOG_PORTS_SGML=	${PREFIX}/share/sgml/catalog.ports
CATALOG_PORTS_XML=	${PREFIX}/share/xml/catalog.ports

.include "${.CURDIR}/contents.inc"

# I'd much rather do this stuff in line with the actual installation
# in do-install, but the PLIST must be generated in pre-install.
pre-install:
	${CAT} /dev/null > ${PLIST}
.for f in ${contents_DTD}
	${ECHO} ${dir_DTD}/${f} >> ${PLIST}
.endfor
.for f in ${contents_DOC}
	${ECHO} ${dir_DOC}/${f} >> ${PLIST}
.endfor
	${ECHO} ${dir_DTD}/catalog.xml >> ${PLIST}
	${ECHO} "@unexec ${XMLCAT_RM}" >> ${PLIST}
	${ECHO} "@exec ${XMLCAT_ADD}" >> ${PLIST}
	${ECHO} "@unexec ${SGMLCAT_RM}" >> ${PLIST}
	${ECHO} "@exec ${SGMLCAT_ADD}" >> ${PLIST}
	${ECHO} '@unexec rmdir %D/share/xml/dtd 2>/dev/null || true' >> \
	    ${PLIST}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${dir_DTD}
	@${MKDIR} ${STAGEDIR}${PREFIX}/${dir_DOC}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${contents_DTD} \
		${STAGEDIR}${PREFIX}/${dir_DTD})
	(cd ${WRKSRC} && ${INSTALL_DATA} ${contents_DOC} \
		${STAGEDIR}${PREFIX}/${dir_DOC})
	${SED} -e "s;@@PREFIX@@;${PREFIX};g" ${FILESDIR}/catalog.xml > \
	    ${WRKDIR}/catalog.xml
	${INSTALL_DATA} ${WRKDIR}/catalog.xml \
		${STAGEDIR}${PREFIX}/${dir_DTD}/catalog.xml

.include <bsd.port.mk>
