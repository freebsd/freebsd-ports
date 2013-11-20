# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/security/libgnome-keyring/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	libgnome-keyring
PORTVERSION=	3.6.0
CATEGORIES=	security gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Program that keeps passwords and other secrets

LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt

NO_STAGE=	yes
USE_XZ=		yes
USE_GNOME=	glib20 gnomehier gnomeprefix intlhack \
		introspection:build ltverhack
USES=		gettext gmake pathfix pkgconfig
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
