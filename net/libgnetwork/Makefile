# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libgnetwork
PORTVERSION=	0.0.9
PORTREVISION=	11
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GLib-based networking wrapper

USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:bzip2
USE_GNOME=	gnomeprefix intlhack gconf2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

#.if !defined(WITHOUT_SSL)
#LIB_DEPENDS+=	gnutls.13:security/gnutls
#CONFIGURE_ARGS+=--enable-ssl=gnutls
#.else
CONFIGURE_ARGS+=--enable-ssl=no
#.endif

#pre-everything::
#	@${ECHO_MSG} ""
#	@${ECHO_MSG} "libgnetwork has the following configurable option(s):"
#	@${ECHO_MSG} "	WITHOUT_SSL	Disable GnuTLS SSL support"
#	@${ECHO_MSG} ""

.include <bsd.port.mk>
