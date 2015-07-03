# $FreeBSD$

PORTNAME=	obs-studio
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Open Broadcaster Software Multiplatform

LICENSE=	GPLv2

LIB_DEPENDS=	libsysinfo.so:${PORTSDIR}/devel/libsysinfo \
		libx264.so:${PORTSDIR}/multimedia/libx264 \
		libv4l2.so:${PORTSDIR}/multimedia/libv4l \
		libpulse.so:${PORTSDIR}/audio/pulseaudio \
		libavcodec.so:${PORTSDIR}/multimedia/ffmpeg \
		libfdk-aac.so:${PORTSDIR}/audio/fdk-aac
BUILD_DEPENDS=	v4l_compat>=0:${PORTSDIR}/multimedia/v4l_compat

BROKEN_FreeBSD_9=	does not build

USE_XORG=	x11 xcomposite xdamage xrender
USE_XCB=	x11extras wm
USE_LDCONFIG=	yes
USE_GL+=	gl
USE_QT5=	core dbus gui opengl network svg multimedia \
		imageformats buildtools qmake x11extras
CFLAGS+=	-fPIC
LDFLAGS+=	-lsysinfo
USES=		cmake compiler:c11
CMAKE_ARGS+=	-DUNIX_STRUCTURE=1 \
		-DOBS_VERSION_OVERRIDE=${PORTVERSION}
INSTALLS_ICONS=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	jp9000

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||' \
		${CONFIGURE_WRKSRC}/deps/glad/CMakeLists.txt

.include <bsd.port.mk>
