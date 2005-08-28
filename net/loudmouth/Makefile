# New ports collection makefile for:	loudmouth
# Date created:				08 July 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	loudmouth
PORTVERSION=	1.0.1
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.0

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Lightweight Jabber client library

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack glib20
CONFIGURE_ARGS=	--disable-gtk-doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	GNUTLS "Enable SSL (via GnuTLS) support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GNUTLS)
LIB_DEPENDS+=		gnutls.12:${PORTSDIR}/security/gnutls
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

.include <bsd.port.post.mk>
