# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libXfont
PORTVERSION=	1.5.4
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	x11-fonts

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X font library

LICENSE=	MIT BSD2CLAUSE BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		cpe xorg xorg-cat:lib
USE_XORG=	xorgproto xtrans fontenc
INSTALL_TARGET=	install-strip
CPE_PRODUCT=	libxfont
CPE_VENDOR=	x

CONFIGURE_ARGS=	--without-xmlto --disable-devel-docs

.include <bsd.port.mk>
