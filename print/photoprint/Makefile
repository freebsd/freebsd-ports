# $FreeBSD$

PORTNAME=	photoprint
DISTVERSION=	0.4.2-pre2
PORTREVISION=	9
CATEGORIES=	print graphics
MASTER_SITES=	http://www.blackfiveimaging.co.uk/photoprint/

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Utility to print multiple images per sheet

LICENSE=	GPLv2

LIB_DEPENDS=	libcups.so:print/cups \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgutenprint.so:print/gutenprint \
		liblcms.so:graphics/lcms \
		libnetpbm.so:graphics/netpbm \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

GNU_CONFIGURE=	yes
USES=		compiler:c++11-lang desktop-file-utils gettext gnome jpeg \
		libtool localbase pkgconfig xorg
USE_GNOME=	cairo gdkpixbuf2 gtk20
USE_XORG=	x11
USE_CXXSTD=	gnu++98
LIBS+=		-lX11
INSTALLS_ICONS=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|cups/cups.h|cups/ppd.h|g' \
		${WRKSRC}/stp_support/printerqueues_unix.c

.include <bsd.port.mk>
