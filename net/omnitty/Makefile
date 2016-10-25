# Created by: Rong-En Fan <rafan@infor.org>
# $FreeBSD$

PORTNAME=	omnitty
PORTVERSION=	0.3.0
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	SF/omnitty/omnitty/omnitty-${PORTVERSION}

MAINTAINER=	david@catwhisker.org
COMMENT=	Curses-based SSH multiplexer

LIB_DEPENDS=	librote.so:devel/rote

USES=		gmake ncurses
GNU_CONFIGURE=	yes
LIBS+=		-lncurses

ALL_TARGET=	omnitty
PLIST_FILES=	bin/omnitty man/man1/omnitty.1.gz

post-patch:
	${REINPLACE_CMD} 's|<alloca.h>|<stdlib.h>|' ${WRKSRC}/machmgr.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/omnitty ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/omnitty.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
