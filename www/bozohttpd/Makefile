# New ports collection makefile for:    bozohttpd
# Date created:         21.03.2002
# Whom:                 Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	bozohttpd
PORTVERSION=	20031005
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.eterna.com.au/bozohttpd/

MAINTAINER=	Janos.Mohacsi@bsd.hu
COMMENT=	The bozotic HTTP server

USE_BZIP2=	YES

.if defined(WITH_HTPASSWD_SUPPORT)
CFLAGS+=	-DDO_HTPASSWD
MAKE_ARGS+=	'LDFLAGS+= -lcrypt'
.endif

MAN8=		bozohttpd.8
MANCOMPRESSED=	maybe
PLIST_FILES=	libexec/bozohttpd

.include <bsd.port.mk>
