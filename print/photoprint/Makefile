# $FreeBSD$

PORTNAME=	photoprint
DISTVERSION=	0.4.2-pre2
PORTREVISION=	2
CATEGORIES=	print graphics
MASTER_SITES=	http://www.blackfiveimaging.co.uk/photoprint/

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Utility to print multiple images per sheet

LICENSE=	GPLv2

LIB_DEPENDS=	libcups.so:${PORTSDIR}/print/cups-client \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libgdk_pixbuf-2.0.so:${PORTSDIR}/graphics/gdk-pixbuf2 \
		libgutenprint.so:${PORTSDIR}/print/gutenprint \
		liblcms.so:${PORTSDIR}/graphics/lcms \
		libnetpbm.so:${PORTSDIR}/graphics/netpbm \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libpng15.so:${PORTSDIR}/graphics/png \
		libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs \
		libtiff.so:${PORTSDIR}/graphics/tiff

GNU_CONFIGURE=	yes
USES=		desktop-file-utils gettext pkgconfig
USE_GNOME=	pango
USE_XORG=	pixman x11 xau xcb xcomposite xcursor xdamage xdmcp xext \
		xfixes xi xinerama xrandr xrender
INSTALLS_ICONS=	yes

LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|glib/gstrfuncs.h|glib.h|g' \
		${WRKSRC}/gp_cppsupport/gprinter.cpp

.include <bsd.port.mk>
