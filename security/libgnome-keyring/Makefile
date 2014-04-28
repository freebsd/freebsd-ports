# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/security/libgnome-keyring/Makefile 19578 2014-04-25 21:50:30Z kwm $

PORTNAME=	libgnome-keyring
PORTVERSION=	3.12.0
CATEGORIES=	security gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Program that keeps passwords and other secrets

LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt

USE_GNOME=	glib20 gnomehier gnomeprefix intlhack \
		introspection:build
USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-vala

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so*

.include <bsd.port.mk>
