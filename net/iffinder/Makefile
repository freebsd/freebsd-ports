# New ports collection makefile for: iffinder
# Date created:		6 June 2007
# Whom:			dikshie@sfc.wide.ad.jp
# $FreeBSD$

PORTNAME=	iffinder
PORTVERSION=	1.37
CATEGORIES=	net
MASTER_SITES=	http://www.caida.org/tools/measurement/iffinder/download/

MAINTAINER=	dikshie@sfc.wide.ad.jp
COMMENT=	Tools for find other interfaces for same router

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/iffinder
PORTDOCS=	README

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/iffinder ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
