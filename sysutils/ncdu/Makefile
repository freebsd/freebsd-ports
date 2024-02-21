PORTNAME=	ncdu
PORTVERSION=	1.19
CATEGORIES=	sysutils
MASTER_SITES=	https://dev.yorhel.nl/download/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	NCurses Disk Usage (LTS version written in C)
WWW=		https://dev.yorhel.nl/ncdu \
		https://code.blicky.net/yorhel/ncdu

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/ncdu \
		share/man/man1/ncdu.1.gz

# ncdu 1.* (LTS) is written in C.
# ncdu 2.* (stable) is written in Zig which only works with specific version.
PORTSCOUT=	limit:^1\.

.include <bsd.port.mk>
