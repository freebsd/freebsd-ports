# Created by: dgilbert@velocet.ca
# $FreeBSD$
#    $MCom: ports/print/gutenprint-base/Makefile,v 1.8 2007/03/30 16:45:02 ahze Exp $

PORTNAME=	gutenprint
PORTVERSION=	5.2.14
PORTREVISION?=	0
CATEGORIES=	print
MASTER_SITES=	SF/gimp-print/gutenprint-5.2/${PORTVERSION}

MAINTAINER=	cmt@burggraben.net
COMMENT=	Gutenprint Printer Drivers

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	gimp-print-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --enable-simplified-cups-ppds DLOPEN_LIBS=" "
INSTALL_TARGET=	install-strip
USES=		compiler:c11 gettext gmake libtool pathfix perl5 pkgconfig \
		tar:bzip2

.if !defined(GUT_SLAVE)
LIB_DEPENDS+=	libcupsimage.so:print/cups
RUN_DEPENDS+=	${LOCALBASE}/libexec/cups/filter/gstoraster:print/cups-filters
CONFIGURE_ARGS+=--disable-libgutenprintui2 --without-gimp2
USES+=		iconv
USE_LDCONFIG=	yes
.else
LIB_DEPENDS+=	libgutenprint.so:print/gutenprint
MAKE_ARGS+=	GUTENPRINT_LIBS='`$$(PKG_CONFIG) --libs gutenprint`'
.if ${GUT_SLAVE} == "gimp"
USE_GNOME+=	cairo gdkpixbuf2
LIB_DEPENDS+=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgimp-2.0.so:graphics/gimp-app
CONFIGURE_ARGS+=--enable-libgutenprintui2 --with-gimp2
BUILD_WRKSRC=	${WRKSRC}/src/gimp2
INSTALL_WRKSRC=	${WRKSRC}/src/gimp2
USE_GNOME+=	gtk20
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
.endif

.include <bsd.port.mk>
