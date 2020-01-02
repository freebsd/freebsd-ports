# Created by: Matt Mills <matt_mills@btopenworld.com>
# $FreeBSD$

PORTNAME=	ipbt
DISTVERSION=	r8765
CATEGORIES=	misc
MASTER_SITES=	http://www.chiark.greenend.org.uk/~sgtatham/ipbt/ \
		LOCAL/uqs

MAINTAINER=	uqs@FreeBSD.org
COMMENT=	High-tech ttyrec player with improvements over ttyplay

USES=		ncurses perl5 shebangfix

ALL_TARGET=	${PORTNAME}
MAKE_ARGS=	LFLAGS="${LDFLAGS}" NCURSES_LIB=-l${NCURSES_IMPL}
PLIST_FILES=	bin/ipbt bin/ttygrep bin/ttydump man/man1/ipbt.1.gz
SHEBANG_FILES=	sbcsgen.pl Makefile ttygrep ttydump

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ttydump ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ttygrep ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ipbt.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
