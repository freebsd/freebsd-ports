# Created by: nectar@FreeBSD.org
# $FreeBSD$

PORTNAME=	vuxml
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	security textproc
MASTER_SITES=	http://www.vuxml.org/dtd/vuxml-1/
DISTFILES=	vuxml-10.dtd  vuxml-model-10.mod \
		vuxml-11.dtd  vuxml-model-11.mod \
		xml1.dcl catalog catalog.xml
DIST_SUBDIR=	vuxml

MAINTAINER=	ports-secteam@FreeBSD.org
COMMENT=	Vulnerability and eXposure Markup Language DTD

RUN_DEPENDS=	${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr \
		${LOCALBASE}/share/xml/dtd/xhtml-modularization/VERSION:${PORTSDIR}/textproc/xhtml-modularization \
		${LOCALBASE}/share/xml/dtd/xhtml-basic/xhtml-basic10.dtd:${PORTSDIR}/textproc/xhtml-basic

USE_PYTHON_RUN=	yes

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

NO_STAGE=	yes
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

validate: tidy
	@${SH} ${FILESDIR}/validate.sh "${VUXML_FILE}"
	@${ECHO_MSG} Checking if tidy differs...
	@if ${DIFF} -u "${VUXML_FILE}" "${VUXML_FILE}.tidy"; \
	then \
		${ECHO_MSG} ... seems okay; \
		${RM} "${VUXML_FILE}.tidy"; \
	else \
		return 1; \
	fi
	@${ECHO_MSG} Checking for space/tab...
	@unexpand "${VUXML_FILE}" | ${SED} -E 's,[[:space:]]*$$,,g' > "${VUXML_FILE}.unexpanded"
	@if ${DIFF} -u "${VUXML_FILE}" "${VUXML_FILE}.unexpanded"; \
	then \
		${ECHO_MSG} ... seems okay; \
		${RM} "${VUXML_FILE}.unexpanded"; \
	else \
		${ECHO_MSG} ... see above; \
		${ECHO_CMD} Consider using ${VUXML_FILE}.unexpanded for final commit; \
		return 1; \
	fi
	${PYTHON_CMD} files/extra-validation.py

tidy: vuln.xml
	@if [ ! -e ${LOCALBASE}/share/xml/dtd/vuxml/catalog.xml ]; \
	then \
		echo "Please install the VuXML port prior to running make validate/tidy."; \
		exit 1; \
	fi
	${SH} ${FILESDIR}/tidy.sh "${FILESDIR}/tidy.xsl" "${VUXML_FILE}" > "${VUXML_FILE}.tidy"

newentry:
	@${SH} ${FILESDIR}/newentry.sh "${VUXML_FILE}"

.include <bsd.port.mk>
