# $FreeBSD$

PORTNAME=	libva-vdpau-driver
PORTVERSION=	0.7.4
PORTREVISION=	9
CATEGORIES=	multimedia
MASTER_SITES=	http://www.freedesktop.org/software/vaapi/releases/${PORTNAME}/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	VDPAU-based backend for VAAPI

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LIB_DEPENDS=	libvdpau.so:multimedia/libvdpau
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/libva.pc:multimedia/libva \
		${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat

LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
USES=		libtool gl gmake localbase pkgconfig tar:bzip2
USE_GL=		gl

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PLIST_FILES=	lib/dri/nvidia_drv_video.so lib/dri/s3g_drv_video.so lib/dri/vdpau_drv_video.so

OPTIONS_DEFINE=	DEBUG

DEBUG_CONFIGURE_ENABLE=	debug

post-patch:	.SILENT
	${REINPLACE_CMD} -e '/LIBS/{ s/-ldl//; s/-lrt//; }' \
		-e 's|driverdir|& --define-variable prefix=${PREFIX}|' \
		-e '/\^vdpau_version/s|$$CC -E|& ${CPPFLAGS}|' \
		 ${WRKSRC}/configure

.include <bsd.port.mk>
