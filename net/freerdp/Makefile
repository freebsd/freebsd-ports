# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freerdp
PORTVERSION=	1.2.0
PORTREVISION=	6
CATEGORIES=	net comms ipv6

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free implementation of Remote Desktop Protocol

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_OPENSSL=	yes
USE_LDCONFIG=	yes
USES=		alias cmake:outsource cpe execinfo pkgconfig compiler:c++11-lib
USE_GITHUB=	yes
GH_ACCOUNT=	FreeRDP
GH_PROJECT=	${GH_ACCOUNT}
GH_TAGNAME=	f5ff6e1

CPE_VENDOR=	freerdp_project

LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${WRKSRC}/include -I${WRKSRC}/winpr/include -I${LOCALBASE}/include

OPTIONS_DEFINE=		ALSA CUPS DIRECTFB FFMPEG GSTREAMER PULSEAUDIO SSE X11
OPTIONS_DEFAULT=	CUPS GSTREAMER X11
OPTIONS_SUB=		yes

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_ON=		-DWITH_ALSA=ON
ALSA_CMAKE_OFF=		-DWITH_ALSA=OFF

CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_CMAKE_ON=		-DWITH_CUPS=ON
CUPS_CMAKE_OFF=		-DWITH_CUPS=OFF

# outdated and unmaintained upstream
DIRECTFB_DESC=		Build FreeRDP DirectFB client (outdated)
DIRECTFB_LIB_DEPENDS=	libdirectfb.so:devel/directfb
DIRECTFB_CMAKE_ON=	-DWITH_DIRECTFB=ON
DIRECTFB_CMAKE_OFF=	-DWITH_DIRECTFB=OFF
# currently DirectFB option fails with clang
DIRECTFB_USE=		gcc=yes

FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
			libavutil.so:multimedia/ffmpeg
FFMPEG_CMAKE_ON=	-DWITH_FFMPEG=ON
FFMPEG_CMAKE_OFF=	-DWITH_FFMPEG=OFF

GSTREAMER_CMAKE_ON=	-DWITH_GSTREAMER_1_0=ON -DWITH_GSTREAMER_0_10=OFF
GSTREAMER_CMAKE_OFF=	-DWITH_GSTREAMER_1_0=OFF -DWITH_GSTREAMER_0_10=OFF
GSTREAMER_USE=		gstreamer1=yes xorg=x11,xextproto,xext,xrandr

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_ON=	-DWITH_PULSE=ON
PULSEAUDIO_CMAKE_OFF=	-DWITH_PULSE=OFF

SSE_CMAKE_ON=		-DWITH_SSE2=ON
SSE_CMAKE_OFF=		-DWITH_SSE2=OFF

X11_DESC=		Build FreeRDP X11 client
X11_BUILD_DEPENDS=	xmlto:textproc/xmlto
X11_CMAKE_ON=		-DWITH_X11=ON
X11_CMAKE_OFF=		-DWITH_X11=OFF -DWITH_XKBFILE=OFF
X11_USE=		xorg=x11,xkbfile,xcursor,xextproto,xv,xinerama,xext,xcursor,xrandr,xi,xfixes

.include <bsd.port.options.mk>

post-extract:
	${REINPLACE_CMD} -e 's|$${CMAKE_INSTALL_LIBDIR}/pkgconfig|libdata/pkgconfig|' \
		-e '/CMAKE_INSTALL_RPATH /d' \
		${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e 's|share/man/man1|man/man1|' \
		${WRKSRC}/client/X11/CMakeLists.txt
	${REINPLACE_CMD} -e 's/NetBSD__)/NetBSD__) || defined(__FreeBSD__)/' \
		${WRKSRC}/winpr/libwinpr/utils/trio/triodef.h
	${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|' \
		${WRKSRC}/channels/drive/client/statvfs.c
.include <bsd.port.mk>
