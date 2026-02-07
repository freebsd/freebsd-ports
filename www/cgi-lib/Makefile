PORTNAME=	cgi-lib
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=		LOCAL/alex

MAINTAINER=	gonza@techline.ru
COMMENT=	ANSI C Library for CGI Programming

MAKEFILE=	makefile

NO_WRKSUBDIR=	yes

do-install:
	@ ${INSTALL_DATA} ${WRKSRC}/cgi-lib.a ${STAGEDIR}${PREFIX}/lib/libcgi.a
.for file in cgi-lib.h html-lib.h list-lib.h
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/include
.endfor
	@ ${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/cgi-lib
	@ ${INSTALL_DATA} ${WRKSRC}/cgi-lib.html ${STAGEDIR}${PREFIX}/share/doc/cgi-lib

.include <bsd.port.mk>
