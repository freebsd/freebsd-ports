# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports-experimental/trunk/security/libsecret/Makefile 19553 2014-04-20 07:23:27Z gusi $

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

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsecret-1.so.0

.include <bsd.port.mk>
