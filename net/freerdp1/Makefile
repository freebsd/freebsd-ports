# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freerdp
PORTVERSION=	1.2.0
CATEGORIES=	net comms ipv6
PKGNAMESUFFIX=	1

MAINTAINER=	bsdports@kyle-evans.net
COMMENT=	Free implementation of Remote Desktop Protocol

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_LDCONFIG=	yes
USES=		alias cmake:outsource cpe execinfo pathfix pkgconfig compiler:c++11-lib ssl
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
X11_USE=		xorg=x11,xkbfile,xcursor,xextproto,xv,xinerama,xext \
			xcursor,xrandr,xi,xfixes,xrender

.include <bsd.port.options.mk>

post-patch:
	@${FIND} ${WRKSRC} -name 'CMakeLists.txt' | ${XARGS} \
		${REINPLACE_CMD} \
				-e 's|list(APPEND $${MODULE_PREFIX}_LIBS freerdp)|list(APPEND $${MODULE_PREFIX}_LIBS freerdp1)|' \
				-e 's|list(APPEND $${MODULE_PREFIX}_LIBS winpr)|list(APPEND $${MODULE_PREFIX}_LIBS winpr1)|'
	@${FIND} ${WRKSRC} -name 'CMakeLists.txt' | ${XARGS} \
		${REINPLACE_CMD} -E \
				-e 's|freerdp winpr|freerdp1 winpr1|' \
				-e 's|winpr freerdp|winpr1 freerdp1|' \
				-e 's|-lwinpr|-lwinpr1|' \
				-e 's|-lfreerdp|-lfreerdp1|' \
				-e 's|^([[:blank:]]*)target_link_libraries\((.+) freerdp\)([[:blank:]]*)$$|\1target_link_libraries(\2 freerdp1)\3|' \
				-e 's|^([[:blank:]]*)target_link_libraries\((.+) winpr\)([[:blank:]]*)$$|\1target_link_libraries(\2 winpr1)\3|' \
				-e 's|^([[:blank:]]*)set\((.+) freerdp (.+) winpr\)([[:blank:]]*)$$|\1set(\2 freerdp1 \3 winpr1)\4|' \
				-e 's|^([[:blank:]]*)set\((.+) winpr\)([[:blank:]]*)$$|\1set(\2 winpr1)\3|'
	@${REINPLACE_CMD} -e 's|share/man/man1|man/man1|' \
		${WRKSRC}/client/X11/CMakeLists.txt
	@${REINPLACE_CMD} -e 's/NetBSD__)/NetBSD__) || defined(__FreeBSD__)/' \
		${WRKSRC}/winpr/libwinpr/utils/trio/triodef.h
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|' \
		${WRKSRC}/channels/drive/client/statvfs.c
	@${REINPLACE_CMD} -e 's|$${CMAKE_INSTALL_LIBDIR}/cmake|$${CMAKE_INSTALL_PREFIX}/share/cmake/Modules|' \
		${WRKSRC}/winpr/CMakeLists.txt \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
