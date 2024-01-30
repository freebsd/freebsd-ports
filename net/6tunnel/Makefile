PORTNAME=	6tunnel
DISTVERSION=	0.13
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	GH

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	TCP proxy for applications that do not speak IPv6
WWW=		https://github.com/wojtekka/6tunnel

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		autoreconf

USE_GITHUB=	yes
GH_ACCOUNT=	wojtekka
GH_TAGNAME=	6c64c42

PLIST_FILES=	bin/6tunnel \
		share/man/man1/6tunnel.1.gz

.include <bsd.port.mk>
