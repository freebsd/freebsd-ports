# $FreeBSD$

PORTNAME=	arcan
DISTVERSION=	0.6.0.1
PORTREVISION=	3
CATEGORIES=	multimedia

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	347240c18313.patch:-p2 # https://github.com/letoram/arcan/pull/229
PATCHFILES+=	bbdb86c8be1b.patch:-p2 # https://github.com/letoram/arcan/pull/230

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Display Server, Multimedia Framework, Game Engine

LICENSE=	BSD3CLAUSE GPLv2+ LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC:H}/data/distr/LICENSE.BSD
LICENSE_FILE_GPLv2+ =	${WRKSRC:H}/data/distr/LICENSE.GPL
LICENSE_FILE_LGPL21+ =	${WRKSRC:H}/data/distr/LICENSE.LGPL

LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	mesa-dri>0:graphics/mesa-dri

USES=		cmake compiler:c11 gl iconv openal pkgconfig sqlite
USE_GITHUB=	yes
USE_GL=		egl gbm gl
USE_LDCONFIG=	yes
GH_ACCOUNT=	letoram
WRKSRC_SUBDIR=	src
CMAKE_ON=	HYBRID_HEADLESS
CMAKE_OFF=	STATIC_LIBUVC
CMAKE_ARGS=	-DENGINE_BUILDTAG:STRING="${DISTVERSIONFULL}"
LDFLAGS+=	-Wl,--as-needed # bzip2, ffmpeg, librt, libutil, lzma, zlib
LDFLAGS_i386=	-Wl,-z,notext

OPTIONS_DEFINE=	ESPEAK FFMPEG LUAJIT SDL SUID TESSERACT UVC VLC VNC WAYLAND
OPTIONS_DEFAULT=ESPEAK FFMPEG LUAJIT SDL SUID TESSERACT UVC VLC VNC WAYLAND
OPTIONS_SUB=	yes

ESPEAK_DESC=		Text to speech via eSpeak
ESPEAK_LIB_DEPENDS=	libespeak.so:audio/espeak

FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

LUAJIT_DESC=		Use LuaJIT instead of standard Lua
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:lang/luajit-openresty
LUAJIT_USES_OFF=	lua:51
LUAJIT_CMAKE_BOOL_OFF=	DISABLE_JIT

SDL_USES=		sdl
SDL_USE=		SDL=sdl2
SDL_CMAKE_BOOL=		HYBRID_SDL

SUID_DESC=		setuid bit on "${PORTNAME}" binary
SUID_PLIST_SUB=		MAYBE_SUID="@(,,4755) "
SUID_PLIST_SUB_OFF=	MAYBE_SUID="@(,,0755) "

TESSERACT_DESC=		Optical Character Recognition via Tesseract
TESSERACT_LIB_DEPENDS=	libtesseract.so:graphics/tesseract

VLC_DESC=		Video decode via libvlc
VLC_LIB_DEPENDS=	libvlc.so:multimedia/vlc

UVC_DESC=		USB video cameras via libuvc
UVC_LIB_DEPENDS=	libuvc.so:multimedia/libuvc
UVC_CMAKE_BOOL=		FSRV_DECODE_UVC

VNC_DESC=		VNC client/server support
VNC_LIB_DEPENDS=	libvncserver.so:net/libvncserver

WAYLAND_BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-server.so:graphics/wayland \
			libxcb-icccm.so:x11/xcb-util-wm \
			libxkbcommon.so:x11/libxkbcommon
WAYLAND_RUN_DEPENDS=	xwayland-devel>0:x11-servers/xwayland-devel
WAYLAND_USES=		xorg
WAYLAND_USE=		XORG=xcb
WAYLAND_CMAKE_BOOL_OFF=	DISABLE_WAYLAND

post-patch:
	@${REINPLACE_CMD} -i.prefix 's,/usr/local,${PREFIX},g' \
		${WRKSRC:H}/doc/${PORTNAME}.1 \
		${WRKSRC}/engine/arcan_vr.c \
		${WRKSRC}/frameserver/decode/default/decode_av.c \
		${WRKSRC}/frameserver/terminal/default/arcterm.c \
		${WRKSRC}/frameserver/terminal/default/cli.c \
		${WRKSRC}/frameserver/terminal/default/cli_builtin.c \
		${WRKSRC}/platform/posix/paths.c \
		${WRKSRC}/shmif/arcan_shmif_debugif.c

post-patch-ESPEAK-off:
	@${REINPLACE_CMD} -i.noespeak '/find.*Espeak/d' \
		${WRKSRC}/frameserver/decode/default/CMakeLists.txt

post-patch-FFMPEG-off:
	@${REINPLACE_CMD} -i.noffmpeg '/pkg.*FFMPEG/d' \
		${WRKSRC}/a12/CMakeLists.txt \
		${WRKSRC}/frameserver/decode/default/CMakeLists.txt \
		${WRKSRC}/frameserver/encode/default/CMakeLists.txt

post-patch-TESSERACT-off:
	@${REINPLACE_CMD} -i.notesseract '/pkg.*tesseract/d' \
		${WRKSRC}/frameserver/encode/default/CMakeLists.txt

post-patch-VNC-off:
	@${REINPLACE_CMD} -i.novnc '/pkg.*libvnc/d' \
		${WRKSRC}/frameserver/encode/default/CMakeLists.txt \
		${WRKSRC}/frameserver/remoting/default/CMakeLists.txt

.include <bsd.port.mk>
