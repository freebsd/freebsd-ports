# New ports collection makefile for:	xf86-video-rdc
# Date created:				14 April 2010
# Whom:					stas
#
# $FreeBSD$
#

PORTNAME=	xf86-video-rdc
MASTER_SITES=	http://www.SpringDaemons.com/stas/
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	x11-drivers

MAINTAINER=	stas@FreeBSD.org
COMMENT=	X.Org RDC display driver

#USE_GL=		gl
XORG_CAT=	driver
USE_XORG=	xvmc xf86driproto xextproto x11 glproto

do-install:
	${MKDIR} ${PREFIX}/lib/xorg/modules/drivers
	${INSTALL_PROGRAM} ${WRKSRC}/src/.libs/rdc_drv.so \
	    ${PREFIX}/lib/xorg/modules/drivers/rdc_drv.so

.include <bsd.port.mk>
