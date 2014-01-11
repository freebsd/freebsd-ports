# Created by: kutulu
# $FreeBSD$

PORTNAME=	docbook
PORTVERSION=	4.2
CATEGORIES=	textproc
MASTER_SITES=	http://www.docbook.org/sgml/4.2/
PKGNAMESUFFIX=	-420

MAINTAINER=	ports@FreeBSD.org
COMMENT=	V4.2 of the DocBook DTD, designed for technical documentation

EXTRACT_DEPENDS=${UNZIP_CMD}:${PORTSDIR}/archivers/unzip
RUN_DEPENDS=	${ISOCAT}:${PORTSDIR}/textproc/iso8879 \
		${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr

USE_ZIP=	yes
NO_MTREE=	yes
NO_BUILD=	yes
PLIST_SUB=	DTD_NAME=${PORTNAME}
PLIST_SUB+=	DTD_VERSION=${PORTVERSION}
PLIST_SUB+=	XMLCATMGR=${XMLCATMGR}
PLIST_SUB+=	CATALOG_PORTS_SGML=${CATALOG_PORTS_SGML}
SUB_FILES+=	catalog
SUB_LIST+=	ISOCAT=${ISOCAT}

INSTDIR=	${STAGEDIR}${PREFIX}/share/sgml/docbook
ISOCAT=		${LOCALBASE}/share/sgml/iso8879/catalog
XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
CATALOG_PORTS_SGML=	${LOCALBASE}/share/sgml/catalog.ports

do-extract:
	${MKDIR} ${WRKSRC}
	${UNZIP_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DISTFILES} \
		-d ${WRKSRC}

do-install:
	@${MKDIR} ${INSTDIR}/${PORTVERSION}
	${INSTALL_DATA} ${WRKSRC}/* ${WRKDIR}/catalog \
		${INSTDIR}/${PORTVERSION}/

.include <bsd.port.mk>
