# New ports collection makefile for:	emotion
# Date created:		2006-07-16
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	emotion
PORTVERSION=	20060719
CATEGORIES=	multimedia
MASTER_SITES=	http://mbsd.msk.ru/dist/

MAINTAINER=	ssedov@mbsd.msk.ru
COMMENT=	Video playback wrapper library for e17

LIB_DEPENDS=	ecore.1:${PORTSDIR}/x11/ecore \
		edje.5:${PORTSDIR}/graphics/edje \
		eet.9:${PORTSDIR}/devel/eet \
		embryo.9:${PORTSDIR}/lang/embryo \
		evas.1:${PORTSDIR}/graphics/evas

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

OPTIONS=	XINE "Build Xine module" on \
		GST "Build GStreamer module" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_XINE) && defined(WITHOUT_GST)
IGNORE=	is useless without playback library. Please run 'make config' and choose one of XINE and GST
.endif

.if defined(WITH_XINE)
LIB_DEPENDS+=	xine.15:${PORTSDIR}/multimedia/libxine
PLIST_SUB+=	XINE=""
.else
PLIST_SUB+=	XINE="@comment "
.endif
.if defined(WITH_GST)
USE_GSTREAMER=	ffmpeg good
PLIST_SUB+=	GST=""
.else
PLIST_SUB+=	GST="@comment "
.endif

.include <bsd.port.post.mk>
