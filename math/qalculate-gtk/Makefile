PORTNAME=	qalculate-gtk
PORTVERSION=	5.9.0
CATEGORIES=	math
MASTER_SITES=	https://github.com/Qalculate/${PORTNAME}/releases/download/v${PORTVERSION}/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Multi-purpose desktop calculator (GTK 3 frontend)
WWW=		https://qalculate.github.io/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqalculate.so:math/libqalculate \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	gnuplot:math/gnuplot

USES=		compiler:c++17-lang gettext gmake gnome \
		libtool localbase pkgconfig
# Project does not set a c++ dialect, but it's better to not leave this
# undefined and left up to the whims of the compiler.
USE_CXXSTD=	c++17
USE_GNOME=	cairo gdkpixbuf gtk30 libxml2

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=		NLS WEBKIT
OPTIONS_DEFAULT=	WEBKIT
OPTIONS_SUB=		yes

WEBKIT_DESC=		Use WebKitGTK for display of the user manual
WEBKIT_LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
			libwebkit2gtk-4.0.so:www/webkit2-gtk@40
WEBKIT_CONFIGURE_ON=	--with-webkitgtk=4.0

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s|po ||g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
