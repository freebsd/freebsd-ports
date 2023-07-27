PORTNAME=	wmnetload
PORTVERSION=	1.3
PORTREVISION=	5
CATEGORIES=	net windowmaker afterstep
MASTER_SITES=	http://vault.101011010.xyz/distfiles/ \
		http://freebsd.nsu.ru/distfiles/ LOCAL/danfe

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Network load monitor dockapp for Window Maker
WWW=		https://www.dockapps.net/wmnetload

LICENSE=	GPLv2+

LIB_DEPENDS=	libdockapp.so:x11-wm/libdockapp

USES=		tar:bzip2 xorg
USE_XORG=	x11 xext xpm
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
