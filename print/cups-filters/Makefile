# $FreeBSD$

PORTNAME=	cups-filters
PORTVERSION=	1.8.2
PORTREVISION=	3
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
		libcupsimage.so:${PORTSDIR}/print/cups \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libpoppler.so:${PORTSDIR}/graphics/poppler

CONFLICTS=	cups-pstoraster-[0-9]* foomatic-filters-[0-9]*

USES=		compiler:c++11-lib cpe ghostscript gmake jpeg libtool pathfix \
		pkgconfig shebangfix tar:xz
CPE_VENDOR=	linuxfoundation
SHEBANG_FILES=	filter/braille/drivers/generic/brftoembosser.in \
		filter/braille/drivers/index/imageubrltoindexv3.in \
		filter/braille/drivers/index/imageubrltoindexv4.in \
		filter/braille/drivers/index/textbrftoindexv3.in \
		filter/braille/filters/imagetobrf.in \
		filter/braille/filters/texttobrf.in filter/textonly
USE_GNOME=	glib20
USE_RC_SUBR=	cups_browsed
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-shell=/bin/sh ZLIB_CFLAGS=" " ZLIB_LIBS="-lz"
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	AVAHI DOCS
OPTIONS_DEFAULT=AVAHI

AVAHI_CONFIGURE_ENABLE=	avahi
AVAHI_LIB_DEPENDS=	libavahi-client.so:${PORTSDIR}/net/avahi-app
AVAHI_SUB_LIST=		AVAHI_DAEMON=avahi_daemon
AVAHI_SUB_LIST_OFF=	AVAHI_DAEMON=

post-patch:
	@${REINPLACE_CMD} 's:-std=c++0x:-std=c++11:' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} 's|/usr/share/liblouis|${LOCALBASE}/share/liblouis|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' \
		-e 's|README.gz|README|' \
		${WRKSRC}/utils/cups-browsed.8 \
		${WRKSRC}/utils/cups-browsed.conf.5

.include <bsd.port.mk>
