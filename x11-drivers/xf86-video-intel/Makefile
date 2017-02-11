# Created by: lesi@FreeBSD.org
# $FreeBSD$

PORTNAME=	xf86-video-intel
PORTVERSION=	2.99.917.20170103
CATEGORIES=	x11-drivers
MASTER_SITES=	http://cgit.freedesktop.org/xorg/${XORG_CAT}/${PORTNAME}/snapshot/
DISTNAME=	${PORTNAME}-${COMMIT_ID}

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Driver for Intel integrated graphics chipsets

LIB_DEPENDS=	libxcb-util.so:x11/xcb-util \
		libdrm.so:graphics/libdrm

COMMIT_ID=	028c946df0855728b2a34d1d588701dc6c5ad4c1

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Intel integrated GPU only exists in Intel x86 processors/chipsets

USE_GL=		gl

USE_LDCONFIG=	yes
XORG_CAT=	driver
USE_XORG=	pciaccess pixman x11 xcb xext xrender xv xvmc

USES+=		cpe autoreconf
CPE_VENDOR=	x

CONFIGURE_ARGS+=	--with-default-accel=uxa

.include <bsd.port.mk>
