# New ports collection makefile for:	Xfce4-media
# Date created:		23 October 2004
# Whom:			Matt Lancereau <ports@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfce4-media
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	multimedia xfce
MASTER_SITES=	http://spuriousinterrupt.org/files/xfmedia/
DISTNAME=	xfmedia-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	r.c.ladan@gmail.com
COMMENT=	Lightweight media player for Xfce4 based on the xine engine

LIB_DEPENDS=	xfcegui4.3:${PORTSDIR}/x11-toolkits/libxfce4gui \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification \
		xine.16:${PORTSDIR}/multimedia/libxine \
		exo-0.3.0:${PORTSDIR}/x11/libexo

OPTIONS=	TAGLIB	"Enable metadata editing"	off \
		DBUS	"Enable remote control support" off

USE_BZIP2=	yes
USE_GETOPT_LONG=yes
USE_GETTEXT=	yes
#NLS is hardcoded to "yes" in source, so no WITHOUT_NLS
USE_GMAKE=	yes
USE_GNOME=	libxml2 intlhack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_TAGLIB)
LIB_DEPENDS+=	tag.5:${PORTSDIR}/audio/taglib
CONFIGURE_ARGS=	--with-taglib
.else
CONFIGURE_ARGS=	--without-taglib
.endif

.if defined(WITH_DBUS)
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=	--enable-dbus
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g" \
		${WRKSRC}/xfmedia/Makefile.in

.include <bsd.port.post.mk>
