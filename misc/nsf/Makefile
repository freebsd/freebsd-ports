# Created by: kaz
# $FreeBSD$

PORTNAME=	nsf
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	LOCAL/will

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NAKAMURA's Shell Form input

USES=		ncurses
WRKSRC=		${WRKDIR}
MAKE_ARGS=	LIBS="${LDFLAGS} -lncurses"
PLIST_FILES=	bin/nsf man/man1/nsf.1.gz
ALL_TARGET=

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/nsf ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/nsf.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
