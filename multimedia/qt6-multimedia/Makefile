PORTNAME=	multimedia
DISTVERSION=	${QT6_VERSION}
PORTREVISION=	1
CATEGORIES=	multimedia
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt audio, video, radio and camera support module

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++17-lang gl localbase:ldflags pkgconfig qt-dist:6
USE_GL=		opengl
USE_QT=		base declarative shadertools:build
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

CFLAGS_powerpc=		-DPFFFT_SIMD_DISABLE
CXXFLAGS_powerpc64=	-mvsx

OPTIONS_DEFINE=		FFMPEG GSTREAMER PIPEWIRE Q3D V4L VAAPI X11
OPTIONS_DEFAULT=	FFMPEG GSTREAMER PIPEWIRE PULSEAUDIO Q3D V4L VAAPI X11
AUDIO_DESC=		Low-level audio backend
OPTIONS_SINGLE=		AUDIO
OPTIONS_SINGLE_AUDIO=	ALSA PULSEAUDIO
OPTIONS_SUB=		yes

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_RUN_DEPENDS=	alsa-plugins>=0:audio/alsa-plugins
ALSA_CMAKE_BOOL=	FEATURE_alsa

FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CMAKE_BOOL=	FEATURE_ffmpeg

GSTREAMER_LIB_DEPENDS=	libdrm.so:graphics/libdrm \
			libwayland-client.so:graphics/wayland
# As of 2024-09-29, Mk/Uses/xorg.mk freaks out if no modules are defined
# via USE_XORG, so FTTB, we must duplicate USES=xorg in the GSTREAMER
# and X11 options and cannot hoist it to the main USES declaration as a
# noop.
GSTREAMER_USES=		gnome gstreamer:1 xorg
GSTREAMER_USE=		GL=egl \
			GNOME=glib20 \
			GSTREAMER=bad,gl,good,ugly,${"${PORT_OPTIONS:MALSA}":?alsa:pulse} \
			XORG=xcb
GSTREAMER_CMAKE_BOOL=	FEATURE_gstreamer \
			FEATURE_gstreamer_1_0 \
			FEATURE_gstreamer_app \
			FEATURE_gstreamer_gl \
			FEATURE_gstreamer_photography

PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_CMAKE_BOOL=	FEATURE_pipewire
PIPEWIRE_IMPLIES=	FFMPEG

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	FEATURE_pulseaudio

Q3D_DESC=		Spatial audio support via QtQuick3D
Q3D_USE=		QT=quick3d,shadertools
Q3D_CMAKE_BOOL=		FEATURE_spatialaudio_quick3d

V4L_BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
V4L_CMAKE_BOOL=		FEATURE_linux_v4l
V4L_IMPLIES=		${"${PORT_OPTIONS:MFFMPEG}":?FFMPEG:GSTREAMER}

VAAPI_LIB_DEPENDS=	libva.so:multimedia/libva
VAAPI_USE=		GL=egl
VAAPI_CMAKE_BOOL=	FEATURE_vaapi
VAAPI_IMPLIES=		FFMPEG

# We assume that the Qt stack has been built with consistent X11 options.
# QT_FEATURE_xlib is defined globally by devel/qt6-base based upon whether
# the X11 option was enabled in that port.
X11_USES=		xorg
X11_USE=		XORG=x11,xext,xrandr
X11_IMPLIES=		FFMPEG

.include <bsd.port.options.mk>

.if ${ARCH} == "i386" && ${MACHINE_CPU:Nsse}
CXXFLAGS+=	-DDISABLE_SIMD \
		-DPFFFT_SIMD_DISABLE
.endif

.include <bsd.port.mk>
