PORTNAME=	freerdp
DISTVERSION=	2.11.2
PORTREVISION=	2
CATEGORIES=	net comms
MASTER_SITES=	https://pub.freerdp.com/releases/ \
		https://github.com/FreeRDP/FreeRDP/releases/download/${DISTVERSION}/

PATCH_SITES=	https://github.com/FreeRDP/FreeRDP/commit/
PATCHFILES+=	61983cd6dcb86097d91b7ef405abc1266444a368.patch:-p1 # ffmpeg6 support: AVPicture
								   # https://github.com/FreeRDP/FreeRDP/pull/8941
PATCHFILES+=	b27b20b2a27217be44fbc5d734299dc45572a207.patch:-p1 # Advertise Image RFX GUID when rfx-mode:image
								   # https://github.com/FreeRDP/FreeRDP/pull/9428

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	Free implementation of Remote Desktop Protocol
WWW=		https://www.freerdp.com/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_SSL=	libressl-devel
BROKEN_SSL_REASON_libressl-devel=	fails to compile: no member named 'alert_dispatch' in 'struct ssl3_state_st'

LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim

USES=		alias cmake compiler:c++11-lib cpe gettext localbase pathfix pkgconfig ssl
USE_LDCONFIG=	yes

PATCHVERSION=	${PORTVERSION}
MAJORVERSION=	${PORTVERSION:R:R}

CMAKE_ARGS+=	${CMAKE_ARGS_${ARCH}}
CMAKE_ON=	WITH_CHANNELS WITH_OPENSSL WITH_OSS WITH_ZLIB CHANNEL_URBDRC_CLIENT
CMAKE_OFF=	WITH_DSP_EXPERIMENTAL WITH_GPROF WITH_GSTREAMER_0_10 WITH_IPP \
		WITH_LIBSYSTEMD WITH_MBEDTLS WITH_OPENCL WITH_OPENSLES WITH_PROFILER \
		WITH_SAMPLE WITH_SANITIZE_ADDRESS WITH_SANITIZE_MEMORY \
		WITH_SANITIZE_THREAD WITH_SERVER WITH_SERVER_INTERFACE \
		WITH_SMARTCARD_INSPECT WITH_THIRD_PARTY WITH_VALGRIND_MEMCHECK

CMAKE_ARGS_aarch64+=	-DWITH_NEON=ON
CFLAGS_aarch64+=	-D__ARM_NEON__=__ARM_NEON # clang

PLIST_SUB+=	PATCHVERSION="${PATCHVERSION}"
PLIST_SUB+=	MAJORVERSION="${MAJORVERSION}"

OPTIONS_DEFINE=		ALSA BROKENFOCUS CUPS FAAC FAAD FFMPEG GSM GSTREAMER \
			ICU JPEG KERBEROS LAME MANPAGES OPENH264 PCSC \
			PULSEAUDIO SOXR WAYLAND X11
OPTIONS_DEFAULT=	CUPS GSTREAMER ICU KERBEROS MANPAGES SWSCALE WAYLAND X11
OPTIONS_RADIO=		SCALE
OPTIONS_RADIO_SCALE=	CAIRO SWSCALE
OPTIONS_SUB=		yes

OPTIONS_DEFINE_armv6=	NEON
OPTIONS_DEFINE_armv7=	NEON
OPTIONS_DEFINE_amd64=	SSE
OPTIONS_DEFINE_i386=	SSE
OPTIONS_DEFAULT_amd64=	SSE

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	WITH_ALSA

BROKENFOCUS_DESC=	Work around focus bug in some WMs (PR \#254908)
BROKENFOCUS_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-focusbug.diff

CAIRO_DESC=		Use CAIRO image library for screen resizing
CAIRO_LIB_DEPENDS=	libcairo.so:graphics/cairo
CAIRO_CMAKE_BOOL=	WITH_CAIRO

CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_CMAKE_BOOL=	WITH_CUPS

FAAC_LIB_DEPENDS=	libfaac.so:audio/faac
FAAC_CMAKE_BOOL=	WITH_FAAC

FAAD_LIB_DEPENDS=	libfaad.so:audio/faad
FAAD_CMAKE_BOOL=	WITH_FAAD2

FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
			libavutil.so:multimedia/ffmpeg
FFMPEG_CMAKE_BOOL=	WITH_FFMPEG WITH_DSP_FFMPEG

GSM_LIB_DEPENDS=	libgsm.so:audio/gsm
GSM_CMAKE_BOOL=		WITH_GSM

GSTREAMER_CMAKE_BOOL=	WITH_GSTREAMER_1_0 CHANNEL_TSMF
GSTREAMER_USES=		gnome gstreamer xorg
GSTREAMER_USE=		gnome=glib20 xorg=x11,xext,xorgproto,xrandr
GSTREAMER_LIB_DEPENDS=	libgstbase-1.0.so:multimedia/gstreamer1

ICU_LIB_DEPENDS=	libicuuc.so:devel/icu
ICU_CMAKE_BOOL=		WITH_ICU

JPEG_USES=		jpeg
JPEG_CMAKE_BOOL=	WITH_JPEG

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

SWSCALE_DESC=		Use SWScale image library for screen resizing (recommended)
SWSCALE_LIB_DEPENDS=	libswscale.so:multimedia/ffmpeg
SWSCALE_CMAKE_BOOL=	WITH_SWSCALE

WAYLAND_DESC=		Build FreeRDP Wayland client
WAYLAND_CATEGORIES=	wayland
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
	@${REINPLACE_CMD} -e 's|gsm/gsm.h|gsm.h|' \
		${WRKSRC}/cmake/FindGSM.cmake \
		${WRKSRC}/libfreerdp/codec/dsp.c

pre-configure:
	${CP} ${FILESDIR}/mntent.h ${WRKSRC}/rdtk/include
	${CP} ${FILESDIR}/mntent_compat.c ${WRKSRC}/channels/rdpdr/client

.include <bsd.port.mk>
