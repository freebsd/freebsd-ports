# New ports collection makefile for:	shaperprobe
# Date created:		2011-06-11
# Whom:			Josh Carroll <josh.carroll@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	shaperprobe
PORTVERSION=	0.1
CATEGORIES=	net
MASTER_SITES=	http://www.cc.gatech.edu/~partha/diffprobe/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	josh.carroll@gmail.com
COMMENT=	Utility to check for traffic shapers

MAKEFILE=	Makefile.osx
PLIST_FILES=	bin/prober

do-install:
	@${INSTALL} ${WRKSRC}/prober ${PREFIX}/bin

.include <bsd.port.mk>
