PORTNAME=	ipbt
DISTVERSION=	r8765
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.chiark.greenend.org.uk/~sgtatham/ipbt/ \
		LOCAL/uqs

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High-tech ttyrec player with improvements over ttyplay
WWW=		https://www.chiark.greenend.org.uk/~sgtatham/ipbt/

USES=		ncurses perl5 shebangfix

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

ALL_TARGET=	${PORTNAME}
MAKE_ARGS=	LFLAGS="${LDFLAGS}" NCURSES_LIB="${NCURSESLIBS}"
PLIST_FILES=	bin/ipbt bin/ttygrep bin/ttydump share/man/man1/ipbt.1.gz
SHEBANG_FILES=	sbcsgen.pl Makefile ttygrep ttydump

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ttydump ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ttygrep ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ipbt.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
