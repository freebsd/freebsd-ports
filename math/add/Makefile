PORTNAME=	add
PORTVERSION=	20220117
CATEGORIES=	math
MASTER_SITES=	ftp://dickey.his.com/add/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full-screen editing calculator

GNU_CONFIGURE=	yes
USES=		ncurses tar:tgz
MAKEFILE=	makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/add ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/add.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/add.hlp ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
