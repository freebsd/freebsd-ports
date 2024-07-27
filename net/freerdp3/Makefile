PORTNAME=	freerdp
DISTVERSION=	3.6.3
CATEGORIES=	net comms
MASTER_SITES=	https://pub.freerdp.com/releases/ \
		https://github.com/FreeRDP/FreeRDP/releases/download/${DISTVERSION}/
PKGNAMESUFFIX=	3

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	Free implementation of Remote Desktop Protocol
WWW=		https://www.freerdp.com/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim

USES=		alias cmake compiler:c++11-lib cpe localbase:ldflags pathfix pkgconfig ssl xorg

BROKEN_SSL=	libressl-devel
BROKEN_SSL_REASON_libressl-devel=	fails to compile: no member named 'alert_dispatch' in 'struct ssl3_state_st'

USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xext

CMAKE_ARGS+=	${CMAKE_ARGS_${ARCH}}
CMAKE_ON=	CHANNEL_URBDRC_CLIENT RDTK_FORCE_STATIC_BUILD UWAC_FORCE_STATIC_BUILD \
		WITH_BINARY_VERSIONING WITH_CHANNELS WITH_OPENSSL WITH_OSS WITH_ZLIB \
		WITH_FREERDP_DEPRECATED WITH_FREERDP_DEPRECATED_COMMANDLINE WITH_WINPR_DEPRECATED
CMAKE_OFF=	CHANNEL_TSMF WITH_DSP_EXPERIMENTAL WITH_FUSE WITH_GPROF WITH_GSTREAMER_0_10 \
		WITH_GSTREAMER_1_0 WITH_IPP WITH_LIBSYSTEMD WITH_MBEDTLS \
		WITH_OPENCL WITH_OPENSLES WITH_PROFILER WITH_SAMPLE \
		WITH_SANITIZE_ADDRESS WITH_SANITIZE_MEMORY WITH_SANITIZE_THREAD \
		WITH_SERVER WITH_SERVER_CHANNELS WITH_SERVER_INTERFACE \
		WITH_SMARTCARD_INSPECT WITH_THIRD_PARTY WITH_VALGRIND_MEMCHECK

PLIST_SUB+=	PATCHVERSION="${DISTVERSION}"
PLIST_SUB+=	MAJORVERSION="${DISTVERSION:R:R}"

OPTIONS_DEFINE=			ALSA BROKENFOCUS CUPS FAAC FAAD FFMPEG GSM ICU \
				JPEG LAME MANPAGES OPENH264 OPUS PCSC PKCS11 \
				PULSEAUDIO SDL SOXR URIPARSER WAYLAND X11
OPTIONS_DEFINE_aarch64=		NEON
OPTIONS_DEFINE_amd64=		SSE
OPTIONS_DEFINE_armv6=		NEON
OPTIONS_DEFINE_armv7=		NEON
OPTIONS_DEFINE_i386=		SSE
OPTIONS_DEFAULT=		AAD_JSONC CUPS GSSAPI_HEIMDAL ICU MANPAGES SDL \
				SWSCALE WAYLAND WEBKIT X11
OPTIONS_DEFAULT_aarch64=	NEON
OPTIONS_DEFAULT_amd64=		SSE
OPTIONS_DEFAULT_armv7=		NEON
OPTIONS_GROUP=			CLIPBOARD_IMAGE
OPTIONS_GROUP_CLIPBOARD_IMAGE=  JPEG_CB PNG WEBP
OPTIONS_RADIO=			AAD GSSAPI SCALE WEBVIEW
OPTIONS_RADIO_AAD=		AAD_CJSON AAD_JSONC
OPTIONS_RADIO_GSSAPI=		GSSAPI_HEIMDAL GSSAPI_MIT
OPTIONS_RADIO_SCALE=		CAIRO SWSCALE
OPTIONS_RADIO_WEBVIEW=		WEBENGINE WEBKIT
OPTIONS_SUB=			yes

