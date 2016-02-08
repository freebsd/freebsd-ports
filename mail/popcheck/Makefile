# Created by: Radim Kolar
# $FreeBSD$

PORTNAME=	popcheck
PORTVERSION=	1.3
CATEGORIES=	mail
MASTER_SITES=	http://www.ludd.luth.se/~staham/linux/programs/ \
		http://T32.TecNik93.com/FreeBSD/others_ports/${PORTNAME}/sources/
DISTNAME=	popcheck

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Preview and delete messages in POP3 mailbox

USES=		ncurses
ALL_TARGET=	popcheck
MAKE_ARGS=	LDFLAGS="${LDFLAGS} -lncurses"
PLIST_FILES=	bin/popcheck man/man1/popcheck.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/popcheck ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/popcheck.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
