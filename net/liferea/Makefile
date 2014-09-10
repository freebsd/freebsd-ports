# Created by: Hye-Shik Chang <perky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	liferea
PORTVERSION=	1.10.8
PORTREVISION=	3
CATEGORIES=	net gnome
MASTER_SITES=	https://github.com/lwindolf/liferea/releases/download/v${PORTVERSION}/ \
		http://rainbow-runner.nl/~kwm/distfiles/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Simple RSS/RDF feed reader

LICENSE=	GPLv2

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	libwebkitgtk-3.0.so:${PORTSDIR}/www/webkit-gtk3 \
		libpeas-1.0.so:${PORTSDIR}/devel/libpeas \
		libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib
RUN_DEPENDS=	gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas

USES=		desktop-file-utils gmake libtool pathfix pkgconfig \
		tar:bzip2
USE_GNOME=	gnomeprefix gtk30 introspection:build libxslt:build libxml2
USE_SQLITE=	3
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--disable-libnotify --disable-libindicate

GLIB_SCHEMAS=	net.sf.liferea.gschema.xml
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
