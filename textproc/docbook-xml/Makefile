# $FreeBSD$

PORTNAME=	docbook
PORTVERSION=	5.0
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${DBFILES:C,(.*):(.*),http://www.docbook.org/xml/\1/:\2,:C,:docbook-xml-([0-9]+).([0-9]+).?([0-9]*),:db\1\2\3,:C,:docbook-([0-9]+).([0-9]+).?([0-9]*),:db\1\2\3,}
PKGNAMESUFFIX=	-xml
DISTFILES=	${DBFILES:C,.*:(.*),\1.zip:\1,:C,:docbook-xml-([0-9]+).([0-9]+).?([0-9]*),:db\1\2\3,:C,:docbook-([0-9]+).([0-9]+).?([0-9]*),:db\1\2\3,}

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	DocBook XML DTD

BUILD_DEPENDS=	${LOCALBASE}/share/xml/xmlcharent/catalog.xml:textproc/xmlcharent \
		${XMLCATMGR_CMD}:textproc/xmlcatmgr
RUN_DEPENDS=	${LOCALBASE}/share/xml/xmlcharent/catalog.xml:textproc/xmlcharent \
		${XMLCATMGR_CMD}:textproc/xmlcatmgr

NO_BUILD=	yes

DBFILES=4.1.2:docbkx412 4.2:docbook-xml-4.2 4.3:docbook-xml-4.3 \
	4.4:docbook-xml-4.4 4.5:docbook-xml-4.5 5.0:docbook-5.0

XMLCATMGR=	bin/xmlcatmgr
XMLCATMGR_CMD=	${LOCALBASE}/${XMLCATMGR}
SGMLCAT=	share/sgml/catalog.ports
XMLCAT=		share/xml/catalog.ports
DBKDIR=		share/xml/docbook
DBCAT_XML=	${PREFIX}/${DBKDIR}/catalog.xml
DBCAT_SGML=	${PREFIX}/${DBKDIR}/catalog
PLIST_SUB=	XMLCATMGR=${XMLCATMGR} SGMLCAT=${SGMLCAT} \
		DBKDIR=${DBKDIR} XMLCAT=${XMLCAT}

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
.for df in ${DISTFILES:C,:.*,,}
	@cd ${WRKDIR} && ${TAR} \
		${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${df} \
		${EXTRACT_AFTER_ARGS} -s ,^,${df:R}/,
.endfor

post-extract:
	@${MV} ${WRKDIR}/docbook-5.0/docbook-5.0/* ${WRKDIR}/docbook-5.0
	@${RMDIR} ${WRKDIR}/docbook-5.0/docbook-5.0

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${DBKDIR}
	${ECHO_CMD} "CATALOG \"${LOCALBASE}/share/xml/xmlcharent/catalog\"" \
	    > ${STAGEDIR}${DBCAT_SGML}
	${XMLCATMGR_CMD} -c ${STAGEDIR}${DBCAT_XML} create
	${XMLCATMGR_CMD} -c ${STAGEDIR}${DBCAT_XML} \
	    add nextCatalog "${LOCALBASE}/share/xml/xmlcharent/catalog.xml"

.for D in ${DBFILES:C,:.*,,}
do-install-${D:S/./_/g}:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${DBKDIR}/$D
	cd ${WRKDIR}/${DBFILES:M${D}\:*:C,.*:,,} && \
	    ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${DBKDIR}/$D
	${XMLCATMGR_CMD} -c ${STAGEDIR}${DBCAT_XML} \
	    add nextCatalog "${PREFIX}/${DBKDIR}/$D/catalog.xml"
	test "$D" = 5.0 || test "$D" = 4.1.2 || \
	    ${ECHO_CMD} "CATALOG \"${PREFIX}/${DBKDIR}/$D/docbook.cat\"" \
	    >> ${STAGEDIR}${DBCAT_SGML}
do-install: do-install-${D:S/./_/g}
.endfor

post-install:
	${INSTALL_DATA} ${FILESDIR}/catalog412.xml \
	    ${STAGEDIR}${PREFIX}/${DBKDIR}/4.1.2/catalog.xml

.include <bsd.port.mk>
