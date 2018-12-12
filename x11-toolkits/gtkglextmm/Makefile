# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	gtkglextmm
PORTVERSION=	1.2.0
PORTREVISION=	14
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/gtkglext/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ wrapper for GtkGLExt

LIB_DEPENDS=	libgtkglext-x11-1.0.so:x11-toolkits/gtkglext \
		libgtkmm-2.4.so:x11-toolkits/gtkmm24

USES=		compiler:c++11-lang pathfix pkgconfig gettext gmake tar:bzip2 \
		libtool
USE_CXXSTD=	c++11
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix gtk20
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|-DGDK_DISABLE_DEPRECATED||g' \
		-e 's|-DGDK_PIXBUF_DISABLE_DEPRECATED||g' \
		-e 's|-DGTK_DISABLE_DEPRECATED||g' \
		-e 's|-DG_DISABLE_DEPRECATED||g' \
		${WRKSRC}/gdkglext/gdkmm/gl/Makefile.in \
		${WRKSRC}/gtkglext/gtkmm/gl/Makefile.in

.include <bsd.port.mk>
