# New ports collection makefile for:    bozohttpd
# Date created:         21.03.2002
# Whom:                 Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	bozohttpd
PORTVERSION=	20090418
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.eterna.com.au/bozohttpd/ \
		${MASTER_SITE_NETBSD}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	The bozotic HTTP server

USE_BZIP2=	YES
USE_RC_SUBR=	bozohttpd

#options handling
OPTIONS=	HTPASSWD_SUPPORT	"Enable htpassord support" 	off \
		SSL			"Enable SSL support"		on \
		CGI			"Enable CGI support"		on

#make happy portlint
.if defined(WITHOUT_SSL)
.else
USE_OPENSSL=	yes
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_HTPASSWD_SUPPORT)
CFLAGS+=	-DDO_HTPASSWD
MAKE_ARGS+=	'LDFLAGS+= -lcrypt'
.endif

.if defined(WITHOUT_SSL)
CFLAGS+=	-DNO_SSL_SUPPORT
.else
#USE_OPENSSL=	yes
CFLAGS+=	-UNO_SSL_SUPPORT
.endif

.if defined(WITHOUT_CGI)
CFLAGS+=	-DNO_CGIBIN_SUPPORT
.else
CFLAGS+=	-UNO_CGIBIN_SUPPORT
.endif

MAN8=		bozohttpd.8
MANCOMPRESSED=	maybe
PLIST_FILES=	libexec/bozohttpd

.include <bsd.port.post.mk>
