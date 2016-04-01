# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libsecret
PORTVERSION=	0.18.4
CATEGORIES=	security gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to access the secret service API

LICENSE=	LGPL21

BUILD_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl \
		vala:lang/vala
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt

USES=		gettext gmake gnome libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 libxslt:build intltool \
		introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-introspection
INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

.include <bsd.port.mk>
