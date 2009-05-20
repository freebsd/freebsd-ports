# New ports collection makefile for:	docbook-440
# Date created:		12 Jul 2008
# Whom:			Gabor Kovesdan <gabor@kovesdan.org>
#
# $FreeBSD$

PORTNAME=	docbook
PORTVERSION=	4.4
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://www.oasis-open.org/docbook/sgml/${PORTVERSION}/

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	DocBook/SGML DTD V4.4, designed for technical documentation

RUN_DEPENDS=	${LOCALBASE}/${ISOCAT}:${PORTSDIR}/textproc/iso8879 \
		${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
LATEST_LINK=	${PORTNAME}-450
PLIST=		${WRKSRC}/pkg-plist

SGMLCATBASE=	share/sgml
DTD_NAME=	${PORTNAME}
DTD_VERSION=	${PORTVERSION}
ISOCAT=		${SGMLCATBASE}/iso8879/catalog

XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
CATALOG_PORTS_SGML=	${PREFIX}/${SGMLCATBASE}/catalog.ports
REGIST_CAT_FLAGS_SGML=	-sc ${CATALOG_PORTS_SGML} \
			add CATALOG ${DTD_NAME}/${DTD_VERSION}/catalog
UNREGIST_CAT_FLAGS_SGML=	-sc ${CATALOG_PORTS_SGML} \
			remove CATALOG ${DTD_NAME}/${DTD_VERSION}/catalog

DOC_FILES=	ChangeLog README
DTDDIR=		${SGMLCATBASE}/${DTD_NAME}/${DTD_VERSION}
DTD_FILES=	calstblx.dtd catalog.xml dbcentx.mod dbgenent.mod \
		dbhierx.mod dbnotnx.mod dbpoolx.mod docbook.cat docbook.dcl \
		docbook.dtd docbookx.dtd htmltblx.mod soextblx.dtd catalog
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}/${PORTVERSION}

LATEST_LINK=	docbook-440

post-extract:
	${CP} ${WRKSRC}/docbook.cat ${WRKSRC}/catalog

post-patch:
	${ECHO_CMD} 'CATALOG "${LOCALBASE}/${ISOCAT}"' >> ${WRKSRC}/catalog

pre-install:
	(for F in ${DTD_FILES}; do \
			${ECHO_CMD} "${DTDDIR}/$${F}"; \
		done;\
	${ECHO_CMD} "@dirrm ${DTDDIR}";\
	${ECHO_CMD} "@dirrmtry ${SGMLCATBASE}/${DTD_NAME}"; ) > ${PLIST}
.if !defined(NOPORTDOCS)
	(for F in ${DOC_FILES}; do \
			${ECHO_CMD} "${DOCSDIR:S,^${PREFIX}/,,}/$${F}"; \
		done;\
	${ECHO_CMD} "@dirrm ${DOCSDIR:S,^${PREFIX}/,,}" ) >> ${PLIST}
	${ECHO_CMD} "@dirrm ${DOCSDIR:S!^${PREFIX}/!!:S!${PORTVERSION}!!}" >> ${PLIST}
	${ECHO_CMD} "@dirrmtry ${DOCSDIR:S!^${PREFIX}/!!:S!${PORTNAME}${PORTVERSION}!!}" >> ${PLIST}
.endif
	${ECHO_CMD} "@exec ${XMLCATMGR} ${REGIST_CAT_FLAGS_SGML}" >> ${PLIST}
	${ECHO_CMD} "@unexec ${XMLCATMGR} ${UNREGIST_CAT_FLAGS_SGML}" >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/${DTDDIR}
	${INSTALL_DATA} ${DTD_FILES:S,^,${WRKSRC}/,} ${PREFIX}/${DTDDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

post-install:
	-${XMLCATMGR} ${REGIST_CAT_FLAGS_SGML}

.include <bsd.port.mk>
