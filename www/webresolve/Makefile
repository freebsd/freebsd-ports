# New ports collection makefile for:	webresolve
# Date created:				Wed 6 Dec 2000
# Whom:					Joseph Scott <joseph@randomnetworks.com>
#
# $FreeBSD$
#

PORTNAME=	webresolve
PORTVERSION=	0.0.1
CATEGORIES=	www
MASTER_SITES=	ftp://siag.nu/pub/webresolve/

MAINTAINER=	joseph@randomnetworks.com

ALL_TARGET=	webresolve
MAKE_ARGS=	PREFIX=${PREFIX}

post-install:
	@strip ${PREFIX}/bin/webresolve

.include <bsd.port.mk>
