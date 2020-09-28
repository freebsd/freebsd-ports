# $FreeBSD$

PORTNAME=	uTox
DISTVERSION=	0.17.2
PORTREVISION=	1
DISTVERSIONSUFFIX=	-full
CATEGORIES=	net-im net-p2p
MASTER_SITES=	https://github.com/uTox/uTox/releases/download/v${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight Tox client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

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
WRKSRC=		${WRKDIR}/uTox

OPTIONS_DEFINE=		DBUS
OPTIONS_DEFAULT=	DBUS

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CMAKE_BOOL=	ENABLE_DBUS

.if ${/usr/bin/ld:L:tA} == /usr/bin/ld.lld
# ld.lld lacks default output emulation.  Using -b binary without
# explicit -m will fail.  Mapping taken from lld/ELF/Driver.cpp.
_LLD_EMUL_aarch64=	aarch64elf_fbsd
_LLD_EMUL_amd64=	elf_x86_64_fbsd
_LLD_EMUL_armv6=	armelf_fbsd
_LLD_EMUL_armv7=	armelf_fbsd
_LLD_EMUL_i386=		elf_i386_fbsd
_LLD_EMUL_powerpc=	elf32ppc_fbsd
_LLD_EMUL_powerpc64=	elf64ppc_fbsd
_LLD_EMUL_powerpc64le=	elf64ppc_fbsd

post-patch:
	@${REINPLACE_CMD} 's,[[:<:]]ld[[:>:]],ld -m${_LLD_EMUL_${ARCH}},' \
		${WRKSRC}/src/xlib/CMakeLists.txt
.endif

do-test:
	@cd ${TEST_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} \
		-DENABLE_TESTS:BOOL=yes ${CMAKE_SOURCE_PATH} && \
		${DO_MAKE_BUILD}
	@${TEST_WRKSRC}/run_tests.sh

.include <bsd.port.mk>
