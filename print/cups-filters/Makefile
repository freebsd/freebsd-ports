# $FreeBSD$

PORTNAME=	cups-filters
PORTVERSION=	1.2.0
CATEGORIES=	print
MASTER_SITES=	http://www.openprinting.org/download/cups-filters/

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Backends, filters and other software (was part of the core CUPS)

BUILD_DEPENDS=	pdftops:${PORTSDIR}/graphics/poppler-utils
RUN_DEPENDS=	pdftops:${PORTSDIR}/graphics/poppler-utils
LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff \
		libpng.so:${PORTSDIR}/graphics/png \
		libijs.so:${PORTSDIR}/print/libijs \
		liblcms2.so:${PORTSDIR}/graphics/lcms2 \
		libqpdf.so:${PORTSDIR}/print/qpdf \
		libdbus-1.so:${PORTSDIR}/devel/dbus \
		libcups.so:${PORTSDIR}/print/cups-client \
		libcupsimage.so:${PORTSDIR}/print/cups-image \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libpoppler.so:${PORTSDIR}/graphics/poppler

USES=		compiler:c++11-lib cpe ghostscript jpeg libtool pathfix \
		pkgconfig shebangfix tar:xz
CPE_VENDOR=	linuxfoundation
SHEBANG_FILES=	filter/textonly
USE_GNOME=	glib20
USE_RC_SUBR=	cups_browsed
GNU_CONFIGURE=	yes
CUPS_SOCKET?=	/var/run/cups.sock
CONFIGURE_ARGS=	--with-cups-domainsocket=${CUPS_SOCKET}
CONFIGURE_ENV=	ZLIB_CFLAGS="-I/usr/include" ZLIB_LIBS="-lz" \
		LIBQPDF_CFLAGS="-I${LOCALBASE}/include" LIBQPDF_LIBS="-lqpdf"
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	AVAHI

AVAHI_CONFIGURE_ENABLE=	avahi
AVAHI_LIB_DEPENDS=	libavahi-client.so:${PORTSDIR}/net/avahi-app

post-patch:
	@${REINPLACE_CMD} 's:-std=c++0x:-std=c++11:' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/filter/pdftops.c

post-configure:
	@${REINPLACE_CMD} \
		-e 's|\(BANNERTOPDF_DATADIR = \).*\(/share/cups/data\)|\1${PREFIX}\2|' \
		-e 's|\(CUPS_DATADIR = \).*\(/share/cups\)|\1${PREFIX}\2|' \
		-e 's|\(CUPS_SERVERBIN = \).*\(/libexec/cups\)|\1${PREFIX}\2|' \
		-e 's|\(CUPS_SERVERROOT = \).*\(/etc/cups\)|\1${PREFIX}\2|' \
		${WRKSRC}/Makefile

post-install:
	@${RM} -rf ${STAGEDIR}${PREFIX}/libexec/cups/filter/foomatic-rip \
		${STAGEDIR}${PREFIX}/bin/foomatic-rip \
		${STAGEDIR}${PREFIX}/man/man1/foomatic-rip.1

.include <bsd.port.mk>
