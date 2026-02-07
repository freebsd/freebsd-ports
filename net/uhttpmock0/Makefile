PORTNAME=	uhttpmock
PORTVERSION=	0.5.3
CATEGORIES=	net gnome
MASTER_SITES=	http://tecnocode.co.uk/downloads/uhttpmock/
PKGNAMESUFFIX=	0
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	HTTP web service mocking library
WWW=		https://gitlab.freedesktop.org/pwithnall/uhttpmock

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup

USES=		gettext gmake gnome libtool pathfix pkgconfig tar:xz vala:build
USE_GNOME=	gnomeprefix glib20 introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-Werror

INSTALL_TARGET=	install-strip
PORTSCOUT=	limit:^0\.5

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
