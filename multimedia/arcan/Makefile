PORTNAME=	arcan
DISTVERSION=	0.7.0.1
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	hoanga@gmail.com	
COMMENT=	Display Server, Multimedia Framework, Game Engine
WWW=		https://arcan-fe.com/

LICENSE=	BSD3CLAUSE GPLv2+ LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC:H}/data/distr/LICENSE.BSD
LICENSE_FILE_GPLv2+ =	${WRKSRC:H}/data/distr/LICENSE.GPL
LICENSE_FILE_LGPL21+ =	${WRKSRC:H}/data/distr/LICENSE.LGPL

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
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
CMAKE_ARGS=	-DDISTR_TAG:STRING="portbld" \
		-DENGINE_BUILDTAG:STRING="${DISTVERSIONFULL}" \
		-DMAN_DEST=share/man/man1 \
		-DAPIMAN_DEST=share/man/man3
LDFLAGS+=	-Wl,--as-needed # bzip2, ffmpeg, librt, libutil, lzma, zlib
LDFLAGS_i386=	-Wl,-z,notext

OPTIONS_DEFINE=	ESPEAK FFMPEG HUNSPELL LUAJIT MANPAGES SDL SUID TESSERACT UVC VLC VNC WAYLAND
OPTIONS_DEFAULT=ESPEAK FFMPEG HUNSPELL LUAJIT MANPAGES SDL SUID TESSERACT UVC VLC VNC WAYLAND
OPTIONS_SUB=	yes

ESPEAK_LIB_DEPENDS=	libespeak-ng.so:audio/espeak-ng
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
HUNSPELL_LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell

MANPAGES_USES=		ruby:build

LUAJIT_DESC=		Use LuaJIT instead of standard Lua
LUAJIT_USES=		luajit
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

WAYLAND_CATEGORIES=	wayland
WAYLAND_BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-server.so:graphics/wayland \
			libxcb-icccm.so:x11/xcb-util-wm \
			libxkbcommon.so:x11/libxkbcommon
WAYLAND_RUN_DEPENDS=	Xwayland:x11-servers/xwayland
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

pre-configure-MANPAGES-on:
	@${RUBY} -C ${WRKSRC:H}/doc -Ku docgen.rb mangen 2>/dev/null

post-patch-ESPEAK-off:
	@${REINPLACE_CMD} -i.noespeak '/find.*Espeak/d' \
		${WRKSRC}/frameserver/decode/default/CMakeLists.txt

post-patch-FFMPEG-off:
	@${REINPLACE_CMD} -i.noffmpeg '/pkg.*FFMPEG/d' \
		${WRKSRC}/a12/CMakeLists.txt \
		${WRKSRC}/frameserver/decode/default/CMakeLists.txt \
		${WRKSRC}/frameserver/encode/default/CMakeLists.txt

post-patch-HUNSPELL-off:
	@${REINPLACE_CMD} -i.nohunspell '/pkg.*HUNSPELL/d' \
		${WRKSRC}/frameserver/decode/default/CMakeLists.txt

post-patch-TESSERACT-off:
	@${REINPLACE_CMD} -i.notesseract '/pkg.*tesseract/d' \
		${WRKSRC}/frameserver/encode/default/CMakeLists.txt

post-patch-VNC-off:
	@${REINPLACE_CMD} -i.novnc '/pkg.*libvnc/d' \
		${WRKSRC}/frameserver/encode/default/CMakeLists.txt \
		${WRKSRC}/frameserver/remoting/default/CMakeLists.txt

.include <bsd.port.mk>
