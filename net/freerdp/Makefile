# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freerdp
PORTVERSION=	1.1.0.b20130711
DISTVERSION=	1.1.0-beta+2013071101
CATEGORIES=	net comms ipv6

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	A free implementation of Remote Desktop Protocol

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_OPENSSL=	yes
USE_LDCONFIG=	yes
USES=		cmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	FreeRDP
GH_PROJECT=	FreeRDP
GH_COMMIT=	780d451
GH_TAGNAME=	${GH_COMMIT}

LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${WRKSRC}/include -I${LOCALBASE}/include

OPTIONS_DEFINE=	ALSA CUPS DIRECTFB FFMPEG GSTREAMER PULSEAUDIO SSE X11
OPTIONS_DEFAULT=	CUPS GSTREAMER PULSEAUDIO X11
X11_DESC=	Build FreeRDP X11 client
DIRECTFB_DESC=	Build FreeRDP DirectFB client

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USE_XORG=	x11 xkbfile xcursor xextproto xv xinerama xext xcursor
CMAKE_ARGS+=	-DWITH_X11=ON
BUILD_DEPENDS+=	xmlto:${PORTSDIR}/textproc/xmlto
MAN1=		xfreerdp.1
PLIST_SUB+=	X11=""
.else
CMAKE_ARGS+=	-DWITH_X11=OFF -DWITH_XKBFILE=OFF
PLIST_SUB+=	X11="@comment "
.endif

.if ${PORT_OPTIONS:MDIRECTFB}
LIB_DEPENDS+=	libdirectfb.so:${PORTSDIR}/devel/directfb
CMAKE_ARGS+=	-DWITH_DIRECTFB=ON
PLIST_SUB+=	DIRECTFB=""
# currently DirectFB option fails with clang
USE_GCC=	yes
.else
PLIST_SUB+=	DIRECTFB="@comment "
.endif

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	libasound.so:${PORTSDIR}/audio/alsa-lib
PLIST_SUB+=	ALSA=""
.else
PLIST_SUB+=	ALSA="@comment "
CMAKE_ARGS+=	-DWITH_ALSA=OFF
.endif

.if ${PORT_OPTIONS:MFFMPEG}
LIB_DEPENDS+=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg \
		libavutil.so:${PORTSDIR}/multimedia/ffmpeg
PLIST_SUB+=	FFMPEG=""
.else
CMAKE_ARGS+=	-DWITH_FFMPEG=OFF
PLIST_SUB+=	FFMPEG="@comment "
.endif

.if ${PORT_OPTIONS:MGSTREAMER}
CMAKE_ARGS+=	-DWITH_GSTREAMER=ON
USE_GSTREAMER=	yes
.else
CMAKE_ARGS+=	-DWITH_GSTREAMER=OFF
.endif

.if ${PORT_OPTIONS:MCUPS}
CMAKE_ARGS+=	-DWITH_CUPS=ON
LIB_DEPENDS+=	libcups.so:${PORTSDIR}/print/cups-client
.else
CMAKE_ARGS+=	-DWITH_CUPS=OFF
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
CMAKE_ARGS+=	-DWITH_PULSE=ON
LIB_DEPENDS+=	libpulse.so:${PORTSDIR}/audio/pulseaudio
PLIST_SUB+=	PULSE=""
.else
PLIST_SUB+=	PULSE="@comment "
CMAKE_ARGS+=	-DWITH_PULSE=OFF
.endif

.if ${PORT_OPTIONS:MSSE}
CMAKE_ARGS+=	-DWITH_SSE2=ON
.else
CMAKE_ARGS+=	-DWITH_SSE2=OFF
.endif

post-extract:
	${REINPLACE_CMD} -e 's|$${CMAKE_INSTALL_LIBDIR}/pkgconfig|libdata/pkgconfig|' \
		-e '/CMAKE_INSTALL_RPATH /d' \
		${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e 's|share/man/man1|man/man1|' \
		${WRKSRC}/client/X11/CMakeLists.txt
	${REINPLACE_CMD} -e 's|HW_AVAILCPU|HW_NCPU|' \
		${WRKSRC}/winpr/libwinpr/sysinfo/sysinfo.c
	${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|' \
		${WRKSRC}/winpr/libwinpr/crt/alignment.c \
		${WRKSRC}/channels/drive/client/statvfs.c
.include <bsd.port.mk>
