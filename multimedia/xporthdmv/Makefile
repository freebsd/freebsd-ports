# New ports collection makefile for:	xporthdmv
# Date created:		2009-08-05
# Whom:			Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	xporthdmv
PORTVERSION=	1.01
CATEGORIES=	multimedia
MASTER_SITES=	http://www.w6rz.net/
DISTNAME=	xport

MAINTAINER=	steve@mouf.net
COMMENT=	The xport Transport Stream Demuxer

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
PLIST_FILES=    bin/xporthdmv

do-build:
	cd ${WRKSRC} \
	&& ${CC} ${CFLAGS} xport.c -o xporthdmv

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xporthdmv ${PREFIX}/bin

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
