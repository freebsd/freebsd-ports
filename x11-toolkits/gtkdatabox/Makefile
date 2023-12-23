PORTNAME=	gtkdatabox
DISTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-1
MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	GTK 3 widget to display large amounts of numerical data
WWW=		https://sourceforge.net/projects/gtkdatabox/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz

USES=		gnome libtool pathfix pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk30
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir="${PREFIX}/include/${PORTNAME}" \
		--with-html-dir="${PREFIX}/share/doc"
INSTALL_TARGET=	install-strip

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES GLADE
OPTIONS_SUB=	yes

GLADE_LIB_DEPENDS=	libgladeui-2.so:devel/glade
GLADE_CONFIGURE_ENABLE=	glade

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SUBDIR/s|examples||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|DOC_MODULE_VERSION = 1|#DOC_MODULE_VERSION = 1|' ${WRKSRC}/doc/Makefile.in
.for dir in examples gtk
	@${REINPLACE_CMD} -e \
		'/-O2/d ; \
		 /DISABLE_DEPRECATED/d' ${WRKSRC}/${dir}/Makefile.in
.endfor

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.c ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
