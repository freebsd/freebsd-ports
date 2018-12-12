# $FreeBSD$

PORTNAME=	uTox
DISTVERSION=	0.17.0
DISTVERSIONSUFFIX=	-full
PORTREVISION=	4
CATEGORIES=	net-im net-p2p
MASTER_SITES=	https://github.com/uTox/uTox/releases/download/v${PORTVERSION}/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Lightweight Tox client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=		fails to compile: endian.h:68:20: too many arguments provided to function-like macro invocation
BROKEN_armv6=		fails to compile: endian.h:68:20: too many arguments provided to function-like macro invocation
BROKEN_armv7=		fails to compile: endian.h:68:20: too many arguments provided to function-like macro invocation

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libsodium.so:security/libsodium \
		libv4lconvert.so:multimedia/libv4l \
		libvpx.so:multimedia/libvpx \
		libopus.so:audio/opus \
		libtoxcore.so:net-im/tox

USES=		cmake:outsource compiler:c11 desktop-file-utils dos2unix \
		openal pkgconfig
USE_XORG=	ice sm x11 xext xrender
CMAKE_OFF=	ENABLE_LTO
DOS2UNIX_GLOB=	*
LLD_UNSAFE=	yes
WRKSRC=		${WRKDIR}/uTox

OPTIONS_DEFINE=		DBUS
OPTIONS_DEFAULT=	DBUS

DBUS_CMAKE_BOOL=	ENABLE_DBUS
DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus

.include <bsd.port.mk>
