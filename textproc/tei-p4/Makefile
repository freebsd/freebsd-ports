# New ports collection makefile for:	tei-p4
# Date created:				29 April 2002
# Whom:					Henrik Motakef
#
# $FreeBSD$
#

PORTNAME=	tei
PORTVERSION=	p4
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.tei-c.org/P4X/DTD/
DISTNAME=	dtd

MAINTAINER=	henrik.motakef@web.de
COMMENT=	DTD of the Text Encoding Initiative

RUN_DEPENDS=	${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_SUB=	XMLCATMGR=${XMLCATMGR} \
		DTDDIR=${DTDDIR} \
		CATALOG_PORTS_SGML=${CATALOG_PORTS_SGML}

DTD=		dtd.zip
SGMLDIR=	${PREFIX}/share/sgml
INSTDIR=	${SGMLDIR}/${PORTNAME}/${PORTVERSION}
DTDDIR=		${PORTNAME}/${PORTVERSION}
XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
CATALOG_PORTS_SGML=	${PREFIX}/share/sgml/catalog.ports

pre-install:
	@[ -d ${INSTDIR} ] || ${MKDIR} ${INSTDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.dtd ${INSTDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ent ${INSTDIR}
	${INSTALL_DATA} ${WRKSRC}/*.dec ${INSTDIR}
	${INSTALL_DATA} ${WRKSRC}/teicatalog.xml ${INSTDIR}
	${SED} -e "s!&DTDpath;!!" ${WRKSRC}/catalog.tei > ${INSTDIR}/catalog

post-install:
	${XMLCATMGR} -sc ${CATALOG_PORTS_SGML} add CATALOG ${DTDDIR}/catalog 

.include <bsd.port.mk>
