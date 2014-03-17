# $FreeBSD$

PORTNAME=	libva-vdpau-driver
PORTVERSION=	0.7.4
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://www.freedesktop.org/software/vaapi/releases/${PORTNAME}/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	VDPAU-based backend for VAAPI

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LIB_DEPENDS=	libvdpau.so:${PORTSDIR}/multimedia/libvdpau
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/libva.pc:${PORTSDIR}/multimedia/libva \
		${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat

LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
USES=		gmake pkgconfig tar:bzip2
USE_GL=		gl

GNU_CONFIGURE=	yes
CPPFLAGS+=	-isystem${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DEBUG
DEBUG_CONFIGURE_ENABLE=	debug

.include <bsd.port.pre.mk>

.if defined(STRIP) && ${STRIP} != ""
INSTALL_TARGET=	install-strip
.endif

post-patch:	.SILENT
	${REINPLACE_CMD} -e '/LIBS/{ s/-ldl//; \
		s/-lrt//; s/-lpthread/${PTHREAD_LIBS}/; }' \
		-e 's|driverdir|& --define-variable prefix=${PREFIX}|' \
		-e '/\^vdpau_version/s|$$CC -E|& ${CPPFLAGS}|' \
		 ${WRKSRC}/configure

.include <bsd.port.post.mk>
