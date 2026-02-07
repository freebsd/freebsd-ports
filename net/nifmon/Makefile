PORTNAME=	nifmon
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.freebsd-support.de/misc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses based network interface monitoring tool
WWW=		http://www.freebsd-support.de/misc/

USES=		ncurses
MAKE_ARGS=	LDADD="-lncurses"
PLIST_FILES=	bin/nifmon share/man/man8/nifmon.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nifmon ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nifmon.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
