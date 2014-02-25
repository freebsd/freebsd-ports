# Created by: Adam Weinberger <adam@vectors.cx>
# $FreeBSD$

PORTNAME=	wmfuzzy
PORTVERSION=	0.7.1
PORTREVISION=	3
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	http://www.manicai.net/comp/wmfuzzy/assets/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fuzzy clock WindowMaker dockapp

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_XORG=	xpm

PORTDOCS=	README
PLIST_FILES=	bin/wmfuzzy

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmfuzzy ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
