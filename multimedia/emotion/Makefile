# New ports collection makefile for:	emotion
# Date created:		2006-07-16
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	emotion
PORTVERSION=	0.2.0.56361
PORTEPOCH=	1
CATEGORIES=	multimedia enlightenment
MASTER_SITES=	http://files.roorback.net/e17/2011-01-29/extra/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video playback wrapper library for Enlightenment

LICENSE=	BSD
DIST_SUBDIR=	e17
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_EFL=	ecore edje eet embryo evas libtool_hack modarch_hack
USE_EFL_EVAS_LOADERS=	png jpeg
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes

OPTIONS=	XINE "Build Xine module" on \
		GST "Build GStreamer module" on

# emotion's vlc plugin needs updating due to libvlc API changes
# details: http://trac.enlightenment.org/e/ticket/601
CONFIGURE_ARGS=	--disable-vlc

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
