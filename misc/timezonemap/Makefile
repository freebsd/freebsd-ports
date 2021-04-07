PORTNAME=	timezonemap
DISTVERSION=	0.4.5.1
CATEGORIES=	misc gnome

MAINTAINER=	gnome@freebsd.org
COMMENT=	Gtk3 timezone map widget, forked from gnome which forked from Ubiquity

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gnome-autogen.sh:devel/gnome-common
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libsoup-2.4.so:devel/libsoup

USES=		autoreconf:build gmake gnome libtool pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	dashea
USE_GNOME=	cairo gdkpixbuf2 gtk30 introspection:build librsvg2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

pre-configure:
	@cd ${WRKSRC} && ${SETENV} NOCONFIGURE=yes ${SH} autogen.sh

.include <bsd.port.mk>
