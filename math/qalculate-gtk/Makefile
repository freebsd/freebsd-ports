PORTNAME=	qalculate-gtk
PORTVERSION=	5.7.0
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

USES=		compiler:c++11-lang gettext gmake gnome \
		libtool:build localbase pkgconfig
USE_GNOME=	cairo gdkpixbuf gtk30 intltool libxml2

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
