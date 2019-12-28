# Created by: Eric Freeman <freebsdports@chillibear.com>
# $FreeBSD$

PORTNAME=	tty-clock
PORTVERSION=	2.3
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Terminal based clock

LICENSE=	BSD3CLAUSE

USES=		gmake ncurses pkgconfig

ALL_TARGET=	tty-clock
LDFLAGS+=	-l${NCURSES_IMPL}

PLIST_FILES=	bin/tty-clock \
		man/man1/tty-clock.1.gz

GH_ACCOUNT=	xorg62
USE_GITHUB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|; s| -g||; /@echo /d; /@chmod/d' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tty-clock ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/tty-clock.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
