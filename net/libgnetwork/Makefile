# New ports collection makefile for:	libgnetwork
# Date created:				11 December 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgnetwork
PORTVERSION=	0.0.5
PORTREVISION=	4
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.0
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GLib-based networking wrapper

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gconf2
INSTALLS_SHLIB=	yes
USE_INC_LIBTOOL_VER=13
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

#.if !defined(WITHOUT_SSL)
#LIB_DEPENDS+=	gnutls.12:${PORTSDIR}/security/gnutls
#CONFIGURE_ARGS+=--enable-ssl=gnutls
#.else
CONFIGURE_ARGS+=--enable-ssl=no
#.endif

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

pre-everything::
#	@${ECHO_MSG} ""
#	@${ECHO_MSG} "libgnetwork has the following configurable option(s):"
#	@${ECHO_MSG} "	WITHOUT_SSL	Disable GnuTLS SSL support"
#	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
