PORTNAME=	freerdp
DISTVERSION=	3.16.0
PORTREVISION=	1
CATEGORIES=	net comms
MASTER_SITES+=	https://pub.freerdp.com/releases/:freerdp \
		https://github.com/FreeRDP/FreeRDP/releases/download/${DISTVERSION}/:freerdp
PKGNAMESUFFIX=	3
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}:freerdp

PATCH_SITES=	https://github.com/FreeRDP/FreeRDP/commit/
PATCHFILES=	281b9245966f019a8aa0271a73acd8da8104baa9.patch:-p1 \
		6f03b25f8ec9320d10b3f3163543f8b6dd9ebc0c.patch:-p1 \
		5d32afcdd0b780d95b77c6005d1b79482884cd46.patch:-p1 \
		40c988e2da289e83081421942685a1a248f46603.patch:-p1 \
		8e38600298310bc74271fd99aca74c2d5a2d071c.patch:-p1 \
		4dc6091fde72a25dadcfed1f76c455cc9c3bf093.patch:-p1 \
		bee5edeb315336102f738a26a9bcff5b4d9ff03c.patch:-p1 \
		59bfe47ef7c0fa596edad0716aaf28782d9e857a.patch:-p1 \
		419ad81aa78d31394c8e8b8452b40ef842f48730.patch:-p1 \
		a86e3dc53c5cf4ba6879a4571b0610dddd224fbf.patch:-p1 \
		daeec1f98d69516fe52276608a750de3b3146d4e.patch:-p1 \
		efd89c035481088c5b352222fbeb0bfc69ac75fe.patch:-p1

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	Free implementation of Remote Desktop Protocol
WWW=		https://www.freerdp.com/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim

USES=		alias cmake compiler:c++11-lib cpe desktop-file-utils \
		localbase:ldflags pathfix pkgconfig ssl xorg

BROKEN_SSL=	libressl-devel
BROKEN_SSL_REASON_libressl-devel=	fails to compile: no member named 'alert_dispatch' in 'struct ssl3_state_st'

USE_GITHUB=	nodefault
GH_TUPLE=	akallabeth:webview:2a0a130:webview/../.build/_deps/webview-src
USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xext

CMAKE_ON=	CHANNEL_SERIAL CHANNEL_URBDRC_CLIENT RDTK_FORCE_STATIC_BUILD \
		UWAC_FORCE_STATIC_BUILD WITH_BINARY_VERSIONING WITH_CHANNELS \
		WITH_CLIENT_SDL_VERSIONED WITH_FREERDP_DEPRECATED \
		WITH_FREERDP_DEPRECATED_COMMANDLINE \
		WITH_INSTALL_CLIENT_DESKTOP_FILES WITH_OPENSSL WITH_OSS \
		WITH_WINPR_DEPRECATED WITH_ZLIB
CMAKE_OFF=	CHANNEL_TSMF WITH_DSP_EXPERIMENTAL WITH_FUSE WITH_GPROF \
		WITH_GSTREAMER_0_10 WITH_GSTREAMER_1_0 WITH_IPP WITH_LIBSYSTEMD \
		WITH_MBEDTLS WITH_OPENCL WITH_OPENSLES WITH_PROFILER WITH_SAMPLE \
		WITH_SANITIZE_ADDRESS WITH_SANITIZE_MEMORY WITH_SANITIZE_THREAD \
		WITH_SERVER WITH_SERVER_CHANNELS WITH_SERVER_INTERFACE \
		WITH_SMARTCARD_INSPECT WITH_THIRD_PARTY WITH_VALGRIND_MEMCHECK

PLIST_SUB+=	PATCHVERSION="${DISTVERSION}"
PLIST_SUB+=	MAJORVERSION="${DISTVERSION:R:R}"

OPTIONS_DEFINE=			ALSA BROKENFOCUS CUPS FAAC FAAD FDKAAC FFMPEG \
				GSM ICU JPEG LAME MANPAGES OPENH264 OPUS PCSC \
				PKCS11 PULSEAUDIO RDPECAM SDL2 SDL3 SOXR \
				URIPARSER WAYLAND WEBVIEW X11
