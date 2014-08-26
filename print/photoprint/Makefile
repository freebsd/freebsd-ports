# $FreeBSD$

PORTNAME=	photoprint
DISTVERSION=	0.4.2-pre2
PORTREVISION=	3
CATEGORIES=	print graphics
MASTER_SITES=	http://www.blackfiveimaging.co.uk/photoprint/

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Utility to print multiple images per sheet

LICENSE=	GPLv2

LIB_DEPENDS=	libcups.so:${PORTSDIR}/print/cups-client \
		libgutenprint.so:${PORTSDIR}/print/gutenprint \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		liblcms.so:${PORTSDIR}/graphics/lcms \
		libnetpbm.so:${PORTSDIR}/graphics/netpbm \
		libpng.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff

GNU_CONFIGURE=	yes
USES=		desktop-file-utils gettext libtool pkgconfig
USE_GNOME=	gdkpixbuf2 gtk20
USE_XORG=	x11
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lX11

post-patch:
	@${REINPLACE_CMD} -e 's|glib/gstrfuncs.h|glib.h|g' \
		${WRKSRC}/gp_cppsupport/gprinter.cpp

.include <bsd.port.mk>
