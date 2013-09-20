# Created by: Steve Wills <steve@mouf.net>
# $FreeBSD$

PORTNAME=	xporthdmv
PORTVERSION=	1.01
CATEGORIES=	multimedia
MASTER_SITES=	http://www.w6rz.net/
DISTNAME=	xport

MAINTAINER=	swills@FreeBSD.org
COMMENT=	The xport Transport Stream Demuxer

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
PLIST_FILES=    bin/xporthdmv

NO_STAGE=	yes
do-build:
	cd ${WRKSRC} \
	&& ${CC} ${CFLAGS} xport.c -o xporthdmv

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xporthdmv ${PREFIX}/bin

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
