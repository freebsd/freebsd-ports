# New ports collection makefile for:	tei-xlite
# Date created:				19 May 2002
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$
#

PORTNAME=	tei
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.tei-c.org/Lite/DTD/
PKGNAMESUFFIX=	-xlite
DISTNAME=	teixlite
EXTRACT_SUFX=	.dtd
EXTRACT_ONLY=	# Empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML version of the TEI-Lite DTD

RUN_DEPENDS=	${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr

BROKEN=		Size mismatch
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

NO_BUILD=	yes
PLIST_SUB=	XMLCATMGR=${XMLCATMGR}
PLIST_SUB+=	DTDDIR=${INSTDIR}
PLIST_SUB+=	CATALOG_PORTS_SGML=${CATALOG_PORTS_SGML}
PLIST_SUB+=	CATALOG_PORTS_XML=${CATALOG_PORTS_XML}
INSTDIR=	${PREFIX}/share/xml/tei/xlite
XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
CATALOG_PORTS_SGML=	${PREFIX}/share/sgml/catalog.ports
CATALOG_PORTS_XML=	${PREFIX}/share/xml/catalog.ports

do-install:
	@[ -d ${INSTDIR} ] || ${MKDIR} ${INSTDIR}
	@${INSTALL_DATA} ${DISTDIR}/teixlite.dtd ${INSTDIR}
	@${INSTALL_DATA} ${FILESDIR}/catalog ${INSTDIR}
	@${SED} -e 's!%%INSTDIR%%!${INSTDIR}!' ${FILESDIR}/catalog.xml \
	  > ${INSTDIR}/catalog.xml

post-install:
	${XMLCATMGR} -sc ${CATALOG_PORTS_SGML} add CATALOG ${INSTDIR}/catalog 
	${XMLCATMGR} -c ${CATALOG_PORTS_XML} add nextCatalog ${INSTDIR}/catalog.xml

.include <bsd.port.mk>
