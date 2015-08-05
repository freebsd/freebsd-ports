# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-online-miners
PORTVERSION=	3.14.3
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Crawls through your online content

LIB_DEPENDS=	libgdata.so:${PORTSDIR}/devel/libgdata \
		libtracker-control-1.0.so:${PORTSDIR}/sysutils/tracker \
		libgfbgraph-0.2.so:${PORTSDIR}/net/gfbgraph \
		libzapojit-0.0.so:${PORTSDIR}/net/libzapojit \
		libgrilo-0.2.so:${PORTSDIR}/net/grilo

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	intlhack introspection:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
