# New ports collection makefile for:	wmfuzzy
# Date created:			4 August 2002
# Whom:				Adam Weinberger <adam@vectors.cx>
#
# $FreeBSD$
#

PORTNAME=	wmfuzzy
PORTVERSION=	0.7.1
PORTREVISION=	2
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	http://www.manicai.net/comp/wmfuzzy/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A fuzzy clock WindowMaker dockapp

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_XORG=	xpm

PORTDOCS=	README
PLIST_FILES=	bin/wmfuzzy

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmfuzzy ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../README ${DOCSDIR}
.endif

.include <bsd.port.mk>
