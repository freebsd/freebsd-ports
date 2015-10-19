# Created by: nectar@FreeBSD.org
# $FreeBSD$

PORTNAME=	vuxml
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	security textproc
MASTER_SITES=	http://www.vuxml.org/dtd/vuxml-1/
DISTFILES=	vuxml-10.dtd  vuxml-model-10.mod \
		vuxml-11.dtd  vuxml-model-11.mod \
		xml1.dcl catalog catalog.xml
DIST_SUBDIR=	vuxml

MAINTAINER=	ports-secteam@FreeBSD.org
COMMENT=	Vulnerability and eXposure Markup Language DTD

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr \
		${LOCALBASE}/share/xml/dtd/xhtml-modularization/VERSION:${PORTSDIR}/textproc/xhtml-modularization \
		${LOCALBASE}/share/xml/dtd/xhtml-basic/xhtml-basic10.dtd:${PORTSDIR}/textproc/xhtml-basic

USES=		python:run

NO_MTREE=	yes
NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}
PLIST_SUB=	XMLCAT_RM="${XMLCAT_RM}" XMLCAT_ADD="${XMLCAT_ADD}" \
		SGMLCAT_RM="${SGMLCAT_RM}" SGMLCAT_ADD="${SGMLCAT_ADD}" \
		dir_DTD="${dir_DTD}"

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

VUXML_FILE?=	${PKGDIR}/vuln.xml

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
.for f in ${DISTFILES}
	${CP} ${_DISTDIR}/${f} ${WRKDIR}/${f}
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${dir_DTD}
.for f in ${DISTFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/${dir_DTD}/${f}
.endfor

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
	${PYTHON_CMD} ${FILESDIR}/extra-validation.py ${VUXML_FILE}

tidy: vuln.xml
	@if [ ! -e ${LOCALBASE}/share/xml/dtd/vuxml/catalog.xml ]; \
	then \
		echo "Please install the VuXML port prior to running make validate/tidy."; \
		exit 1; \
	fi
	${SH} ${FILESDIR}/tidy.sh "${FILESDIR}/tidy.xsl" "${VUXML_FILE}" > "${VUXML_FILE}.tidy"

newentry:
	@${SH} ${FILESDIR}/newentry.sh "${VUXML_FILE}"

.include <bsd.port.pre.mk>

.if defined(VID) && !empty(VID)
html: work/${VID}.html
work/${VID}.html: ${FILESDIR}/html.xsl ${FILESDIR}/common.css ${VUXML_FILE}
	${MKDIR} work
	xsltproc --stringparam vid "${VID}" \
	    --output ${.TARGET} \
	    ${FILESDIR}/html.xsl ${VUXML_FILE}
	${INSTALL_DATA} ${FILESDIR}/common.css work
.endif

.include <bsd.port.post.mk>
