PORTNAME=	tty-clock
PORTVERSION=	2.3
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Terminal based clock

LICENSE=	BSD3CLAUSE

USES=		gmake ncurses pkgconfig

ALL_TARGET=	tty-clock
LDFLAGS+=	${NCURSESLIBS}

PLIST_FILES=	bin/tty-clock \
		share/man/man1/tty-clock.1.gz

GH_ACCOUNT=	xorg62
USE_GITHUB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's| -g||; /@echo /d; /@chmod/d' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tty-clock ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/tty-clock.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
