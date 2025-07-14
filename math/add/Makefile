PORTNAME=	add
PORTVERSION=	20240916
CATEGORIES=	math
MASTER_SITES=	https://invisible-island.net/archives/add/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Full-screen editing calculator
WWW=		https://invisible-island.net/add/add.html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses tar:tgz
GNU_CONFIGURE=	yes

MAKEFILE=	makefile

PLIST_FILES=	bin/add \
		share/man/man1/add.1.gz
PORTDATA=	add.hlp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/add \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/add.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/add.hlp \
		${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
