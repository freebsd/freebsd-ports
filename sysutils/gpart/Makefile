# New ports collection makefile for:	gpart
# Date created:		29 Sep 1999
# Whom:			Andrew Stevenson <andrew@ugh.net.au>
#
# $FreeBSD$
#

PORTNAME=	gpart
PORTVERSION=	0.1h
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/filesystems

MAINTAINER=	andrew@ugh.net.au
COMMENT=	Tries to recover lost partition tables and file systems

USE_GMAKE=	yes
MAN8=		gpart.8

.if defined(WANT_STATIC)
MAKE_ARGS+= LDFLAGS=-static
.endif

.include <bsd.port.mk>
