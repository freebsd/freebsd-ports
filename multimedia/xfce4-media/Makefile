# New ports collection makefile for:	Xfce4-media
# Date created:		23 October 2004
# Whom:			Matt Lancereau <matt@bsdfly.org>
#
# $FreeBSD$
#

PORTNAME=	Xfce4-media
PORTVERSION=	0.6.0
PORTREVISION=	2
CATEGORIES=	multimedia xfce
MASTER_SITES=	http://spuriousinterrupt.org/projects/xfmedia/files/
DISTNAME=	xfmedia-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	matt@bsdfly.org
COMMENT=	Lightweight media player for Xfce4 based on the xine engine

LIB_DEPENDS=	xfcegui4.3:${PORTSDIR}/x11-toolkits/libxfce4gui \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification \
		xine.13:${PORTSDIR}/multimedia/libxine

USE_BZIP2=	yes
USE_GETOPT_LONG=yes
USE_GNOME=	libxml2
USE_LIBTOOL_VER=15
USE_X_PREFIX=	yes
USE_REINPLACE=	yes

INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g" \
		${WRKSRC}/xfmedia/Makefile.in

.include <bsd.port.mk>
