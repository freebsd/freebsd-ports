# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libXfont
PORTVERSION=	1.5.4
PORTEPOCH=	2
CATEGORIES=	x11-fonts

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X font library

LIB_DEPENDS=	libfreetype.so:print/freetype2

XORG_CAT=	lib
USE_XORG=	xproto:both xtrans fontsproto:both fontenc
INSTALL_TARGET=	install-strip
USES+=	cpe
CPE_PRODUCT=	libxfont
CPE_VENDOR=	x

CONFIGURE_ARGS=--without-xmlto --disable-devel-docs

.include <bsd.port.mk>
