# Created by: Sergey Lyubka (valenok@gmail.com)

PORTNAME=	shttpd
PORTVERSION=	1.42
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	valenok@gmail.com
COMMENT=	Small, fast, embeddable web server with CGI, SSL, Authorization

DEPRECATED=	Abandonware, last release over 12+ years ago
EXPIRATION_DATE=2022-04-30

ALL_TARGET=	unix
LIBS+=		-lpthread
BUILD_WRKSRC=	${WRKSRC}/src

PLIST_FILES=	bin/shttpd man/man1/shttpd.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/shttpd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/src/shttpd.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
