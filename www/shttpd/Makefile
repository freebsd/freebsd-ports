# New ports collection makefile for:  shttpd
# Date created:			  Wed Dec 15, 2004
# Whom:				  Sergey Lyubka (valenok@gmail.com)
#
# $FreeBSD$
#

PORTNAME=	shttpd
PORTVERSION=	1.25
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	shttpd
DISTNAME=	shttpd-${PORTVERSION}

MAINTAINER=	valenok@gmail.com
COMMENT=	Small, fast, embeddable web server with CGI, SSL, Authorization

MAN1=		shttpd.1

.if defined(WITHOUT_SSL)
PKGNAMESUFFIX=	-nossl
.else
CFLAGS+=	-DWITH_SSL -lssl -lcrypto
.endif

PLIST_FILES=	bin/shttpd etc/shttpd.conf

do-build:
	${CC} ${CFLAGS} -DCONFIG=\"${PREFIX}/etc/shttpd.conf\" \
		${WRKSRC}/shttpd.c -o ${WRKSRC}/shttpd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/shttpd ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/shttpd.conf ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/shttpd.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
