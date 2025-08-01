PORTNAME=	vuxml
PORTVERSION=	1.1
PORTREVISION=	6
CATEGORIES=	security textproc
MASTER_SITES=	http://www.vuxml.org/dtd/vuxml-1/
DISTFILES=	vuxml-10.dtd  vuxml-model-10.mod \
		vuxml-11.dtd  vuxml-model-11.mod \
		xml1.dcl catalog catalog.xml
DIST_SUBDIR=	vuxml

MAINTAINER=	ports-secteam@FreeBSD.org
COMMENT=	Vulnerability and eXposure Markup Language DTD
WWW=		https://vuxml.freebsd.org/

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	xmlcatmgr:textproc/xmlcatmgr \
		xsltproc:textproc/libxslt \
		${LOCALBASE}/share/xml/dtd/xhtml-modularization/VERSION:textproc/xhtml-modularization \
		${LOCALBASE}/share/xml/dtd/xhtml-basic/xhtml-basic10.dtd:textproc/xhtml-basic

USES=		python:run

NO_MTREE=	yes
NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

dir_DTD=	share/xml/dtd/vuxml

.include <bsd.port.pre.mk>

VUXML_FILE?=	${PKGDIR}/vuln.xml
VUXML_FLAT_NAME=	vuln-flat.xml
VUXML_FLAT_FILE?=	${PKGDIR}/${VUXML_FLAT_NAME}
_YEAR!=	date +%Y
VUXML_CURRENT_FILE?=	${PKGDIR}/vuln/${_YEAR}.xml

post-clean:
	@${RM} "${VUXML_FILE}.tidy"
	@${RM} "${VUXML_FLAT_FILE}"

do-extract:
	@${RM} -r ${WRKDIR}
	@${MKDIR} ${WRKDIR}
.for f in ${DISTFILES}
	${CP} ${_DISTDIR}/${f} ${WRKDIR}/${f}
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${dir_DTD}
.for f in ${DISTFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/${dir_DTD}/${f}
.endfor

do-test:
	@${MKDIR} ${WRKDIR}/test
	@${CP} -R ${.CURDIR}/vuln.xml ${.CURDIR}/vuln ${WRKDIR}/test
	@cd ${.CURDIR} && make validate PKGDIR=${WRKDIR}/test

${VUXML_FLAT_NAME}: ${VUXML_FILE} vuln/*.xml
	xmllint -noent ${.ALLSRC:[1]} > ${.TARGET}

validate: tidy
	@${SH} ${FILESDIR}/validate.sh "${VUXML_FLAT_FILE}"
	@${ECHO_MSG} Checking if tidy differs...
	@if ${DIFF} -u "${VUXML_FLAT_FILE}" "${VUXML_FILE}.tidy"; \
	then \
		${ECHO_MSG} ... seems okay; \
		${RM} "${VUXML_FILE}.tidy"; \
	else \
		return 1; \
	fi
	@${ECHO_MSG} Checking for space/tab...
	@unexpand "${VUXML_FLAT_FILE}" | ${SED} -E 's,[[:space:]]*$$,,g' > "${VUXML_FILE}.unexpanded"
	@if ${DIFF} -u "${VUXML_FLAT_FILE}" "${VUXML_FILE}.unexpanded"; \
	then \
		${ECHO_MSG} ... seems okay; \
		${RM} "${VUXML_FILE}.unexpanded"; \
	else \
		${ECHO_MSG} ... see above; \
		${ECHO_CMD} Consider using ${VUXML_FILE}.unexpanded for final commit; \
		return 1; \
	fi
	${PYTHON_CMD} ${FILESDIR}/extra-validation.py ${VUXML_FLAT_FILE}
	@${ECHO_CMD}
	@${ECHO_CMD} 'Be sure to get versioning right for PORTEPOCH and remember possible linux-* ports!'
	@${ECHO_CMD} 'Also, <gt> tags are usually wrong in ranges. Use <ge> where adequate.'
	@${ECHO_CMD}

tidy: ${VUXML_FLAT_NAME}
	@if [ ! -e ${LOCALBASE}/share/xml/dtd/vuxml/catalog.xml ]; \
	then \
		echo "Please install the VuXML port prior to running make validate/tidy."; \
		exit 1; \
	fi
	${SH} ${FILESDIR}/tidy.sh "${FILESDIR}/tidy.xsl" "${VUXML_FLAT_FILE}" > "${VUXML_FILE}.tidy"

newentry:
	@${ECHO_CMD}
	@${ECHO_CMD} 'Be sure to get versioning right for PORTEPOCH and remember possible linux-* ports!'
	@${ECHO_CMD} 'Also, <gt> tags are usually wrong in ranges. Use <ge> where adequate.'
	@${ECHO_CMD}
	@${SH} ${FILESDIR}/newentry.sh "${VUXML_CURRENT_FILE}" "CVE_ID=${CVE_ID}" "SA_ID=${SA_ID}"
	@${ECHO_CMD}
	@${ECHO_CMD} 'Be sure to get versioning right for PORTEPOCH and remember possible linux-* ports!'
	@${ECHO_CMD} 'Also, <gt> tags are usually wrong in ranges. Use <ge> where adequate.'
	@${ECHO_CMD}

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
