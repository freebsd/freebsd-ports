PORTNAME=	add
PORTVERSION=	20230205
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	ftp://dickey.his.com/add/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Full-screen editing calculator
WWW=		https://dickey.his.com/add/add.html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses tar:tgz
GNU_CONFIGURE=	yes

MAKEFILE=	makefile

PLIST_FILES=	bin/add \
		share/man/man1/add.1.gz
PORTDATA=	add.hlp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/add ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/add.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/add.hlp ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
