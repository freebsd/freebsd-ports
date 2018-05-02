# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freerdp
DISTVERSION=	2.0.0-rc1
PORTREVISION=	5
CATEGORIES=	net comms ipv6

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	78df32c77f28.patch:-p1 ed571e74a594.patch:-p1

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	Free implementation of Remote Desktop Protocol

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		alias cmake:outsource compiler:c++11-lib cpe gettext localbase pathfix pkgconfig ssl
USE_LDCONFIG=	yes
CPE_VENDOR=	freerdp_project

USE_GITHUB=	yes
GH_ACCOUNT=	FreeRDP
GH_PROJECT=	${GH_ACCOUNT}

CMAKE_ARGS+=	-DWITH_LIBSYSTEMD=OFF -DWITH_GSTREAMER_0_10=OFF ${CMAKE_ARGS_${ARCH}}

CMAKE_ARGS_aarch64=	-DWITH_NEON=ON
CFLAGS_aarch64=		-D__ARM_NEON__=__ARM_NEON # clang

OPTIONS_DEFINE=		ALSA CUPS FFMPEG GSTREAMER ICU KERBEROS MANPAGES \
			PULSEAUDIO WAYLAND X11
OPTIONS_DEFAULT=	CUPS GSTREAMER ICU KERBEROS MANPAGES WAYLAND X11
OPTIONS_SUB=		yes

OPTIONS_DEFINE_armv6=	NEON
OPTIONS_DEFINE_armv7=	NEON
OPTIONS_DEFINE_amd64=	SSE
OPTIONS_DEFINE_i386=	SSE
OPTIONS_DEFAULT_amd64=	SSE

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	WITH_ALSA

CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_CMAKE_BOOL=	WITH_CUPS

FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
			libavutil.so:multimedia/ffmpeg
FFMPEG_CMAKE_BOOL=	WITH_FFMPEG

GSTREAMER_CMAKE_BOOL=	WITH_GSTREAMER_1_0
GSTREAMER_USE=		gnome=glib20 gstreamer1=yes xorg=x11,xext,xextproto,xrandr
GSTREAMER_LIB_DEPENDS=	libgstbase-1.0.so:multimedia/gstreamer1

ICU_LIB_DEPENDS=	libicuuc.so:devel/icu
ICU_CMAKE_BOOL=		WITH_ICU

KERBEROS_CMAKE_BOOL=	WITH_GSSAPI_HEIMDAL

MANPAGES_BUILD_DEPENDS=	xmlto:textproc/xmlto
MANPAGES_CMAKE_BOOL=	WITH_MANPAGES
MANPAGES_CMAKE_OFF=	-DWITH_MANPAGES=OFF

NEON_DESC=		Enable	Media Processing Engine instructions
NEON_CMAKE_BOOL=	WITH_NEON
.if ! ${CFLAGS:M-march*}
NEON_CFLAGS=		-march=armv7-a
.endif

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	WITH_PULSE

SSE_CMAKE_BOOL=		WITH_SSE2

WAYLAND_DESC=		Build FreeRDP Wayland client
WAYLAND_BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:multimedia/v4l_compat
WAYLAND_LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
			libwayland-client.so:graphics/wayland \
			libwayland-cursor.so:graphics/wayland \
			libxkbcommon.so:x11/libxkbcommon
WAYLAND_CMAKE_BOOL=	WITH_WAYLAND

X11_DESC=		Build FreeRDP X11 client
X11_CMAKE_BOOL=		WITH_X11
X11_CMAKE_OFF=		-DWITH_XKBFILE=OFF
X11_USE=		xorg=x11,xcursor,xext,xextproto,xfixes,xi,xinerama,xkbfile,xrandr,xrender,xv

.include <bsd.port.pre.mk>

.if ${OPSYS} == "FreeBSD" && ${ARCH} == "armv6"
.if ${OSVERSION} < 1100500 || \
	(${OSVERSION} >= 1100500 && ${OSVERSION} < 1100504) || \
	(${OSVERSION} >= 1200000 && ${OSVERSION} < 1200008)
BROKEN=	Fails to build on ARMv6 (libm bug). See: r305380 (HEAD), r305971 (stable/11) [\#199422, \#211965] \
	Please update to a later (fixed) version.
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e '/CMAKE_INSTALL_RPATH /d' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's/Linux/Linux|FreeBSD/' \
		${WRKSRC}/winpr/CMakeLists.txt
	@${REINPLACE_CMD} -e 's/NetBSD__)/NetBSD__) || defined(__FreeBSD__)/' \
		${WRKSRC}/winpr/libwinpr/utils/trio/triodef.h
	@${RM} ${WRKSRC}/cmake/FindOpenSSL.cmake
	@${REINPLACE_CMD} -e 's|$${CMAKE_INSTALL_LIBDIR}/cmake|$${CMAKE_INSTALL_PREFIX}/share/cmake/Modules|' \
		${WRKSRC}/client/CMakeLists.txt \
		${WRKSRC}/winpr/CMakeLists.txt \
		${WRKSRC}/uwac/CMakeLists.txt \
		${WRKSRC}/server/CMakeLists.txt \
		${WRKSRC}/server/shadow/CMakeLists.txt \
		${WRKSRC}/libfreerdp/CMakeLists.txt

.include <bsd.port.post.mk>
