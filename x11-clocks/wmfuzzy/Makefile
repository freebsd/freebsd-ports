# Created by: Adam Weinberger <adam@vectors.cx>
# $FreeBSD$

PORTNAME=	wmfuzzy
PORTVERSION=	0.7.1
PORTREVISION=	2
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	http://www.manicai.net/comp/wmfuzzy/assets/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A fuzzy clock WindowMaker dockapp

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_XORG=	xpm

PORTDOCS=	README
PLIST_FILES=	bin/wmfuzzy

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmfuzzy ${STAGEDIR}${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../README ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
