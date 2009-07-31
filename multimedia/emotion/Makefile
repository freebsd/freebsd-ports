# New ports collection makefile for:	emotion
# Date created:		2006-07-16
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	emotion
PORTVERSION=	0.1.0.042
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/ \
		http://download.enlightenment.org/snapshots/2008-01-25/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Video playback wrapper library for Enlightenment

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_EFL=	ecore edje eet embryo evas
USE_EFL_EVAS_LOADERS=	png jpeg
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

OPTIONS=	XINE "Build Xine module" on \
		GST "Build GStreamer module" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_XINE) && defined(WITHOUT_GST)
IGNORE=	is useless without playback library. Please run 'make config' and choose one of XINE and GST
.endif

.if !defined(WITHOUT_XINE)
LIB_DEPENDS+=	xine.1:${PORTSDIR}/multimedia/libxine
CONFIGURE_ARGS+=--enable-xine
PLIST_SUB+=	XINE=""
.else
CONFIGURE_ARGS+=--disable-xine
PLIST_SUB+=	XINE="@comment "
.endif

.if !defined(WITHOUT_GST)
USE_GSTREAMER=	ffmpeg good
CONFIGURE_ARGS+=--enable-gstreamer
PLIST_SUB+=	GST=""
.else
CONFIGURE_ARGS+=--disable-gstreamer
PLIST_SUB+=	GST="@comment "
.endif

.include <bsd.port.post.mk>
