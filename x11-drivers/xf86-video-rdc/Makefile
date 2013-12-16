# Created by: stas
# $FreeBSD$

PORTNAME=	xf86-video-rdc
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	x11-drivers
MASTER_SITES=	http://www.SpringDaemons.com/stas/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X.Org RDC display driver

#USE_GL=		gl
XORG_CAT=	driver
USE_XORG=	xvmc xf86driproto xextproto x11 glproto

.include <bsd.port.options.mk>

.if defined(WITH_NEW_XORG)
IGNORE=         does not build with X server 1.12
.endif

NO_STAGE=	yes
do-install:
	${MKDIR} ${PREFIX}/lib/xorg/modules/drivers
	${INSTALL_PROGRAM} ${WRKSRC}/src/.libs/rdc_drv.so \
	    ${PREFIX}/lib/xorg/modules/drivers/rdc_drv.so

.include <bsd.port.mk>
