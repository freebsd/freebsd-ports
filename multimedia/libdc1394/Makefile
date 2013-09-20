# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	libdc1394
PORTVERSION=	2.2.0
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-2/${PORTVERSION}/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	1394-based DC Control Library

LICENSE=	LGPL21

GNU_CONFIGURE=	yes
USES=	pathfix
USE_LDCONFIG=	yes

MAN1=		dc1394_multiview.1 \
		dc1394_reset_bus.1 \
		dc1394_vloopback.1 \
		grab_color_image.1 \
		grab_gray_image.1 \
		grab_partial_image.1

NO_STAGE=	yes
.include <bsd.port.mk>
