# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-online-miners
PORTVERSION=	3.26.0
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Crawls through your online content

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgdata.so:devel/libgdata \
		libjson-glib-1.0.so:devel/json-glib \
		librest-0.7.so:devel/librest \
		libsoup-2.4.so:devel/libsoup \
		libtracker-control-2.0.so:sysutils/tracker \
		libgoa-1.0.so:net/gnome-online-accounts \
		libgfbgraph-0.2.so:net/gfbgraph \
		libzapojit-0.0.so:net/libzapojit \
		libgrilo-0.3.so:net/grilo

USES=		gettext gmake gnome libtool localbase pathfix pkgconfig tar:xz
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
