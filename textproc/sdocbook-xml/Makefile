# New ports collection makefile for:	"Simplified" DocBook XML DTD
# Date created:		25 December 2000
# Whom:			KIRIYAMA Kazuhiko <kiri@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdocbook-xml
PORTVERSION= 	4.1.2.5
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://www.oasis-open.org/docbook/xml/simple/4.1.2.5/
DISTNAME=	simple${PORTVERSION:S/.//g}

MAINTAINER=	des@FreeBSD.org
COMMENT=	"Simplified" DocBook XML DTD

RUN_DEPENDS=	${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}
PLIST_SUB=	XMLCATMGR=${XMLCATMGR}\
		CATALOG_PORTS_SGML=${CATALOG_PORTS_SGML}\
		CATALOG_PORTS_XML=${CATALOG_PORTS_XML}\
		XMLDIR=${SDOCBOOKDIR}\
		VERSION=${PORTVERSION}

SDOCBOOKDIR=	${PREFIX}/share/xml/${PORTNAME:S/-xml//}/${PORTVERSION}
XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
CATALOG_PORTS_SGML=	${PREFIX}/share/sgml/catalog.ports
CATALOG_PORTS_XML=	${PREFIX}/share/xml/catalog.ports

FILES=		sdbcent.mod sdbhier.mod sdbpool.mod sdocbook-custom.dtd \
		sdocbook.css sdocbook.dtd sdocbookref-custom.dtd \
		sdocbookref.dtd sinclist.mod

do-extract:
	${MKDIR} ${WRKDIR}; \
	(cd ${WRKDIR} && unzip -oq ${DISTDIR}/${DISTFILES})

post-patch:
	${SED} -e 's#@@DTDDIR@@#${SDOCBOOKDIR}#' < ${FILESDIR}/catalog.xml > ${WRKSRC}/catalog.xml

do-install:
	${MKDIR} ${SDOCBOOKDIR}
.for i in ${FILES}
	${INSTALL_DATA} $(WRKDIR)/${i} ${SDOCBOOKDIR}
.endfor
	${INSTALL_DATA} ${FILESDIR}/catalog ${SDOCBOOKDIR}
	${INSTALL_DATA} ${WRKDIR}/catalog.xml ${SDOCBOOKDIR}

post-install:
	${XMLCATMGR} -sc ${CATALOG_PORTS_SGML} add CATALOG ${SDOCBOOKDIR}/catalog
	${XMLCATMGR} -c ${CATALOG_PORTS_XML} add nextCatalog ${SDOCBOOKDIR}/catalog.xml

.include <bsd.port.mk>
