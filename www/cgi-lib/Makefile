# New ports collection makefile for:	libcgi
# Date created:				7 January 2000
# Whom:					Sergey Samoyloff <gonza@techline.ru>
#
# $FreeBSD$
#

PORTNAME=	cgi-lib
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	alex

MAINTAINER=	gonza@techline.ru
COMMENT=	ANSI C Library for CGI Programming

MAKEFILE=	makefile

NO_WRKSUBDIR=	yes

do-install:
	@ ${INSTALL_DATA} ${WRKSRC}/cgi-lib.a ${PREFIX}/lib/libcgi.a
.for file in cgi-lib.h html-lib.h list-lib.h
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/include
.endfor
	@ ${MKDIR} ${PREFIX}/share/doc/cgi-lib
	@ ${INSTALL_DATA} ${WRKSRC}/cgi-lib.html ${PREFIX}/share/doc/cgi-lib

.include <bsd.port.mk>
