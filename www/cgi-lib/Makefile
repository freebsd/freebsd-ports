# New ports collection makefile for:	libcgi
# Date created:		7 January 2000
# Whom:			Sergey Samoyloff <gonza@techline.ru>
#
# $FreeBSD$
#

PORTNAME=	cgi-lib
PORTVERSION= 	1.3
CATEGORIES=	www
MASTER_SITES=	http://www.geocities.com/SiliconValley/Vista/6493/projects/code/
DISTNAME=	${PORTNAME}

MAINTAINER=	gonza@techline.ru

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
