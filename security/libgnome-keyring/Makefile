# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/security/libgnome-keyring/Makefile 18965 2013-12-20 11:02:42Z kwm $

PORTNAME=	libgnome-keyring
PORTVERSION=	3.6.0
CATEGORIES=	security gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Program that keeps passwords and other secrets

LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt

USE_XZ=		yes
USE_GNOME=	glib20 gnomehier gnomeprefix intlhack \
		introspection:build ltverhack
USES=		gettext gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-vala

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so*

.include <bsd.port.mk>
