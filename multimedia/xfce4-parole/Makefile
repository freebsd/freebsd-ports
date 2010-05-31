# New ports collection makefile for:	Xfce4-parole
# Date created:		26 December 2009
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfce4-parole
PORTVERSION=	0.2.0.2
PORTREVISION=	3
CATEGORIES=	multimedia xfce
MASTER_SITES=	http://archive.xfce.org/src/apps/parole/0.2/
DISTNAME=	parole-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Lightweight media player for Xfce4 based on the gstreamer engine

LIB_DEPENDS=	tag:${PORTSDIR}/audio/taglib

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GSTREAMER=	ffmpeg good theora xvid mp3 faad ogg dvd x264
USE_GMAKE=	yes
CONFIGURE_ARGS=	--disable-power-manager-plugin
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
USE_GNOME=	gnomehack intltool intlhack pkgconfig
USE_XFCE=	configenv libexo libgui libutil panel
USE_XORG=	x11 sm

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
