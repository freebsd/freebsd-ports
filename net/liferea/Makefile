# Created by: Hye-Shik Chang <perky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	liferea
PORTVERSION=	1.8.15
PORTREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	SF/${PORTNAME}/Liferea%20Stable/${PORTVERSION}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Simple RSS/RDF feed reader

LICENSE=	GPLv2

LIB_DEPENDS=	libwebkitgtk-1.0.so:${PORTSDIR}/www/webkit-gtk2 \
		libunique-1.0.so:${PORTSDIR}/x11-toolkits/unique \
		libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib

USES=		desktop-file-utils libtool gmake pathfix pkgconfig \
		tar:bzip2
USE_GNOME=	gnomeprefix gconf2
USE_SQLITE=	3
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--disable-libnotify --disable-libindicate

GCONF_SCHEMAS=	liferea.schemas
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
