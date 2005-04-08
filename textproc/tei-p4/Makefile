# New ports collection makefile for:	tei-p4
# Date created:				29 April 2002
# Whom:					Henrik Motakef
#
# $FreeBSD$
#

PORTNAME=	tei
PORTVERSION=	p4
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://www.tei-c.org/P4X/DTD/
DISTNAME=	dtd

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DTD of the Text Encoding Initiative

RUN_DEPENDS=	${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr

LATEST_LINK=	tei-p4
USE_ZIP=	yes
NO_BUILD=	yes
PLIST_SUB=	XMLCATMGR=${XMLCATMGR} \
		DTDDIR=${DTDDIR} \
		CATALOG_PORTS_SGML=${CATALOG_PORTS_SGML} \
		CATALOG_PORTS_XML=${CATALOG_PORTS_XML} \
		SGMLDIR=${SGMLDIR}

DTD=		dtd.zip
SGMLDIR=	${PREFIX}/share/sgml
INSTDIR=	${SGMLDIR}/${PORTNAME}/${PORTVERSION}
DTDDIR=		${PORTNAME}/${PORTVERSION}
DTD_URL=	http://www.tei-c.org/Guidelines/DTD
XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
CATALOG_PORTS_SGML=	${PREFIX}/share/sgml/catalog.ports
CATALOG_PORTS_XML=	${PREFIX}/share/xml/catalog.ports

pre-install:
	@[ -d ${INSTDIR} ] || ${MKDIR} ${INSTDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.dtd ${INSTDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ent ${INSTDIR}
	${INSTALL_DATA} ${WRKSRC}/*.dec ${INSTDIR}
	${SED} -e "s!${DTD_URL}!file://${INSTDIR}!" ${WRKSRC}/teicatalog.xml > ${INSTDIR}/catalog.xml
	${SED} -e "s!&DTDpath;!!" ${WRKSRC}/catalog.tei > ${INSTDIR}/catalog
	${CHMOD} ${SHAREMODE} ${INSTDIR}/catalog.xml
	${CHMOD} ${SHAREMODE} ${INSTDIR}/catalog

post-install:
	${XMLCATMGR} -sc ${CATALOG_PORTS_SGML} add CATALOG ${INSTDIR}/catalog
	${XMLCATMGR} -c ${CATALOG_PORTS_XML} add nextCatalog ${INSTDIR}/catalog.xml

.include <bsd.port.mk>
