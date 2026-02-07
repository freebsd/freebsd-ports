PORTNAME=	window
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://people.FreeBSD.org/~trhodes/

MAINTAINER=	trhodes@FreeBSD.org
COMMENT=	Window environment on ASCII terminals

LICENSE=	BSD4CLAUSE

USES=		ncurses
WRKSRC=		${WRKDIR}/window
CFLAGS+=	-Wno-return-type
MAKE_ARGS=	LDADD="-lncurses -lutil"

PLIST_FILES=	bin/window share/man/man1/window.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/window ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/window.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
