# New ports collection makefile for:	libproxy
# Date created:		26 February 2009
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libproxy
PORTVERSION=	0.2.3
PORTREVISION?=	0
CATEGORIES?=	net devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	Library that provides automatic proxy configuration management

USE_GMAKE=	yes
USE_GNOME+=	gnomehack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS?=--without-gnome --without-kde --without-webkit \
		--without-mozjs --without-networkmanager --with-python \
		--with-envvar --with-file

PLIST_SUB+=	VERSION=${PORTVERSION}

.if !defined(LIBPROXY_SLAVE)
USE_LDCONFIG=	yes
USE_PYTHON=	yes
CONFLICTS=	libmonetra-[0-9]*
.endif

.include <bsd.port.mk>
