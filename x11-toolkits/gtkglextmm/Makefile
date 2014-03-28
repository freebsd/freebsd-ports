# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	gtkglextmm
PORTVERSION=	1.2.0
PORTREVISION=	7
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/gtkglext/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ wrapper for GtkGLExt

LIB_DEPENDS=	gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext \
		gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24

USES=		pathfix pkgconfig gettext gmake tar:bzip2
USE_GNOME=	gnomeprefix gtk20
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-DGDK_DISABLE_DEPRECATED||g' \
		-e 's|-DGDK_PIXBUF_DISABLE_DEPRECATED||g' \
		-e 's|-DGTK_DISABLE_DEPRECATED||g' \
		-e 's|-DG_DISABLE_DEPRECATED||g' \
		${WRKSRC}/gdkglext/gdkmm/gl/Makefile.in \
		${WRKSRC}/gtkglext/gtkmm/gl/Makefile.in

.include <bsd.port.mk>
