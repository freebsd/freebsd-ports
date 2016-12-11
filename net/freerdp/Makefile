# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freerdp
PORTVERSION=	2.0.0.g2016.11.24
PORTREVISION=	2
CATEGORIES=	net comms ipv6

MAINTAINER=	bsdports@kyle-evans.net
COMMENT=	Free implementation of Remote Desktop Protocol

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	FreeRDP
GH_PROJECT=	${GH_ACCOUNT}
GH_TAGNAME=	2a6dbab

USES=		alias cmake:outsource compiler:c++11-lib cpe execinfo gettext localbase pathfix pkgconfig ssl
USE_LDCONFIG=	yes
CPE_VENDOR=	freerdp_project

CMAKE_ARGS+=	-DWITH_LIBSYSTEMD=OFF -DWITH_WAYLAND=OFF -DWITH_GSTREAMER_0_10=OFF ${CMAKE_ARGS_${ARCH}}

CMAKE_ARGS_aarch64=	-DWITH_NEON=ON
CFLAGS_aarch64=		-D__ARM_NEON__=__ARM_NEON # clang

OPTIONS_DEFINE=		ALSA CUPS FFMPEG GSTREAMER PULSEAUDIO SSE X11
OPTIONS_DEFAULT=	CUPS GSTREAMER X11
OPTIONS_SUB=		yes

OPTIONS_DEFINE_armv6=	NEON
OPTIONS_EXCLUDE_armv6=	SSE

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	WITH_ALSA

CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_CMAKE_BOOL=	WITH_CUPS

FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
			libavutil.so:multimedia/ffmpeg
FFMPEG_CMAKE_BOOL=	WITH_FFMPEG

GSTREAMER_CMAKE_BOOL=	WITH_GSTREAMER_1_0
GSTREAMER_USE=		gnome=glib20 gstreamer1=yes xorg=x11,xextproto,xext,xrandr
GSTREAMER_LIB_DEPENDS=	libgstbase-1.0.so:multimedia/gstreamer1

NEON_DESC=		Enable	Media Processing Engine instructions
NEON_CMAKE_BOOL=	WITH_NEON
.if ! ${CFLAGS:M-march*}
NEON_CFLAGS=		-march=armv7-a
.endif

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	WITH_PULSE

SSE_CMAKE_BOOL=		WITH_SSE2

X11_DESC=		Build FreeRDP X11 client
X11_BUILD_DEPENDS=	xmlto:textproc/xmlto
X11_CMAKE_BOOL=		WITH_X11
X11_CMAKE_OFF=		-DWITH_XKBFILE=OFF
X11_USE=		xorg=x11,xkbfile,xcursor,xextproto,xv,xinerama,xext,xrandr,xi,xfixes,xrender

.include <bsd.port.pre.mk>

.if ${OPSYS} == "FreeBSD" && ${ARCH} == "armv6"
.if ${OSVERSION} < 1100500 || \
	(${OSVERSION} >= 1100500 && ${OSVERSION} < 1100504) || \
	(${OSVERSION} >= 1200000 && ${OSVERSION} < 1200008)
BROKEN=	Fails to build on ARMv6 (libm bug). See: r305380 (HEAD), r305971 (stable/11) [\#199422, \#211965] \
	Please update to a later (fixed) version.
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e '/CMAKE_INSTALL_RPATH /d' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's/OPENBSD/BSD/' \
		${WRKSRC}/winpr/CMakeLists.txt \
		${WRKSRC}/client/X11/CMakeLists.txt
	@${REINPLACE_CMD} -e 's/NetBSD__)/NetBSD__) || defined(__FreeBSD__)/' \
		${WRKSRC}/winpr/libwinpr/utils/trio/triodef.h
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|' \
		${WRKSRC}/channels/drive/client/statvfs.c
	@${RM} ${WRKSRC}/cmake/FindOpenSSL.cmake
	@${REINPLACE_CMD} -e 's|$${CMAKE_INSTALL_LIBDIR}/cmake|$${CMAKE_INSTALL_PREFIX}/share/cmake/Modules|' \
		${WRKSRC}/client/CMakeLists.txt \
		${WRKSRC}/winpr/CMakeLists.txt \
		${WRKSRC}/uwac/CMakeLists.txt \
		${WRKSRC}/server/CMakeLists.txt \
		${WRKSRC}/server/shadow/CMakeLists.txt \
		${WRKSRC}/libfreerdp/CMakeLists.txt

.include <bsd.port.post.mk>
