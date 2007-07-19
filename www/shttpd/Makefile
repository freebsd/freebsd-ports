# New ports collection makefile for:  shttpd
# Date created:			  Wed Dec 15, 2004
# Whom:				  Sergey Lyubka (valenok@gmail.com)
#
# $FreeBSD$
#

PORTNAME=	shttpd
PORTVERSION=	1.38
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	shttpd
DISTNAME=	shttpd-${PORTVERSION}

MAINTAINER=	valenok@gmail.com
COMMENT=	Small, fast, embeddable web server with CGI, SSL, Authorization

MAN1=		shttpd.1
ALL_TARGET=	unix
BUILD_WRKSRC=	${WRKSRC}/src

PLIST_FILES=	bin/shttpd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/shttpd ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/src/shttpd.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
