PORTNAME=	numchar
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	ftp://www.whizkidtech.redprince.net/unix/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts phone numbers between digits and characters

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/numchar ${STAGEDIR}${PREFIX}/bin
	${LN} -fs ${PREFIX}/bin/numchar ${STAGEDIR}${PREFIX}/bin/phdecode
	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/numchar
	${INSTALL_DATA} ${WRKSRC}/numchar.html \
		${STAGEDIR}${PREFIX}/share/doc/numchar

.include <bsd.port.mk>
