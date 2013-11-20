# $FreeBSD$
#   $MCom: ports/trunk/multimedia/cheese3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	cheese
PORTVERSION=	3.6.0
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Photobooth-inspired app for taking pictures and videos from webcam

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev.h:${PORTSDIR}/multimedia/v4l_compat \
		${LOCALBASE}/libdata/pkgconfig/gnome-video-effects.pc:${PORTSDIR}/graphics/gnome-video-effects \
		vala>=0.14.0:${PORTSDIR}/lang/vala \
		itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3 \
		libhal.so:${PORTSDIR}/sysutils/hal \
		libgee.so.2:${PORTSDIR}/devel/libgee06 \
		libclutter-gtk-1.0.so:${PORTSDIR}/graphics/clutter-gtk3 \
		libclutter-gst-2.0.so:${PORTSDIR}/multimedia/clutter-gst
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-video-effects.pc:${PORTSDIR}/graphics/gnome-video-effects

USE_XORG=	xxf86vm x11
USE_XZ=		yes
USE_GNOME=	gnomeprefix intlhack evolutiondataserver3 librsvg2 \
		gnomedesktop3 libxml2:build introspection:build
USES=		gettext gmake pathfix pkgconfig
USE_GSTREAMER1=	bad good jpeg ogg theora v4l2 vpx
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -Wno-format-nonliteral
LDFLAGS+=	-L${LOCALBASE}/lib

DOCS=		AUTHORS COPYING ChangeLog NEWS README
GLIB_SCHEMAS=	org.gnome.Cheese.gschema.xml

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcheese*.so.*

.include <bsd.port.mk>
