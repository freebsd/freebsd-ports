PORTNAME=	guile-gnome-platform
DISTVERSION=	2.16.5
PORTREVISION=	10
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNU/guile-gnome/${PORTNAME}

MAINTAINER=	andrew@tao11.riddles.org.uk
COMMENT=	Guile bindings for Gnome libraries
WWW=		https://www.gnu.org/software/guile-gnome/

LICENSE=	GPLv2+

LIB_DEPENDS=	libgwrap-guile-runtime.so:devel/g-wrap \
		libffi.so:devel/libffi

FLAVORS=	lite full
FLAVOR?=	${FLAVORS:[1]}
full_PKGNAMESUFFIX=-full
full_CONFLICTS_INSTALL=${PORTNAME}-lite
lite_PKGNAMESUFFIX=-lite
lite_CONFLICTS_INSTALL=${PORTNAME}-full

# We don't actually need gettext, but for some incomprehensible reason it
# is the package that installs some basic gnulib autoconf functionality.
USES=		autoreconf gettext-tools gmake gnome guile:2.2,alias \
		libtool pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

MAKE_JOBS_UNSAFE=yes

INSTALL_TARGET=	install-strip

DATADIR=	${PREFIX}/share/guile-gnome-2

INFO=		guile-gnome-gconf guile-gnome-glib guile-gnome-gobject \
		guile-gnome-libgnome guile-gnome-libgnomeui

OPTIONS_DEFINE=	ATK CAIRO CANVAS GLADE GTK2 PANGO
OPTIONS_DEFAULT=ATK CAIRO CANVAS GLADE GTK2 PANGO

.if ${FLAVOR} == full
OPTIONS_SLAVE=	ATK CAIRO CANVAS GLADE GTK2 PANGO
.endif

OPTIONS_SUB=	yes

# other options have descriptions provided by ports/Mk/*
ATK_DESC=	GNOME accessibility toolkit (ATK)
CANVAS_DESC=	GNOMECanvas Graphics library

ATK_USE=		gnome=atk
ATK_CONFIGURE_WITH=	atk
ATK_INFO=		guile-gnome-atk

# Cairo support depends on a separate module.
CAIRO_BUILD_DEPENDS=	${LOCALBASE}/lib/guile/${GUILE_VER}/extensions/libguile-cairo.so:graphics/guile-cairo@${GUILE_FLAVOR}
CAIRO_RUN_DEPENDS=	${LOCALBASE}/lib/guile/${GUILE_VER}/extensions/libguile-cairo.so:graphics/guile-cairo@${GUILE_FLAVOR}
CAIRO_USE=		gnome=cairo
CAIRO_CONFIGURE_WITH=	cairo

CANVAS_IMPLIES=		GLADE GTK2 CAIRO
CANVAS_USE=		gnome=libgnomecanvas
CANVAS_CONFIGURE_WITH=	canvas
CANVAS_INFO=		guile-gnome-libgnomecanvas

GLADE_IMPLIES=		GTK2 CAIRO
GLADE_USE=		gnome=libglade2
GLADE_CONFIGURE_WITH=	libglade
GLADE_INFO=		guile-gnome-libglade

GTK2_IMPLIES=		CAIRO
# These dependencies are brought in from gtk2's pkgconf, but
# not accounted for by Uses/gnome
GTK2_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig	\
			libfreetype.so:print/freetype2 \
			libharfbuzz.so:print/harfbuzz
GTK2_USE=		gnome=gtk20,gdkpixbuf
GTK2_CONFIGURE_WITH=	gtk pixbuf
GTK2_INFO=		guile-gnome-gtk guile-gnome-gdk

PANGO_LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz
PANGO_USE=		gnome=pango
PANGO_CONFIGURE_WITH=	pango
PANGO_INFO=		guile-gnome-pango

# pangocairo doesn't have its own option, but is enabled if both PANGO
# and CAIRO are set.

PANGOCAIRO_INFO=guile-gnome-pangocairo

HAS_PANGOCAIRO=	${"${PORT_OPTIONS:MPANGO}${PORT_OPTIONS:MCAIRO}" == "PANGOCAIRO":?1:}
INFO+=		${"${HAS_PANGOCAIRO}":?${PANGOCAIRO_INFO}:}

