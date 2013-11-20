# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	grilo-plugins
PORTVERSION=	0.2.3
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plugins for net/grilo

LIB_DEPENDS=	grilo-0.2:${PORTSDIR}/net/grilo

USES=		gettext gmake pathfix pkgconfig
USE_XZ=		yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_GNOME=	glib20 gnomehier intlhack libxml2 ltverhack
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
