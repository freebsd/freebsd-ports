# New ports collection makefile for:	XHTML DTD
# Date created:		10 May 2000
# Whom:			kuriyama
#
# $FreeBSD$
#

PORTNAME=	xhtml
PORTVERSION=	1.0.20020801
PORTREVISION=	4
CATEGORIES=	textproc
#MASTER_SITES=	http://www.w3.org/TR/xhtml1/
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kuriyama
DISTNAME=	xhtml1-20020801

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	W3C's XHTML DTD

RUN_DEPENDS=	${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr

USE_ZIP=	YES
NO_MTREE=	YES
NO_BUILD=	YES
WRKSRC=		${WRKDIR}/xhtml1-20020801
PLIST_SUB=	XMLCATMGR=${XMLCATMGR}
PLIST_SUB+=	DTDDIR=${DTDDIR}
PLIST_SUB+=	CATALOG_PORTS_SGML=${CATALOG_PORTS_SGML}
PLIST_SUB+=	CATALOG_PORTS_XML=${CATALOG_PORTS_XML}

INSTDIR=	${PREFIX}/share/xml
DTDDIR=		${INSTDIR}/dtd/xhtml
DTDFILES=	xhtml-lat1.ent xhtml-special.ent xhtml-symbol.ent \
		xhtml.soc xhtml1-frameset.dtd xhtml1-strict.dtd \
		xhtml1-transitional.dtd xhtml1.dcl ${WRKSRC}/catalog.xml
XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
CATALOG_PORTS_SGML=	${PREFIX}/share/sgml/catalog.ports
CATALOG_PORTS_XML=	${PREFIX}/share/xml/catalog.ports

post-patch:
	${SED} -e 's#@@DTDDIR@@#${DTDDIR}#' < ${FILESDIR}/catalog.xml > ${WRKSRC}/catalog.xml

pre-su-install:
	@[ -d ${DTDDIR}	 ] || ${MKDIR} ${DTDDIR}

do-install:
	@(cd ${WRKSRC}/DTD; ${INSTALL_DATA} ${DTDFILES} ${DTDDIR})
	${SED} -e 's|SGMLDECL.*||' ${WRKSRC}/DTD/xhtml.soc > ${DTDDIR}/xhtml-dcl.soc

post-install:
	${XMLCATMGR} -sc ${CATALOG_PORTS_SGML} add CATALOG ${DTDDIR}/xhtml-dcl.soc
	${XMLCATMGR} -c ${CATALOG_PORTS_XML} add nextCatalog ${DTDDIR}/catalog.xml

.include <bsd.port.mk>
