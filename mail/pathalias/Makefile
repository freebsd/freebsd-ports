PORTNAME=	pathalias
PORTVERSION=	9.16
PORTREVISIOMN=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.dinoex.de/pub/approved/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Mail routing tools

USES=		tar:Z

ALL_TARGET=	pathalias

PLIST_FILES=	bin/pathalias share/man/man8/pathalias.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pathalias ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/pathalias.8 ${STAGEDIR}${PREFIX}/share/man/man8/

.include <bsd.port.mk>
