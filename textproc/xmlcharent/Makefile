# New ports collection makefile for:   xmlcharent # Date created:                31 January 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	xmlcharent
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.oasis-open.org/docbook/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML character entities

RUN_DEPENDS=	${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_SUB=	XMLCATMGR=${XMLCATMGR}
PLIST_SUB+=	XMLDIR=${XMLDIR}
PLIST_SUB+=	CATALOG_PORTS_SGML=${CATALOG_PORTS_SGML}
PLIST_SUB+=	CATALOG_PORTS_XML=${CATALOG_PORTS_XML}

XMLDIR=		${PREFIX}/share/xml/${PORTNAME}
XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
CATALOG_PORTS_SGML=	${PREFIX}/share/sgml/catalog.ports
CATALOG_PORTS_XML=	${PREFIX}/share/xml/catalog.ports

post-patch:
	${SED} -e 's#@@XMLDIR@@#${XMLDIR}#' < ${FILESDIR}/catalog.xml > ${WRKSRC}/catalog.xml

do-install:
	${MKDIR} ${XMLDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ent\
		${FILESDIR}/catalog ${WRKSRC}/catalog.xml ${XMLDIR}
	${XMLCATMGR} -sc ${CATALOG_PORTS_SGML} add CATALOG ${XMLDIR}/catalog
	${XMLCATMGR} -c ${CATALOG_PORTS_XML} add nextCatalog ${XMLDIR}/catalog.xml

.include <bsd.port.mk>
