# New ports collection makefile for:	tei-p3
# Date created:				19 May 2002
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$
#

PORTNAME=	tei
PORTVERSION=	p3
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.tei-c.org/Vault/GL/
DISTNAME=	teip3dtd

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DTD of the Text Encoding Initiative

RUN_DEPENDS=	${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr

LATEST_LINK=	tei-p3
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_SUB=	XMLCATMGR=${XMLCATMGR} \
		DTDDIR=${DTDDIR} \
		CATALOG_PORTS_SGML=${CATALOG_PORTS_SGML}

SGMLDIR=	${PREFIX}/share/sgml
INSTDIR=	${SGMLDIR}/${PORTNAME}/${PORTVERSION}
DTDDIR=		${PORTNAME}/${PORTVERSION}
XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
CATALOG_PORTS_SGML=	${PREFIX}/share/sgml/catalog.ports

do-install:
	@[ -d ${INSTDIR} ] || ${MKDIR} ${INSTDIR}
	@${INSTALL_MAN} ${WRKSRC}/*.dtd ${INSTDIR}
	@${INSTALL_MAN} ${WRKSRC}/*.ent ${INSTDIR}
	@${INSTALL_DATA} ${FILESDIR}/catalog ${INSTDIR}

post-install:
	${XMLCATMGR} -sc ${CATALOG_PORTS_SGML} add CATALOG ${DTDDIR}/catalog

.include <bsd.port.mk>
