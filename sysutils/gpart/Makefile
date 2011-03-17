# New ports collection makefile for:	gpart
# Date created:		29 Sep 1999
# Whom:			Andrew Stevenson <andrew@ugh.net.au>
#
# $FreeBSD$
#

PORTNAME=	gpart
PORTVERSION=	0.1h
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/filesystems

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tries to recover lost partition tables and file systems

DEPRECATED=	Upstream disappeared
EXPIRATION_DATE=	2011-09-15

USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
MAN8=		gpart.8
PLIST_FILES=	sbin/gpart

.if defined(WANT_STATIC)
MAKE_ARGS+=	LDFLAGS=-static
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${ARCH} != "alpha" && ${ARCH} != "amd64"
BROKEN=		Only compiles on i386, amd64 and alpha.
.endif

.include <bsd.port.post.mk>
