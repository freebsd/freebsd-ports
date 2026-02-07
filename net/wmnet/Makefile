PORTNAME=	wmnet
PORTVERSION=	1.2
PORTREVISION=	4
CATEGORIES=	net windowmaker
MASTER_SITES=	http://vault.101011010.xyz/distfiles/ \
		http://freebsd.nsu.ru/distfiles/ \
		LOCAL/danfe LOCAL/novel

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Network bandwidth monitor for Window Maker dock

LICENSE=	GPLv2+

USES=		xorg
USE_XORG=	x11 xext xpm

PORTDOCS=	CHANGELOG README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
