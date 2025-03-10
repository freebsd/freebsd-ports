PORTNAME=	timezonemap
DISTVERSION=	0.4.5.3
CATEGORIES=	misc gnome

MAINTAINER=	gnome@freebsd.org
COMMENT=	Gtk3 timezone map widget, forked from gnome which forked from Ubiquity
WWW=		https://github.com/dashea/timezonemap

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libsoup-2.4.so:devel/libsoup

USES=		autoreconf gmake gnome libtool pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	dashea
USE_GNOME=	gtk30 introspection:build librsvg2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

post-patch:
.for d in TZ_DATA_FILE ADMIN1_FILE COUNTRY_FILE
	@${REINPLACE_CMD} '/$d/s|/usr|${PREFIX}|' ${WRKSRC}/src/tz.h
.endfor

.include <bsd.port.mk>
