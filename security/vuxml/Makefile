# New ports collection makefile for:	vuxml
# Date created:		2004/02/12
# Whom:			nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	vuxml
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	security textproc
MASTER_SITES=	http://www.vuxml.org/dtd/vuxml-1/
DISTFILES=	vuxml-10.dtd  vuxml-model-10.mod \
		vuxml-11.dtd  vuxml-model-11.mod \
		xml1.dcl catalog catalog.xml
DIST_SUBDIR=	vuxml

MAINTAINER=	secteam@FreeBSD.org
COMMENT=	Vulnerability and eXposure Markup Language DTD

RUN_DEPENDS=	${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr \
		${LOCALBASE}/share/xml/dtd/xhtml-modularization/VERSION:${PORTSDIR}/textproc/xhtml-modularization \
		${LOCALBASE}/share/xml/dtd/xhtml-basic/xhtml-basic10.dtd:${PORTSDIR}/textproc/xhtml-basic

NO_MTREE=	YES
NO_BUILD=	YES
WRKSRC=		${WRKDIR}

dir_DTD=	share/xml/dtd/vuxml

XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
SGMLCAT=	${PREFIX}/share/sgml/catalog.ports
XMLCAT=		${PREFIX}/share/xml/catalog.ports

XMLCAT_ADD=	${XMLCATMGR} -c ${XMLCAT} add nextCatalog \
		    ${PREFIX}/${dir_DTD}/catalog.xml
XMLCAT_RM=	${XMLCATMGR} -c ${XMLCAT} remove nextCatalog \
		    ${PREFIX}/${dir_DTD}/catalog.xml
SGMLCAT_ADD=	${XMLCATMGR} -sc ${SGMLCAT} add CATALOG \
		    ${PREFIX}/${dir_DTD}/catalog
SGMLCAT_RM=	${XMLCATMGR} -sc ${SGMLCAT} remove CATALOG \
		    ${PREFIX}/${dir_DTD}/catalog

CATALOG_PORTS_SGML=	${PREFIX}/share/sgml/catalog.ports
CATALOG_PORTS_XML=	${PREFIX}/share/xml/catalog.ports

PLIST=		${WRKDIR}/PLIST

VUXML_FILE?=	${PKGDIR}/vuln.xml

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
.for f in ${DISTFILES}
	${CP} ${_DISTDIR}/${f} ${WRKDIR}/${f}
.endfor

pre-install:
	${CP} ${PKGDIR}/pkg-plist ${PLIST}
	${ECHO} "@unexec ${XMLCAT_RM}" >> ${PLIST}
	${ECHO} "@exec ${XMLCAT_ADD}" >> ${PLIST}
	${ECHO} "@unexec ${SGMLCAT_RM}" >> ${PLIST}
	${ECHO} "@exec ${SGMLCAT_ADD}" >> ${PLIST}
	${ECHO} "@dirrm ${dir_DTD}" >> ${PLIST}
	${ECHO} '@unexec rmdir %D share/xml/dtd 2>/dev/null || true' >> \
	    ${PLIST}

do-install:
	@[ -d ${PREFIX}/${dir_DTD} ] || \
	    ${MKDIR} ${PREFIX}/${dir_DTD}
.for f in ${DISTFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${dir_DTD}/${f}
.endfor
	${XMLCAT_ADD}
	${SGMLCAT_ADD}

validate:
	@${SH} ${FILESDIR}/validate.sh "${VUXML_FILE}"

tidy:
	${SH} ${FILESDIR}/tidy.sh "${FILESDIR}/tidy.xsl" "${VUXML_FILE}" > "${VUXML_FILE}.tidy"

newentry:
	@${SH} ${FILESDIR}/newentry.sh "${VUXML_FILE}"

.include <bsd.port.mk>
