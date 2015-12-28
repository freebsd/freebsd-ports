# Created by: Adam Weinberger <adam@vectors.cx>
# $FreeBSD$

PORTNAME=	wmfuzzy
PORTVERSION=	0.7.1
PORTREVISION=	3
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	http://www.manicai.net/comp/wmfuzzy/assets/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fuzzy clock WindowMaker dockapp

LICENSE=	GPLv2

USES=		tar:tgz
USE_XORG=	xpm
WRKSRC_SUBDIR=	src

PORTDOCS=	README
PLIST_FILES=	bin/wmfuzzy

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmfuzzy ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
