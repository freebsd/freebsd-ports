# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freerdp
DISTVERSION=	2.0.0-rc4
PORTREVISION=	7
CATEGORIES=	net comms

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	649f49f.patch:-p1 effa8b8.patch:-p1 0c83efa.patch:-p1

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	Free implementation of Remote Desktop Protocol

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_SSL=	libressl-devel
BROKEN_SSL_REASON_libressl-devel=	fails to compile: no member named 'alert_dispatch' in 'struct ssl3_state_st'

LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim

USES=		alias cmake compiler:c++11-lib cpe gettext gnome localbase pathfix pkgconfig ssl
USE_LDCONFIG=	yes

CPE_VENDOR=	freerdp_project

USE_GITHUB=	yes
GH_ACCOUNT=	FreeRDP
GH_PROJECT=	${GH_ACCOUNT}

CMAKE_ARGS+=	-DWITH_CHANNELS:BOOL=ON \
		-DWITH_DIRECTFB:BOOL=OFF \
		-DWITH_DSP_EXPERIMENTAL:BOOL=OFF \
		-DWITH_DSP_FFMPEG:BOOL=OFF -DWITH_GPROF:BOOL=OFF \
		-DWITH_GSTREAMER_0_10:BOOL=OFF -DWITH_IPP:BOOL=OFF \
		-DWITH_JPEG:BOOL=OFF -DWITH_LIBSYSTEMD:BOOL=OFF \
		-DWITH_MBEDTLS:BOOL=OFF -DWITH_OPENSLES=OFF \
		-DWITH_OPENSSL:BOOL=ON -DWITH_OSS=ON \
		-DWITH_PROFILER:BOOL=OFF -DWITH_SAMPLE:BOOL=OFF \
		-DWITH_SANITIZE_ADDRESS:BOOL=OFF \
		-DWITH_SANITIZE_MEMORY:BOOL=OFF \
		-DWITH_SANITIZE_THREAD:BOOL=OFF -DWITH_SERVER:BOOL=OFF \
		-DWITH_SERVER_INTERFACE:BOOL=OFF \
		-DWITH_SMARTCARD_INSPECT:BOOL=OFF \
		-DWITH_THIRD_PARTY:BOOL=OFF \
		-DWITH_VALGRIND_MEMCHECK:BOOL=OFF -DWITH_X264:BOOL=OFF \
		-DWITH_ZLIB:BOOL=ON \
		${CMAKE_ARGS_${ARCH}}

CMAKE_ARGS_aarch64=	-DWITH_NEON=ON
CFLAGS_aarch64=		-D__ARM_NEON__=__ARM_NEON # clang

OPTIONS_DEFINE=		ALSA CUPS FAAC FAAD FFMPEG GSM \
			GSTREAMER ICU KERBEROS LAME MANPAGES OPENH264 \
			PCSC PULSEAUDIO SOXR WAYLAND X11
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

FAAC_LIB_DEPENDS=	libfaac.so:audio/faac
FAAC_CMAKE_BOOL=	WITH_FAAC

FAAD_LIB_DEPENDS=	libfaad.so:audio/faad
FAAD_CMAKE_BOOL=	WITH_FAAD2

FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
			libavutil.so:multimedia/ffmpeg
FFMPEG_CMAKE_BOOL=	WITH_FFMPEG

GSM_LIB_DEPENDS=	libgsm.so:audio/gsm
GSM_CMAKE_BOOL=		WITH_GSM

GSTREAMER_CMAKE_BOOL=	WITH_GSTREAMER_1_0
GSTREAMER_USES=		gnome xorg
GSTREAMER_USE=		gnome=glib20 gstreamer1=yes xorg=x11,xext,xorgproto,xrandr
GSTREAMER_LIB_DEPENDS=	libgstbase-1.0.so:multimedia/gstreamer1

ICU_LIB_DEPENDS=	libicuuc.so:devel/icu
ICU_CMAKE_BOOL=		WITH_ICU

KERBEROS_CMAKE_BOOL=	WITH_GSSAPI_HEIMDAL

LAME_LIB_DEPENDS=	libmp3lame.so:audio/lame
LAME_CMAKE_BOOL=	WITH_LAME

MANPAGES_BUILD_DEPENDS=	xmlto:textproc/xmlto
MANPAGES_CMAKE_BOOL=	WITH_MANPAGES
MANPAGES_CMAKE_OFF=	-DWITH_MANPAGES=OFF

NEON_DESC=		Enable	Media Processing Engine instructions
NEON_CMAKE_BOOL=	WITH_NEON
.if ! ${CFLAGS:M-march*}
NEON_CFLAGS=		-march=armv7-a
.endif

OPENH264_DESC=		H.264 video codec support via OpenH264
OPENH264_LIB_DEPENDS=	libopenh264.so:multimedia/openh264
OPENH264_CMAKE_BOOL=	WITH_OPENH264

PCSC_DESC=		Smart card support (smart card device redirection)
PCSC_LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite
PCSC_CMAKE_BOOL=	WITH_PCSC

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	WITH_PULSE

SOXR_LIB_DEPENDS=	libsoxr.so:audio/libsoxr
SOXR_CMAKE_BOOL=	WITH_SOXR

SSE_CMAKE_BOOL=		WITH_SSE2

WAYLAND_DESC=		Build FreeRDP Wayland client
WAYLAND_BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
			libwayland-cursor.so:graphics/wayland \
			libxkbcommon.so:x11/libxkbcommon
WAYLAND_CMAKE_BOOL=	WITH_WAYLAND

X11_DESC=		Build FreeRDP X11 client
X11_CMAKE_ON=		-DWITH_X11:BOOL=ON -DWITH_XCURSOR:BOOL=ON \
			-DWITH_XEXT:BOOL=ON -DWITH_XFIXES:BOOL=ON \
			-DWITH_XI:BOOL=ON -DWITH_XINERAMA:BOOL=ON \
			-DWITH_XKBFILE:BOOL=ON -DWITH_XRANDR:BOOL=ON \
			-DWITH_XRENDER:BOOL=ON -DWITH_XSHM:BOOL=ON \
			-DWITH_XV:BOOL=ON
X11_CMAKE_OFF=		-DWITH_X11:BOOL=OFF -DWITH_XKBFILE:BOOL=OFF
X11_USES=		xorg
X11_USE=		xorg=x11,xcursor,xext,xorgproto,xfixes,xi,xinerama,xkbfile,xrandr,xrender,xv

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
	@${REINPLACE_CMD} -e 's|gsm/gsm.h|gsm.h|' \
		${WRKSRC}/cmake/FindGSM.cmake \
		${WRKSRC}/libfreerdp/codec/dsp.c

.include <bsd.port.mk>
