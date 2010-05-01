# New ports collection makefile for:	xf86-video-sis-intel
# Date Created:				30 May 2008
# Whom:					Alexey Illarionov <littlesavage@orionet.ru>
# Based on:             		x11-drivers/xf86-video-sis by flz@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xf86-video-sis-intel
PORTVERSION=	300407
PORTREVISION=	4
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

.include <bsd.port.mk>
