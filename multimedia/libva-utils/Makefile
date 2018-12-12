# $FreeBSD$

PORTNAME=	libva-utils
PORTVERSION=	2.3.0
PORTREVISION=	2
CATEGORIES=	multimedia

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Collection of tests and utilities for VAAPI

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libva.so:multimedia/libva \
		libdrm.so:graphics/libdrm

USES=		autoreconf compiler:c++11-lang gmake libtool pkgconfig tar:bzip2
USE_XORG=	x11 xext xfixes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	intel

OPTIONS_DEFINE=	DEBUG WAYLAND
OPTIONS_DEFAULT=WAYLAND
WAYLAND_DESC=	Support wayland protocol
OPTIONS_SUB=	yes

DEBUG_CFLAGS=		-D_DEBUG
DEBUG_CFLAGS_OFF=	-DNDEBUG

WAYLAND_CONFIGURE_ENABLE=	wayland
WAYLAND_LIB_DEPENDS=		libwayland-client.so:graphics/wayland

.include <bsd.port.mk>
