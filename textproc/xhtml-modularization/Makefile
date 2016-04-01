# Created by: nectar
# $FreeBSD$

PORTNAME=	xhtml-modularization
PORTVERSION=	1.0.${RECDATE}
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.w3.org/TR/2001/REC-${PORTNAME}-${RECDATE}/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	W3C's Modularization of XHTML DTDs and docs

RUN_DEPENDS=	${XMLCATMGR}:textproc/xmlcatmgr

USES=		tar:tgz

RECDATE=	20010410

SUB_FILES=	catalog.xml
NO_MTREE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${RECDATE}

PLIST=		${WRKDIR}/PLIST
dir_DTD=	share/xml/dtd/xhtml-modularization
dir_DOC=	share/doc/xhtml-modularization
dir_EXAMPLES=	share/examples/xhtml-modularization
dir_TEMPLATES=	share/examples/xhtml-modularization/templates

XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
SGMLCAT=	${PREFIX}/share/sgml/catalog.ports
XMLCAT=		${PREFIX}/share/xml/catalog.ports

XMLCAT_ADD=	${XMLCATMGR} -c ${XMLCAT} add nextCatalog \
		    ${PREFIX}/${dir_DTD}/catalog.xml
XMLCAT_RM=	${XMLCATMGR} -c ${XMLCAT} remove \
		    ${PREFIX}/${dir_DTD}/catalog.xml
SGMLCAT_ADD=	${XMLCATMGR} -sc ${SGMLCAT} add CATALOG \
		    ${PREFIX}/${dir_DTD}/xhtml.cat
SGMLCAT_RM=	${XMLCATMGR} -sc ${SGMLCAT} remove \
		    ${PREFIX}/${dir_DTD}/xhtml.cat

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
.for f in ${contents_EXAMPLES}
	${ECHO} ${dir_EXAMPLES}/${f} >> ${PLIST}
.endfor
.for f in ${contents_TEMPLATES}
	${ECHO} ${dir_TEMPLATES}/${f} >> ${PLIST}
.endfor
	${ECHO} ${dir_DTD}/catalog.xml >> ${PLIST}
	${ECHO} "@unexec ${XMLCAT_RM}" >> ${PLIST}
	${ECHO} "@exec ${XMLCAT_ADD}" >> ${PLIST}
	${ECHO} "@unexec ${SGMLCAT_RM}" >> ${PLIST}
	${ECHO} "@exec ${SGMLCAT_ADD}" >> ${PLIST}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${dir_DTD}
.for f in ${contents_DTD}
	${INSTALL_DATA} ${WRKSRC}/DTD/${f} ${STAGEDIR}${PREFIX}/${dir_DTD}/${f}
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/${dir_DOC}/images
.for f in ${contents_DOC}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/${dir_DOC}/${f}
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/${dir_EXAMPLES}
.for f in ${contents_EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/DTD/examples/${f} \
	    ${STAGEDIR}${PREFIX}/${dir_EXAMPLES}/${f}
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/${dir_TEMPLATES}
.for f in ${contents_TEMPLATES}
	${INSTALL_DATA} ${WRKSRC}/DTD/templates/${f} \
	    ${STAGEDIR}${PREFIX}/${dir_TEMPLATES}/${f}
.endfor
	${INSTALL_DATA} ${WRKDIR}/catalog.xml ${STAGEDIR}${PREFIX}/${dir_DTD}/catalog.xml

.include <bsd.port.mk>
