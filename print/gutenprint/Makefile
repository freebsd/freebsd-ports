PORTNAME=	gutenprint
DISTVERSION=	5.3.5
PORTREVISION?=	0
CATEGORIES=	print
MASTER_SITES=	SF/gimp-print/gutenprint-5.3/${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Gutenprint Printer Drivers
WWW=		https://gimp-print.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 cpe gettext gmake libtool pathfix perl5 pkgconfig \
		tar:xz
CPE_VENDOR=	${PORTNAME}_project
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --enable-cups-ppds \
		--enable-cups-1_2-enhancements \
		--enable-simplified-cups-ppds \
		--disable-globalized-cups-ppds \
		--enable-cups-level3-ppds \
		--disable-translated-cups-ppds
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		DOCS NLS
OPTIONS_SUB=		yes
DOCS_CONFIGURE_WITH=	doc
NLS_CONFIGURE_ENABLE=	nls

.if !defined(GUT_SLAVE)
LIB_DEPENDS+=	libcupsimage.so:print/cups
RUN_DEPENDS+=	${LOCALBASE}/libexec/cups/filter/gstoraster:print/cups-filters
USES+=		iconv
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=--disable-libgutenprintui2 --without-gimp2 \
		--with-cups=${PREFIX} \
		--with-cups-config=${PREFIX}/bin/cups-config
.else
LIB_DEPENDS+=	libgutenprint.so:print/gutenprint
MAKE_ARGS+=	GUTENPRINT_LIBS='`$$(PKG_CONFIG) --libs gutenprint`'
.if ${GUT_SLAVE} == "gimp"
LIB_DEPENDS+=	libbabl-0.1.so:x11/babl \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgegl-0.4.so:graphics/gegl \
		libgimp-2.0.so:graphics/gimp-app \
		libjson-glib-1.0.so:devel/json-glib
USES+=		gnome
USE_GNOME+=	cairo gdkpixbuf gtk20
CONFIGURE_ARGS+=--enable-libgutenprintui2 --with-gimp2
BUILD_WRKSRC=	${WRKSRC}/src/gimp2
INSTALL_WRKSRC=	${WRKSRC}/src/gimp2
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/lpstat|${LOCALBASE}/bin/lpstat|' \
		${WRKSRC}/src/gutenprintui2/plist.c
	@${REINPLACE_CMD} -e '/DEPENDENCIES/s/$$(GUTENPRINT_LIBS)//' \
		${WRKSRC}/src/gimp2/Makefile.in

post-install:
.if defined(GUT_SLAVE) && ${GUT_SLAVE} == "gimp"
	@(cd ${WRKSRC}/src/gutenprintui2 && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.else
	@${RM} -r ${STAGEDIR}/${DATADIR}/doc/reference-html
.endif

.include <bsd.port.mk>
