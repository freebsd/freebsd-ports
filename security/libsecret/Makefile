# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/security/libsecret/Makefile 19814 2014-08-15 20:17:00Z gusi $

PORTNAME=	libsecret
PORTVERSION=	0.18
CATEGORIES=	security gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to access the secret service API

BUILD_DEPENDS=	docbook-xsl>=0:${PORTSDIR}/textproc/docbook-xsl
LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt

USES=		gettext gmake pathfix pkgconfig tar:xz
USE_GNOME=	gnomehier glib20 libxslt:build intltool \
		introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-introspection
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
