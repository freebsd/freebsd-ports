PORTNAME=	ah-tty
PORTVERSION=	0.3.12
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automatic helper for command prompts and shells

USES=		ncurses
GNU_CONFIGURE=	yes
USE_CSTD=	gnu89

PLIST_FILES=	bin/ah-tty bin/ah-tty.static \
		share/ah-tty.conf man/man1/ah-tty.1.gz

INFO=		ah-tty

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' \
		${WRKSRC}/dillib/vty/vtlabel.c
	@${REINPLACE_CMD} -e 's|##x|x|' \
		${WRKSRC}/include/platform.h

.include <bsd.port.mk>
