# New ports collection makefile for:	tei-lite
# Date created:				19 May 2002
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$
#

PORTNAME=	tei
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.tei-c.org/Lite/DTD/
PKGNAMESUFFIX=	-lite
DISTFILES=	teilite.dtd teilite.tag
EXTRACT_ONLY=	# Empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SGML version of the TEI-Lite DTD

RUN_DEPENDS=	${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr

NO_BUILD=	yes
PLIST_SUB=	XMLCATMGR=${XMLCATMGR}
PLIST_SUB+=	DTDDIR=${DTDDIR}
PLIST_SUB+=	CATALOG_PORTS_SGML=${CATALOG_PORTS_SGML}
INSTDIR=	${PREFIX}/share/sgml/tei/lite
DTDDIR=		${PORTNAME}/lite
XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
CATALOG_PORTS_SGML=	${PREFIX}/share/sgml/catalog.ports

do-install:
	@[ -d ${INSTDIR} ] || ${MKDIR} ${INSTDIR}
	@${INSTALL_DATA} ${DISTDIR}/teilite.dtd ${INSTDIR}
	@${INSTALL_DATA} ${DISTDIR}/teilite.tag ${INSTDIR}
	@${INSTALL_DATA} ${FILESDIR}/catalog ${INSTDIR}

post-install:
	${XMLCATMGR} -sc ${CATALOG_PORTS_SGML} add CATALOG ${DTDDIR}/catalog 

.include <bsd.port.mk>
