# New ports collection makefile for: 9libs
# Date created:		15 February 2003
# Whom:			gagnon__s@videotron.ca
#
# $FreeBSD$
#

PORTNAME=	9libs
PORTVERSION=	1.0.1
CATEGORIES=	x11-toolkits plan9
MASTER_SITES=	ftp://ftp.cs.yorku.ca/pub/wily/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plan9 compatibility libraries

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--includedir=${PREFIX}/include/9libs

MAN3=	add.3 balloc.3 bitblt.3 cachechars.3 event.3 frame.3 graphics.3 rgbpix.3 rune.3
MAN4=	font.4 keyboard.4 utf.4
MAN6=	bitmap.6 regexp.6

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" || ${ARCH} == "amd64"
BROKEN=		Does not compile on alpha or amd64
.endif

.include <bsd.port.post.mk>
