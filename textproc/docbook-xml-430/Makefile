# New ports collection makefile for:	docbook-xml-430
# Date created:		02 Apr 2004
# Whom:			hrs
#
# $FreeBSD$

PORTNAME=	docbook-xml
PORTVERSION=	4.3
CATEGORIES=	textproc
MASTER_SITES=	http://www.oasis-open.org/docbook/xml/${PORTVERSION}/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	DocBook/XML DTD V4.3, designed for technical documentation

RUN_DEPENDS=	${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
LATEST_LINK=	${PORTNAME}-430
PLIST=		${WRKSRC}/pkg-plist

XMLCATBASE=	share/xml
DTD_NAME=	${PORTNAME:S,-xml,,}
DTD_VERSION=	${PORTVERSION}

XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
CATALOG_PORTS_XML=	${PREFIX}/${XMLCATBASE}/catalog.ports
REGIST_CAT_FLAGS_XML=	-c ${CATALOG_PORTS_XML} \
			add nextCatalog ${DTD_NAME}/${DTD_VERSION}/catalog.xml
UNREGIST_CAT_FLAGS_XML=	-c ${CATALOG_PORTS_XML} \
			remove nextCatalog ${DTD_NAME}/${DTD_VERSION}/catalog.xml

DOC_FILES=	ChangeLog README
DTDDIR=		${XMLCATBASE}/${DTD_NAME}/${DTD_VERSION}
DTD_FILES=	calstblx.dtd catalog.xml dbcentx.mod dbgenent.mod \
		dbhierx.mod dbnotnx.mod dbpoolx.mod docbook.cat docbookx.dtd \
		htmltblx.mod soextblx.dtd
ENTDIR=		${DTDDIR}/ent
ENT_FILES=	iso-amsa.ent iso-amsb.ent iso-amsc.ent iso-amsn.ent \
		iso-amso.ent iso-amsr.ent iso-box.ent iso-cyr1.ent \
		iso-cyr2.ent iso-dia.ent iso-grk1.ent iso-grk2.ent \
		iso-grk3.ent iso-grk4.ent iso-lat1.ent iso-lat2.ent \
		iso-num.ent iso-pub.ent iso-tech.ent

pre-install:
	(for F in ${ENT_FILES}; do \
			${ECHO_CMD} "${ENTDIR}/$${F}"; \
		done;\
	${ECHO_CMD} "@dirrm ${ENTDIR}"; ) > ${PLIST}
	(for F in ${DTD_FILES}; do \
			${ECHO_CMD} "${DTDDIR}/$${F}"; \
		done;\
	${ECHO_CMD} "@dirrm ${DTDDIR}";\
	${ECHO_CMD} "@unexec rmdir %D/${XMLCATBASE}/${DTD_NAME} 2> /dev/null || true"; ) >> ${PLIST}
.if !defined(NOPORTDOCS)
	(for F in ${DOC_FILES}; do \
			${ECHO_CMD} "${DOCSDIR:S,^${PREFIX}/,,}/$${F}"; \
		done;\
	${ECHO_CMD} "@dirrm ${DOCSDIR:S,^${PREFIX}/,,}" ) >> ${PLIST}
.endif
	${ECHO_CMD} "@exec ${XMLCATMGR} ${REGIST_CAT_FLAGS_XML}" >> ${PLIST}
	${ECHO_CMD} "@unexec ${XMLCATMGR} ${UNREGIST_CAT_FLAGS_XML}" >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/${DTDDIR}
	${INSTALL_DATA} ${DTD_FILES:S,^,${WRKSRC}/,} ${PREFIX}/${DTDDIR}
	${MKDIR} ${PREFIX}/${ENTDIR}
	${INSTALL_DATA} ${ENT_FILES:S,^,${WRKSRC}/ent/,} ${PREFIX}/${ENTDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

post-install:
	-${XMLCATMGR} ${REGIST_CAT_FLAGS_XML}

.include <bsd.port.mk>
