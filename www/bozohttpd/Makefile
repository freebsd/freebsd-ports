# New ports collection makefile for:    bozohttpd
# Date created:         21.03.2002
# Whom:                 Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	bozohttpd
PORTVERSION=	20040823
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.eterna.com.au/bozohttpd/ \
		${MASTER_SITE_NETBSD}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	The bozotic HTTP server

USE_BZIP2=	YES

.if defined(WITH_HTPASSWD_SUPPORT)
CFLAGS+=	-DDO_HTPASSWD
MAKE_ARGS+=	'LDFLAGS+= -lcrypt'
.endif

.if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
CFLAGS+=	-UNO_SSL_SUPPORT
.else
CFLAGS+=	-DNO_SSL_SUPPORT
.endif

.if defined(NO_CGI)
CFLAGS+=	-DNO_CGIBIN_SUPPORT
.else
CFLAGS+=	-UNO_CGIBIN_SUPPORT
.endif

MAN8=		bozohttpd.8
MANCOMPRESSED=	maybe
PLIST_FILES=	libexec/bozohttpd

.include <bsd.port.mk>
