# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freerdp
PORTVERSION=	1.1.0
DISTVERSIONSUFFIX=	-beta+2013071101
PORTREVISION=	1
CATEGORIES=	net comms ipv6

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Free implementation of Remote Desktop Protocol

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_OPENSSL=	yes
USE_LDCONFIG=	yes
USES=		cmake:outsource pkgconfig compiler:c++11-lib
USE_GITHUB=	yes
GH_ACCOUNT=	FreeRDP
GH_PROJECT=	FreeRDP
GH_COMMIT=	780d451
GH_TAGNAME=	${GH_COMMIT}

LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${WRKSRC}/include -I${LOCALBASE}/include

OPTIONS_DEFINE=		ALSA CUPS DIRECTFB FFMPEG GSTREAMER PULSEAUDIO SSE X11
OPTIONS_DEFAULT=	CUPS GSTREAMER X11
OPTIONS_SUB=		yes

ALSA_LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib
ALSA_CMAKE_ON=		-DWITH_ALSA=ON
ALSA_CMAKE_OFF=		-DWITH_ALSA=OFF

CUPS_LIB_DEPENDS=	libcups.so:${PORTSDIR}/print/cups-client
CUPS_CMAKE_ON=		-DWITH_CUPS=ON
CUPS_CMAKE_OFF=		-DWITH_CUPS=OFF

# outdated and unmaintained upstream
DIRECTFB_DESC=		Build FreeRDP DirectFB client (outdated)
DIRECTFB_LIB_DEPENDS=	libdirectfb.so:${PORTSDIR}/devel/directfb
DIRECTFB_CMAKE_ON=	-DWITH_DIRECTFB=ON
DIRECTFB_CMAKE_OFF=	-DWITH_DIRECTFB=OFF
# currently DirectFB option fails with clang
DIRECTFB_USE=		gcc=yes

FFMPEG_LIB_DEPENDS=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg \
			libavutil.so:${PORTSDIR}/multimedia/ffmpeg
FFMPEG_CMAKE_ON=	-DWITH_FFMPEG=ON
FFMPEG_CMAKE_OFF=	-DWITH_FFMPEG=OFF

GSTREAMER_CMAKE_ON=	-DWITH_GSTREAMER=ON
GSTREAMER_CMAKE_OFF=	-DWITH_GSTREAMER=OFF
GSTREAMER_USE=		gstreamer=yes xorg=x11,xextproto,xext,xrandr

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_CMAKE_ON=	-DWITH_PULSE=ON
PULSEAUDIO_CMAKE_OFF=	-DWITH_PULSE=OFF

SSE_CMAKE_ON=		-DWITH_SSE2=ON
SSE_CMAKE_OFF=		-DWITH_SSE2=OFF

X11_DESC=		Build FreeRDP X11 client
X11_BUILD_DEPENDS=	xmlto:${PORTSDIR}/textproc/xmlto
X11_CMAKE_ON=		-DWITH_X11=ON
X11_CMAKE_OFF=		-DWITH_X11=OFF -DWITH_XKBFILE=OFF
X11_USE=		xorg=x11,xkbfile,xcursor,xextproto,xv,xinerama,xext,xcursor,xrandr

.include <bsd.port.options.mk>

post-extract:
	${REINPLACE_CMD} -e 's|$${CMAKE_INSTALL_LIBDIR}/pkgconfig|libdata/pkgconfig|' \
		-e '/CMAKE_INSTALL_RPATH /d' \
		${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e 's|share/man/man1|man/man1|' \
		${WRKSRC}/client/X11/CMakeLists.txt
	${REINPLACE_CMD} -e 's|HW_AVAILCPU|HW_NCPU|' \
		${WRKSRC}/winpr/libwinpr/sysinfo/sysinfo.c
	${REINPLACE_CMD} -e 's/NetBSD__)/NetBSD__) || defined(__FreeBSD__)/' \
		${WRKSRC}/winpr/libwinpr/utils/trio/triodef.h
	${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|' \
		${WRKSRC}/winpr/libwinpr/crt/alignment.c \
		${WRKSRC}/channels/drive/client/statvfs.c
.include <bsd.port.mk>
