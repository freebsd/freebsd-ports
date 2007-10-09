# New ports collection makefile for:	xf86-video-openchrome
# Date Created:				17 Sep 2007
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xf86-video-openchrome
PORTVERSION=	0.2.6
CATEGORIES=	x11-drivers
MASTER_SITES=	http://archive.ubuntu.com/ubuntu/pool/main/x/xserver-xorg-video-openchrome/
DISTFILES=	xserver-xorg-video-openchrome_${PORTVERSION}+svn357.orig.tar.gz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org openchrome display driver

CONFLICTS=	xf86-video-via-[0-9]*

USE_TGZ=	yes
WRKSRC=		${WRKDIR}/xserver-xorg-video-openchrome
NOMANCOMPRESS=	yes

USE_AUTOTOOLS=	autoconf:261:env automake:19:env libtool:15:env

XORG_CAT=	driver
USE_GL=		gl
USE_XORG=	xvmc xf86driproto glproto
MAN4=		via.4x

pre-configure:
	@(cd ${WRKSRC} && ${SH} ./autogen.sh)

.include <bsd.port.mk>
