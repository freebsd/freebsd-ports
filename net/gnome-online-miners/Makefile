# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/net/gnome-online-miners/Makefile 19571 2014-04-25 18:12:46Z kwm $

PORTNAME=	gnome-online-miners
PORTVERSION=	3.12.0
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Crawls through your online content

LIB_DEPENDS=	libgdata.so:${PORTSDIR}/devel/libgdata \
		libtracker-control-1.0.so:${PORTSDIR}/sysutils/tracker \
		libgfbgraph-0.2.so:${PORTSDIR}/net/gfbgraph \
		libzapojit-0.0.so:${PORTSDIR}/net/libzapojit \
		libgrilo-0.2.so:${PORTSDIR}/net/grilo

USE_GNOME=	intlhack introspection:build
USES=		gettext gmake pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gnome-online-miners/libgom-1.0.so 

.include <bsd.port.mk>
