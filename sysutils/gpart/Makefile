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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tries to recover lost partition tables and file systems

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_GMAKE=	yes
MAN8=		gpart.8
PLIST_FILES=	sbin/gpart

.if defined(WANT_STATIC)
MAKE_ARGS+= LDFLAGS=-static
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${ARCH} != "alpha"
BROKEN=		Does not compile on !i386 and !alpha
.endif

.include <bsd.port.post.mk>
