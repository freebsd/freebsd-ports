# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nocatsplash
PORTVERSION=	0.82
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://farrokhi.net/distfiles/ \
		http://BSDforge.com/projects/source/net/nocatsplash/
DISTNAME=	NoCatSplash-nightly

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Open 802.11 Splash Screen

DEPRECATED=	Uses obsolete glib12
EXPIRATION_DATE=	2018-12-20

LICENSE=	GPLv2

USE_GNOME=	glib12

CONFLICTS=	nocatauth-server-[0-9]*

GNU_CONFIGURE=	yes
USES=		gmake tar:tgz

CONFIGURE_ARGS+=	--disable-dependency-tracking
CONFIGURE_ARGS+=	--disable-glibtest
CONFIGURE_ARGS+=	--with-firewall=pfctl
CONFIGURE_ARGS+=	--with-ghttpd
.if defined(AUTHMODE)
CONFIGURE_ARGS+=	--with-mode=${AUTHMODE}
.endif
.if defined(DOCROOT)
CONFIGURE_ARGS+=	--with-docroot=${DOCROOT}
.endif

USERS=		nocat
GROUPS=		nocat

.include <bsd.port.mk>
