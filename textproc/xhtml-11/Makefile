# New ports collection makefile for:	XHTML 1.1 DTD
# Date created:				18 April 2003
# Whom:					Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	xhtml
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.w3.org/TR/xhtml11/
DISTNAME=	xhtml11
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	W3C's XHTML 1.1 DTD

RUN_DEPENDS=	${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr

LATEST_LINK=	xhtml-11
WRKSRC=		${WRKDIR}/xhtml11-20010531
NO_BUILD=	yes
PLIST_SUB=	XMLCATMGR=${XMLCATMGR} DTDDIR=${DTDDIR} \
		CATALOG_PORTS_SGML=${CATALOG_PORTS_SGML}

DTDDIR=		${PREFIX}/share/xml/${PORTNAME}/${PORTVERSION}
XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
CATALOG_PORTS_SGML=	${PREFIX}/share/sgml/catalog.ports

do-install:
	${MKDIR} ${DTDDIR}
	${INSTALL_DATA} ${WRKSRC}/DTD/* ${DTDDIR}

post-install:
	${XMLCATMGR} -sc ${CATALOG_PORTS_SGML}	\
		add CATALOG ${DTDDIR}/xhtml11.cat

.include <bsd.port.mk>