AAD_CJSON_DESC=		Use cJSON library (devel/libcjson)
AAD_DESC=		Compile with support for Azure AD authentication (require SDL)
AAD_JSONC_DESC=		Use JSON-C library (devel/json-c)
BROKENFOCUS_DESC=	Work around focus bug in some WMs (PR \#254908)
CAIRO_DESC=		Use CAIRO image library for screen resizing
CLIPBOARD_IMAGE_DESC=	Add "to/from" BMP conversion support to clipboard (experimental)
JPEG_CB_DESC=		${JPEG_DESC}
NEON_DESC=		Enable Media Processing Engine instructions
OPENH264_DESC=		H.264 video codec support via OpenH264
PCSC_DESC=		Smart card support (smart card device redirection)
PKCS11_DESC=		Use security/pkcs11-helper
SDL_DESC=		Build FreeRDP SDL client
SWSCALE_DESC=		Use SWScale image library for screen resizing (recommended)
URIPARSER_DESC=		Use uriparser RFC 3986 URI parsing library to handle URIs
WAYLAND_DESC=		Build FreeRDP Wayland client
WEBVIEW_DESC=		Build with WebView support for AAD login popup browser
X11_DESC=		Build FreeRDP X11 client

AAD_CJSON_IMPLIES=	SDL
AAD_CJSON_LIB_DEPENDS=	libcjson.so:devel/libcjson \
			libcjson_utils.so:devel/libcjson
AAD_CJSON_CMAKE_BOOL=	WITH_AAD WITH_CJSON_REQUIRED

AAD_JSONC_IMPLIES=	${AAD_CJSON_IMPLIES}
AAD_JSONC_LIB_DEPENDS=	libjson-c.so:devel/json-c
AAD_JSONC_CMAKE_BOOL=	WITH_AAD WITH_JSONC_REQUIRED

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	WITH_ALSA

BROKENFOCUS_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-focusbug.diff

CAIRO_USES=		gnome
CAIRO_USE=		gnome=cairo
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

GSSAPI_HEIMDAL_USES=	gssapi:heimdal
GSSAPI_MIT_USES=	gssapi:mit

ICU_LIB_DEPENDS=	libicuuc.so:devel/icu
ICU_CMAKE_ON=		-DWITH_UNICODE_BUILTIN=OFF
ICU_CMAKE_OFF=		-DWITH_UNICODE_BUILTIN=ON

JPEG_USES=		jpeg
JPEG_CMAKE_BOOL=	WITH_JPEG

JPEG_CB_USES=		jpeg
JPEG_CB_CMAKE_BOOL=	WINPR_UTILS_IMAGE_JPEG

LAME_LIB_DEPENDS=	libmp3lame.so:audio/lame
LAME_CMAKE_BOOL=	WITH_LAME

MANPAGES_BUILD_DEPENDS=	xmlto:textproc/xmlto
MANPAGES_CMAKE_BOOL=	WITH_MANPAGES

NEON_CMAKE_BOOL=	WITH_NEON

OPENH264_LIB_DEPENDS=	libopenh264.so:multimedia/openh264
OPENH264_CMAKE_BOOL=	WITH_OPENH264

OPUS_LIB_DEPENDS=	libopus.so:audio/opus
OPUS_CMAKE_BOOL=	WITH_OPUS

# LoadLibraryA("libpcsclite.so")
PCSC_RUN_DEPENDS=	${LOCALBASE}/lib/libpcsclite.so:devel/pcsc-lite
PCSC_CMAKE_BOOL=	WITH_PCSC

PKCS11_BUILD_DEPENDS=	${LOCALBASE}/include/pkcs11-helper-1.0/pkcs11.h:security/pkcs11-helper
PKCS11_CMAKE_BOOL=	WITH_PKCS11

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CMAKE_BOOL=		WINPR_UTILS_IMAGE_PNG

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	WITH_PULSE

SDL_USES=		sdl
SDL_USE=		sdl=sdl2,ttf2,image2
SDL_CMAKE_BOOL=		WITH_CLIENT_SDL WITH_SDL_IMAGE_DIALOGS

SOXR_LIB_DEPENDS=	libsoxr.so:audio/libsoxr
SOXR_CMAKE_BOOL=	WITH_SOXR

SSE_CMAKE_BOOL=		WITH_SSE2

SWSCALE_LIB_DEPENDS=	libswscale.so:multimedia/ffmpeg
SWSCALE_CMAKE_BOOL=	WITH_SWSCALE

URIPARSER_LIB_DEPENDS=	liburiparser.so:net/uriparser
URIPARSER_CMAKE_BOOL=	WITH_URIPARSER

WAYLAND_CATEGORIES=	wayland
WAYLAND_BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto \
			wayland-scanner:graphics/wayland
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
			libwayland-cursor.so:graphics/wayland \
			libxkbcommon.so:x11/libxkbcommon
WAYLAND_RUN_DEPENDS=	wayland-scanner:graphics/wayland
WAYLAND_CMAKE_BOOL=	WITH_WAYLAND

WEBENGINE_USES_=	qt:5
WEBENGINE_USE_QT=	core declarative gui location network printsupport \
			webchannel webengine widgets buildtools:build qmake:build
WEBENGINE_CMAKE_BOOL=	WITH_WEBVIEW_QT
WEBENGINE_CMAKE_ON=	-DWITH_WEBVIEW:BOOL=ON

WEBKIT_LIB_DEPENDS_=	libsoup-2.4.so:devel/libsoup \
			libharfbuzz.so:print/harfbuzz \
			libwebkit2gtk-4.0.so:www/webkit2-gtk3
WEBKIT_USES_=		gettext gnome
WEBKIT_USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 pango
WEBKIT_CMAKE_ON=	-DWITH_WEBVIEW:BOOL=ON

WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_CMAKE_BOOL=	WINPR_UTILS_IMAGE_WEBP

X11_USE=		xorg=xcursor,xfixes,xi,xinerama,xkbfile,xorgproto,xrandr,xrender,xv
X11_CMAKE_ON=		-DWITH_X11:BOOL=ON -DWITH_XCURSOR:BOOL=ON \
			-DWITH_XEXT:BOOL=ON -DWITH_XFIXES:BOOL=ON \
			-DWITH_XI:BOOL=ON -DWITH_XINERAMA:BOOL=ON \
			-DWITH_XKBFILE:BOOL=ON -DWITH_XRANDR:BOOL=ON \
			-DWITH_XRENDER:BOOL=ON -DWITH_XSHM:BOOL=ON \
			-DWITH_XV:BOOL=ON
X11_CMAKE_OFF=		-DWITH_X11:BOOL=OFF -DWITH_XKBFILE:BOOL=OFF

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAAD_CJSON} || ${PORT_OPTIONS:MAAD_JSONC}
.  if ${PORT_OPTIONS:MWEBENGINE}
USES+=		${WEBENGINE_USES_}
USE_QT+=	${WEBENGINE_USE_QT}
.  elif ${PORT_OPTIONS:MWEBKIT}
LIB_DEPENDS+=	${WEBKIT_LIB_DEPENDS_}
USES+=		${WEBKIT_USES_}
USE_GNOME+=	${WEBKIT_USE_GNOME}
.  else
CMAKE_OFF+=	WITH_WEBVIEW
.  endif
.else
CMAKE_OFF+=	WITH_WEBVIEW
.endif

.if ${PORT_OPTIONS:MGSSAPI_HEIMDAL} || ${PORT_OPTIONS:MGSSAPI_MIT}
CMAKE_ON+=	WITH_KRB5
.else
CMAKE_OFF+=	WITH_KRB5
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|gsm/gsm.h|gsm.h|' \
		${WRKSRC}/cmake/FindGSM.cmake \
		${WRKSRC}/libfreerdp/codec/dsp.c

pre-configure:
	${CP} ${FILESDIR}/mntent.h ${WRKSRC}/winpr/include
	${CP} ${FILESDIR}/mntent_compat.c ${WRKSRC}/channels/rdpdr/client

.include <bsd.port.mk>
