# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libgnetwork
PORTVERSION=	0.0.9
PORTREVISION=	8
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GLib-based networking wrapper

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USES=		gettext gmake pkgconfig
USE_GNOME=	gnomeprefix gnomehack intlhack gconf2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

#.if !defined(WITHOUT_SSL)
#LIB_DEPENDS+=	gnutls.13:${PORTSDIR}/security/gnutls
#CONFIGURE_ARGS+=--enable-ssl=gnutls
#.else
CONFIGURE_ARGS+=--enable-ssl=no
#.endif

NO_STAGE=	yes
#pre-everything::
#	@${ECHO_MSG} ""
#	@${ECHO_MSG} "libgnetwork has the following configurable option(s):"
#	@${ECHO_MSG} "	WITHOUT_SSL	Disable GnuTLS SSL support"
#	@${ECHO_MSG} ""

.include <bsd.port.mk>
