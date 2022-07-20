PORTNAME=	nsf
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	LOCAL/will

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NAKAMURA's Shell Form input

USES=		ncurses

MAKE_ARGS=	LIBS="${LDFLAGS} -lncurses"
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/nsf man/man1/nsf.1.gz
ALL_TARGET=

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nsf ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nsf.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
