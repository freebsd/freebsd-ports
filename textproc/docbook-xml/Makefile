# Created by: kuriyama
# $FreeBSD$

PORTNAME=	docbook-xml
PORTVERSION=	4.2
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.docbook.org/xml/${PORTVERSION}/ \
		http://www.oasis-open.org/committees/docbook/xml/${PORTVERSION}/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	XML version of the DocBook DTD

RUN_DEPENDS=	${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
USE_ZIP=	YES
NO_BUILD=	YES
NO_WRKSUBDIR=	YES
PLIST_SUB=	DTD_VERSION=${PORTVERSION} \
		XMLCATMGR=${XMLCATMGR}\
		DOCBOOKDIR=${DOCBOOKDIR}\
		CATALOG_PORTS_SGML=${CATALOG_PORTS_SGML} \
		CATALOG_PORTS_XML=${CATALOG_PORTS_XML}

DOCBOOKDIR=	${PREFIX}/share/xml/${PORTNAME:S/-xml//}/${PORTVERSION}
XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
CATALOG_PORTS_SGML=	${PREFIX}/share/sgml/catalog.ports
CATALOG_PORTS_XML=	${PREFIX}/share/xml/catalog.ports

pre-su-install:
	@[ -d ${STAGEDIR}${DOCBOOKDIR}/ent ] || ${MKDIR} ${STAGEDIR}${DOCBOOKDIR}/ent

do-install:
	for file in `unzip -l ${DISTDIR}/${DISTFILES}|${AWK} '/:[0-9].*[^\/]$$/{print $$4}'`; do \
		${INSTALL_DATA} ${WRKSRC}/$$file ${STAGEDIR}${DOCBOOKDIR}/$$file; \
	done

.include <bsd.port.mk>
