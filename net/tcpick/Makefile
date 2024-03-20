PORTNAME=	tcpick
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Text-based TCP stream sniffer
WWW=		https://tcpick.sourceforge.net/

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USE_CSTD=	gnu89

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/it/man8
	${MV} ${STAGEDIR}${PREFIX}/share/man/man8/tcpick_italian.8 ${STAGEDIR}${PREFIX}/share/man/it/man8/tcpick.8

.include <bsd.port.mk>
