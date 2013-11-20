# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/net/gnome-online-accounts/Makefile 18904 2013-11-19 08:59:04Z gusi $

PORTNAME=	gnome-online-accounts
PORTVERSION=	3.6.3
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Interface privider to access the user's online accounts.

BUILD_DEPENDS=	docbook-xsl>=0:${PORTSDIR}/textproc/docbook-xsl
LIB_DEPENDS=	libwebkitgtk-3.0.so:${PORTSDIR}/www/webkit-gtk3 \
		libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring \
		libsecret-1.so:${PORTSDIR}/security/libsecret \
		librest-0.7.so:${PORTSDIR}/devel/librest

USE_XZ=		yes
USE_GNOME=	gtk30 intlhack introspection:build libxslt:build
USES=		gettext gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgoa-*.so.0

.include <bsd.port.mk>
