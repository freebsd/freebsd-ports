# $FreeBSD$

PORTNAME=	uTox
DISTVERSION=	0.17.1
DISTVERSIONSUFFIX=	-full
CATEGORIES=	net-im net-p2p
MASTER_SITES=	https://github.com/uTox/uTox/releases/download/v${DISTVERSION}/

PATCH_SITES=	https://github.com/uTox/uTox/commit/
PATCHFILES=	37271f991c590a533781b66e9036e9b66dfbbf1b.patch:-p1

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Lightweight Tox client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=	fails to compile: endian.h:68:20: too many arguments provided to function-like macro invocation
BROKEN_armv6=	fails to compile: endian.h:68:20: too many arguments provided to function-like macro invocation
BROKEN_armv7=	fails to compile: endian.h:68:20: too many arguments provided to function-like macro invocation

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto \
		${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libfilteraudio.so:audio/libfilteraudio \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libopus.so:audio/opus \
		libsodium.so:security/libsodium \
		libtoxcore.so:net-im/tox \
		libv4lconvert.so:multimedia/libv4l \
		libvpx.so:multimedia/libvpx
TEST_DEPENDS=	check>=0:devel/check

USES=		cmake compiler:c11 desktop-file-utils openal pkgconfig xorg
USE_XORG=	ice sm x11 xext xrender

CMAKE_OFF=	ENABLE_LTO ENABLE_TESTS
# Uses ld -b binary without -m 
LLD_UNSAFE=	yes
WRKSRC=		${WRKDIR}/uTox

OPTIONS_DEFINE=		DBUS
OPTIONS_DEFAULT=	DBUS

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CMAKE_BOOL=	ENABLE_DBUS

do-test:
	@cd ${TEST_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} \
		-DENABLE_TESTS:BOOL=yes ${CMAKE_SOURCE_PATH} && \
		${DO_MAKE_BUILD}
	@${TEST_WRKSRC}/run_tests.sh

.include <bsd.port.mk>