OPTIONS_DEFINE_aarch64=		SIMD
OPTIONS_DEFINE_amd64=		SIMD
OPTIONS_DEFINE_armv7=		SIMD
OPTIONS_DEFINE_i386=		SIMD
OPTIONS_DEFAULT=		AAD CUPS FFMPEG GSSAPI_HEIMDAL ICU JSON_C \
				KEYBOARD_LAYOUT MANPAGES RDPECAM SDL2 SDL3 \
				SWSCALE TIMEZONE_FILE WAYLAND WEBVIEW X11
OPTIONS_DEFAULT_aarch64=	SIMD
OPTIONS_DEFAULT_amd64=		SIMD
OPTIONS_DEFAULT_armv7=		SIMD
OPTIONS_GROUP=			CLIPBOARD_IMAGE REQUIRE_JSON
OPTIONS_GROUP_CLIPBOARD_IMAGE=	JPEG_CB PNG WEBP
OPTIONS_GROUP_REQUIRE_JSON=	AAD KEYBOARD_LAYOUT TIMEZONE_FILE
OPTIONS_RADIO=			GSSAPI JSON SCALE
OPTIONS_RADIO_GSSAPI=		GSSAPI_HEIMDAL GSSAPI_MIT
OPTIONS_RADIO_JSON=		CJSON JSON_C
OPTIONS_RADIO_SCALE=		CAIRO SWSCALE
OPTIONS_SUB=			yes

