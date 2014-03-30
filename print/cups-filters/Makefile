# $FreeBSD$

PORTNAME=	cups-filters
PORTVERSION=	1.0.42
CATEGORIES=	print
MASTER_SITES=	http://www.openprinting.org/download/cups-filters/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Backends, filters and other software (was part of the core CUPS)

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libpng15.so:${PORTSDIR}/graphics/png \
		libijs.so:${PORTSDIR}/print/libijs \
		liblcms2.so:${PORTSDIR}/graphics/lcms2 \
		libqpdf.so:${PORTSDIR}/print/qpdf \
		libdbus-1.so:${PORTSDIR}/devel/dbus \
		libcups.so:${PORTSDIR}/print/cups-client \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libpoppler.so:${PORTSDIR}/graphics/poppler

USES=		compiler:c++11-lib pathfix pkgconfig tar:xz
USE_GNOME=	glib20
USE_GHOSTSCRIPT=	yes
GNU_CONFIGURE=	yes
CUPS_SOCKET=	/var/run/cups.sock
CONFIGURE_ARGS=	--with-domainsocket=${CUPS_SOCKET}
CONFIGURE_ENV=	ZLIB_CFLAGS="-I/usr/include" ZLIB_LIBS="-lz" \
		LIBQPDF_CFLAGS="-I/usr/local/include" LIBQPDF_LIBS="-lqpdf"

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	AVAHI
OPTIONS_DEFAULT=	AVAHI

AVAHI_CONFIGURE_ENABLE=	avahi
AVAHI_LIB_DEPENDS=	libavahi-client.so:${PORTSDIR}/net/avahi-app

post-patch:
	@${REINPLACE_CMD} 's:-std=c++0x:-std=c++11:' ${WRKSRC}/Makefile.in

post-install:
	@${RM} -rf ${STAGEDIR}${PREFIX}/libexec/cups/filter/foomatic-rip \
		${STAGEDIR}${PREFIX}/man/man1/foomatic-rip.1

.include <bsd.port.mk>
