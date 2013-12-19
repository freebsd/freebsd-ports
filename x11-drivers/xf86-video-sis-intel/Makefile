# Created by: Alexey Illarionov <littlesavage@orionet.ru>
# $FreeBSD$

PORTNAME=	xf86-video-sis-intel
PORTVERSION=	300407
PORTREVISION=	6
CATEGORIES=	x11-drivers
MASTER_SITES=	http://downloadmirror.intel.com/15443/eng/
DISTNAME=	sis_drv_src_300407

MAINTAINER=	littlesavage@orionet.ru
COMMENT=	X.Org sis display driver provided by Intel

IGNORE=		requires pciVideoPtr typedef

CONFLICTS=	xf86-video-sis-[0-9]*
WRKSRC=		${WRKDIR}/2d-driver

USE_GL=		gl

XORG_CAT=	driver
USE_XORG=	xf86dgaproto xf86driproto xineramaproto videoproto xf86miscproto xextproto glproto
MAN4=		sis.4x

NO_STAGE=	yes
.include <bsd.port.mk>