AAD_DESC=		Compile with support for Azure AD authentication (require SDL and WEBVIEW)
BROKENFOCUS_DESC=	Work around focus bug in some WMs (PR \#254908)
CAIRO_DESC=		Use CAIRO image library for screen resizing
CJSON_DESC=		${JSON_DESC} via cJSON
CLIPBOARD_IMAGE_DESC=	Add "to/from" BMP conversion support to clipboard (experimental)
FDKAAC_DESC=		Support for FDK-AAC for sound and microphone redirection
JPEG_CB_DESC=		${JPEG_DESC}
KEYBOARD_LAYOUT_DESC=	Use keyboard definitions from JSON file
OPENH264_DESC=		H.264 video codec support via OpenH264
PCSC_DESC=		Smart card support (smart card device redirection)
PKCS11_DESC=		Use security/pkcs11-helper
RDPECAM_DESC=		RDP webcam redirection (require FFMPEG and SWSCALE)
REQUIRE_JSON_DESC=	Options that require JSON
SDL2_DESC=		Build FreeRDP SDL 2 client
SDL3_DESC=		Build FreeRDP SDL 3 client
SWSCALE_DESC=		Use SWScale image library for screen resizing (recommended)
TIMEZONE_FILE_DESC=	Support timezones as JSON resources (if OFF, compiled in is used)
URIPARSER_DESC=		Use uriparser RFC 3986 URI parsing library to handle URIs
WAYLAND_DESC=		Build FreeRDP Wayland client
WEBVIEW_DESC=		Build with WebView support for AAD login popup browser
X11_DESC=		Build FreeRDP X11 client

AAD_IMPLIES=		SDL3 WEBVIEW
AAD_CMAKE_BOOL=		WITH_AAD

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	WITH_ALSA

BROKENFOCUS_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-focusbug.diff

CAIRO_USES=		gnome
CAIRO_USE=		gnome=cairo
CAIRO_CMAKE_BOOL=	WITH_CAIRO

CJSON_LIB_DEPENDS=	libcjson.so:devel/libcjson \
			libcjson_utils.so:devel/libcjson
CJSON_CMAKE_BOOL=	WITH_CJSON_REQUIRED

CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_CMAKE_BOOL=	WITH_CUPS

FAAC_LIB_DEPENDS=	libfaac.so:audio/faac
FAAC_CMAKE_BOOL=	WITH_FAAC

FAAD_LIB_DEPENDS=	libfaad.so:audio/faad
FAAD_CMAKE_BOOL=	WITH_FAAD2

FDKAAC_LIB_DEPENDS=	libfdk-aac.so:audio/fdk-aac
FDKAAC_CMAKE_BOOL=	WITH_FDK_AAC

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

JSON_C_LIB_DEPENDS=	libjson-c.so:devel/json-c
JSON_C_CMAKE_BOOL=	WITH_JSONC_REQUIRED

KEYBOARD_LAYOUT_CMAKE_BOOL=	WITH_KEYBOARD_LAYOUT_FROM_FILE

LAME_LIB_DEPENDS=	libmp3lame.so:audio/lame
LAME_CMAKE_BOOL=	WITH_LAME

MANPAGES_CMAKE_BOOL=	WITH_MANPAGES

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

RDPECAM_IMPLIES=	FFMPEG SWSCALE
RDPECAM_BUILD_DEPENDS=	${LOCALBASE}/include/linux/uvcvideo.h:multimedia/v4l_compat \
			${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
RDPECAM_LIB_DEPENDS=	libv4l2.so:multimedia/libv4l \
			libv4lconvert.so:multimedia/libv4l
RDPECAM_CMAKE_BOOL=	CHANNEL_RDPECAM_CLIENT

SDL2_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader
SDL2_USES=		sdl
SDL2_USE=		sdl=sdl2,ttf2,image2
SDL2_CMAKE_BOOL=	WITH_CLIENT_SDL2 WITH_SDL_IMAGE_DIALOGS

SDL3_USES=		sdl
SDL3_USE=		sdl=sdl3,ttf3,image3
SDL3_CMAKE_BOOL=	WITH_CLIENT_SDL3 WITH_SDL_IMAGE_DIALOGS

SIMD_CMAKE_BOOL=	WITH_SIMD

SOXR_LIB_DEPENDS=	libsoxr.so:audio/libsoxr
SOXR_CMAKE_BOOL=	WITH_SOXR

SWSCALE_LIB_DEPENDS=	libswscale.so:multimedia/ffmpeg
SWSCALE_CMAKE_BOOL=	WITH_SWSCALE

TIMEZONE_FILE_CMAKE_BOOL=	WITH_TIMEZONE_FROM_FILE
TIMEZONE_FILE_CMAKE_ON=		-DWITH_TIMEZONE_COMPILED=OFF
TIMEZONE_FILE_CMAKE_OFF=	-DWITH_TIMEZONE_COMPILED=ON

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

WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_CMAKE_BOOL=	WINPR_UTILS_IMAGE_WEBP

WEBVIEW_LIB_DEPENDS=	libsoup-3.0.so:devel/libsoup3 \
			libharfbuzz.so:print/harfbuzz \
			libwebkitgtk-6.0.so:www/webkit2-gtk@60 \
			libgraphene-1.0.so:graphics/graphene
WEBVIEW_USES=		gnome
WEBVIEW_USE=		gnome=cairo,gdkpixbuf,glib20,gtk40,pango
WEBVIEW_CMAKE_BOOL=	WITH_WEBVIEW

X11_USE=		xorg=xcursor,xfixes,xi,xinerama,xkbfile,xorgproto,xrandr,xrender,xv
X11_CMAKE_ON=		-DWITH_X11:BOOL=ON -DWITH_XCURSOR:BOOL=ON \
			-DWITH_XEXT:BOOL=ON -DWITH_XFIXES:BOOL=ON \
			-DWITH_XI:BOOL=ON -DWITH_XINERAMA:BOOL=ON \
			-DWITH_XKBFILE:BOOL=ON -DWITH_XRANDR:BOOL=ON \
			-DWITH_XRENDER:BOOL=ON -DWITH_XSHM:BOOL=ON \
			-DWITH_XV:BOOL=ON
X11_CMAKE_OFF=		-DWITH_X11:BOOL=OFF -DWITH_XKBFILE:BOOL=OFF

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGSSAPI_HEIMDAL} || ${PORT_OPTIONS:MGSSAPI_MIT}
CMAKE_ON+=	WITH_KRB5
.else
CMAKE_OFF+=	WITH_KRB5
.endif

.if ${PORT_OPTIONS:MCJSON} || ${PORT_OPTIONS:MJSON_C}
CMAKE_ON+=	WITH_WINPR_JSON
CMAKE_OFF+=	WITH_JSON_DISABLED
PLIST_SUB+=	JSON=""
.else
CMAKE_ON+=	WITH_JSON_DISABLED
CMAKE_OFF+=	WITH_AAD WITH_WINPR_JSON
PLIST_SUB+=	JSON="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|gsm/gsm.h|gsm.h|' \
		${WRKSRC}/cmake/FindGSM.cmake \
		${WRKSRC}/libfreerdp/codec/dsp.c

pre-configure:
	${CP} ${FILESDIR}/mntent.h ${WRKSRC}/winpr/include
	${CP} ${FILESDIR}/mntent_compat.c ${WRKSRC}/channels/rdpdr/client

.include <bsd.port.mk>