# Compute the list of info files that are _not_ installed.
INFO_UNUSED=	${DESELECTED_OPTIONS:@s@${${s}_INFO}@}		\
		${OPTIONS_EXCLUDE:@s@${${s}_INFO}@}		\
		${"${HAS_PANGOCAIRO}":?:${PANGOCAIRO_INFO}}

post-patch:
	@${REINPLACE_CMD} -e '/grep/s,\^ {|,^ \\{|,' ${WRKSRC}/gconf/gnome/gw/Makefile.in \
	    ${WRKSRC}/gconf/gnome/overrides/Makefile.in \
	    ${WRKSRC}/gconf/gnome/Makefile.in \
	    ${WRKSRC}/libgnome/gnome/gw/Makefile.in \
	    ${WRKSRC}/libgnome/gnome/Makefile.in \
	    ${WRKSRC}/libgnome/gnome/overrides/Makefile.in \
	    ${WRKSRC}/defs/gnome/defs/Makefile.in \
	    ${WRKSRC}/defs/Makefile.in \
	    ${WRKSRC}/gtk/Makefile.in \
	    ${WRKSRC}/gtk/gnome/gw/Makefile.in \
	    ${WRKSRC}/gtk/gnome/gtk/Makefile.in \
	    ${WRKSRC}/gtk/gnome/overrides/Makefile.in \
	    ${WRKSRC}/gtk/gnome/contrib/Makefile.in \
	    ${WRKSRC}/gtk/gnome/Makefile.in \
	    ${WRKSRC}/libgnomeui/Makefile.in \
	    ${WRKSRC}/libgnomeui/gnome/overrides/Makefile.in \
	    ${WRKSRC}/libgnomeui/gnome/gw/Makefile.in \
	    ${WRKSRC}/libgnomeui/gnome/Makefile.in \
	    ${WRKSRC}/libgnomecanvas/gnome/gw/Makefile.in \
	    ${WRKSRC}/libgnomecanvas/gnome/Makefile.in \
	    ${WRKSRC}/libgnomecanvas/gnome/overrides/Makefile.in \
	    ${WRKSRC}/libglade/gnome/overrides/Makefile.in \
	    ${WRKSRC}/libglade/gnome/gw/Makefile.in \
	    ${WRKSRC}/libglade/gnome/Makefile.in \
	    ${WRKSRC}/pango/gnome/Makefile.in \
	    ${WRKSRC}/pango/gnome/overrides/Makefile.in \
	    ${WRKSRC}/pango/gnome/gw/Makefile.in \
	    ${WRKSRC}/glib/gnome/Makefile.in \
	    ${WRKSRC}/glib/gnome/gobject/Makefile.in \
	    ${WRKSRC}/glib/gnome/overrides/Makefile.in \
	    ${WRKSRC}/glib/gnome/gw/Makefile.in \
	    ${WRKSRC}/glib/gnome/gw/support/Makefile.in \
	    ${WRKSRC}/glib/Makefile.in \
	    ${WRKSRC}/glib/bin/Makefile.in \
	    ${WRKSRC}/glib/test-suite/Makefile.in \
	    ${WRKSRC}/common.mk \
	    ${WRKSRC}/cairo/gnome/gw/Makefile.in \
	    ${WRKSRC}/cairo/gnome/Makefile.in \
	    ${WRKSRC}/atk/gnome/overrides/Makefile.in \
	    ${WRKSRC}/atk/gnome/gw/Makefile.in \
	    ${WRKSRC}/atk/gnome/Makefile.in

# pacify check-plist by removing any .info files for deselected
# components. This doesn't affect the packaging but makes QA testing
# of the options much easier.

# DO NOT try and add rules here to strip .go files, no matter how loudly
# testport / stage-qa shouts at you about it, because .go files (which are
# compiled bytecode) are not intended to be stripped and doing so causes
# breakage at run time.

post-install:
	for f in ${INFO_UNUSED}; do \
		${RM} ${STAGEDIR}${PREFIX}/${INFO_PATH}/$${f}.info*; \
	done;

.include <bsd.port.mk>
