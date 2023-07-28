PORTNAME=	photoprint
DISTVERSION=	0.4.2-pre2
PORTREVISION=	11
CATEGORIES=	print graphics
MASTER_SITES=	http://www.blackfiveimaging.co.uk/photoprint/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to print multiple images per sheet
WWW=		http://blackfiveimaging.co.uk/

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

post-patch:
	@${REINPLACE_CMD} -e 's|cups/cups.h|cups/ppd.h|g' \
		${WRKSRC}/stp_support/printerqueues_unix.c

.include <bsd.port.mk>
