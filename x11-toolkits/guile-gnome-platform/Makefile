# $FreeBSD$

PORTNAME=	guile-gnome-platform
DISTVERSION=	2.16.5
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNU/guile-gnome/${PORTNAME}

MAINTAINER=	andrew@tao11.riddles.org.uk
COMMENT=	Guile bindings for Gnome libraries

LICENSE=	GPLv2+

BUILD_DEPENDS=	guile2>=2.2:lang/guile2
LIB_DEPENDS=	libguile-2.2.so:lang/guile2				\
		libgc-threaded.so:devel/boehm-gc-threaded		\
		libgwrap-guile-runtime.so:devel/g-wrap			\
		libffi.so:devel/libffi

# A note on flavors: LIBGNOMEUI, LIBGNOME, GCONF pull in very long
# dependency lists including things like spidermonkey and samba, which
# is rather overkill if you just want to do GUI tools. So make "lite"
# the default.
FLAVORS=	lite full
FLAVOR?=	${FLAVORS:[1]}
full_PKGNAMESUFFIX=-full
full_CONFLICTS_INSTALL=${PORTNAME}-lite
lite_PKGNAMESUFFIX=-lite
lite_CONFLICTS_INSTALL=${PORTNAME}-full

# We don't actually need gettext, but for some incomprehensible reason it
# is the package that installs some basic gnulib autoconf functionality.
USES=		autoreconf gettext-tools gmake gnome libtool pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

MAKE_JOBS_UNSAFE=yes

INSTALL_TARGET=	install-strip

DATADIR=	${PREFIX}/share/guile-gnome-2

INFO=		guile-gnome-glib guile-gnome-gobject

OPTIONS_DEFINE=	ATK CAIRO CANVAS GCONF GLADE GTK2 LIBGNOME LIBGNOMEUI PANGO
OPTIONS_DEFAULT=ATK CAIRO CANVAS GLADE GTK2 PANGO

.if ${FLAVOR} == full
OPTIONS_SLAVE=	ATK CAIRO CANVAS GCONF GLADE GTK2 LIBGNOME LIBGNOMEUI PANGO
.endif

OPTIONS_SUB=	yes

# other options have descriptions provided by ports/Mk/*
ATK_DESC=	GNOME accessibility toolkit (ATK)
CANVAS_DESC=	GNOMECanvas Graphics library
LIBGNOMEUI_DESC=libgnomeui support
LIBGNOME_DESC=	libgnome support

ATK_USE=		gnome=atk
ATK_CONFIGURE_WITH=	atk
ATK_INFO=		guile-gnome-atk

# Cairo support depends on a separate module.
CAIRO_LIB_DEPENDS=	libguile-cairo.so:graphics/guile-cairo
CAIRO_USE=		gnome=cairo
CAIRO_CONFIGURE_WITH=	cairo

CANVAS_IMPLIES=		GLADE GTK2 CAIRO
CANVAS_USE=		gnome=libgnomecanvas
CANVAS_CONFIGURE_WITH=	canvas
CANVAS_INFO=		guile-gnome-libgnomecanvas

GCONF_IMPLIES=		GTK2 CAIRO
GCONF_USE=		gnome=gconf2
GCONF_CONFIGURE_WITH=	gconf
GCONF_INFO=		guile-gnome-gconf

GLADE_IMPLIES=		GTK2 CAIRO
GLADE_USE=		gnome=libglade2
GLADE_CONFIGURE_WITH=	libglade
GLADE_INFO=		guile-gnome-libglade

GTK2_IMPLIES=		CAIRO
# These dependencies are brought in from gtk2's pkgconf, but
# not accounted for by Uses/gnome
GTK2_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig	\
			libfreetype.so:print/freetype2
GTK2_USE=		gnome=gtk20,gdkpixbuf2
GTK2_CONFIGURE_WITH=	gtk pixbuf
GTK2_INFO=		guile-gnome-gtk guile-gnome-gdk

LIBGNOMEUI_IMPLIES=	LIBGNOME GTK2 CAIRO
# libgnomeui's pkgconf brings in libSM and libICE from xorg, but for
# some reason Uses/gnome doesn't account for this, so we arrange for
# USES=xorg and USE_XORG=sm,ice
LIBGNOMEUI_USES=	xorg
LIBGNOMEUI_USE=		gnome=libgnomeui xorg=sm,ice
LIBGNOMEUI_CONFIGURE_WITH=libgnomeui
LIBGNOMEUI_INFO=	guile-gnome-libgnomeui

# This dependency is brought in from libgnome's pkgconf, but
# not accounted for by Uses/gnome
LIBGNOME_LIB_DEPENDS=	libpopt.so:devel/popt
LIBGNOME_USE=		gnome=libgnome
LIBGNOME_CONFIGURE_WITH=libgnome
LIBGNOME_INFO=		guile-gnome-libgnome

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

post-install:
	for f in ${INFO_UNUSED}; do \
		${RM} ${STAGEDIR}${PREFIX}/${INFO_PATH}/$${f}.info*; \
	done;

.include <bsd.port.mk>
