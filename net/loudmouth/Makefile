# New ports collection makefile for:	loudmouth
# Date created:				08 July 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	loudmouth
PORTVERSION=	0.15.1
PORTREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.15

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Lightweight Jabber client library

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack glib20
CONFIGURE_ARGS=	--disable-gtk-doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libgnutls.so)
WITH_GNUTLS=	yes
.endif

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=		gnutls.7:${PORTSDIR}/security/gnutls
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Loudmouth has the following tunable option(s):"
	@${ECHO_MSG} "	WITH_GNUTLS	Enable SSL (via GnuTLS) support"
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
