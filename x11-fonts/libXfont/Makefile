# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libXfont
PORTVERSION=	1.4.7
PORTEPOCH=	1
CATEGORIES=	x11-fonts

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X font library

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2

XORG_CAT=	lib
USE_XORG=	xproto:both xtrans fontsproto:both fontenc

CONFIGURE_ARGS=--without-xmlto --disable-devel-docs

.include <bsd.port.mk>
