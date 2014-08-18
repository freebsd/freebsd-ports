# Created by: FreeBSD GNOME Team <gnome@freebsd.org>
# $FreeBSD$
#   $MCom: ports/trunk/multimedia/cheese/Makefile 19813 2014-08-15 19:44:33Z gusi $

PORTNAME=	cheese
PORTVERSION=	3.12.2
PORTREVISION=	1
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Photobooth-inspired app for taking pictures and videos from webcam

BUILD_DEPENDS=	v4l_compat>=0:${PORTSDIR}/multimedia/v4l_compat \
		gnome-video-effects>=0:${PORTSDIR}/graphics/gnome-video-effects \
		vala>=0.14.0:${PORTSDIR}/lang/vala \
		itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3 \
		libhal.so:${PORTSDIR}/sysutils/hal \
		libclutter-gtk-1.0.so:${PORTSDIR}/graphics/clutter-gtk3 \
		libclutter-gst-2.0.so:${PORTSDIR}/multimedia/clutter-gst
RUN_DEPENDS=	gnome-video-effects>=0:${PORTSDIR}/graphics/gnome-video-effects

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix intlhack evolutiondataserver3 librsvg2 \
		gnomedesktop3 libxml2:build introspection:build
USE_XORG=	xxf86vm x11
USE_GSTREAMER1=	bad good jpeg ogg theora v4l2 vpx
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -Wno-format-nonliteral
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

DOCS=		AUTHORS COPYING ChangeLog NEWS README
GLIB_SCHEMAS=	org.gnome.Cheese.gschema.xml

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
