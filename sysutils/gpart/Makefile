# New ports collection makefile for:	gpart
# Date created:		29 Sep 1999
# Whom:			Andrew Stevenson <andrew@ugh.net.au>
#
# $FreeBSD$
#

PORTNAME=	gpart
PORTVERSION=	0.1h
CATEGORIES=	sysutils
MASTER_SITES=	http://home.pages.de/~michab/gpart/ \
		http://www.stud.uni-hannover.de/user/76201/gpart/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/filesystems

MAINTAINER=	andrew@ugh.net.au

USE_GMAKE=	yes
MAN8=		gpart.8

.if defined(WANT_STATIC)
MAKE_ARGS+= LDFLAGS=-static
.endif

.include <bsd.port.mk>
