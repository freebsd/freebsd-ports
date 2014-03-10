# Created by: Josh Carroll <josh.carroll@gmail.com>
# $FreeBSD$

PORTNAME=	shaperprobe
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.cc.gatech.edu/~partha/diffprobe/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	josh.carroll@gmail.com
COMMENT=	Utility to check for traffic shapers

LICENSE=	GPLv2

USE_GCC=	yes

MAKEFILE=	Makefile.osx
PLIST_FILES=	bin/prober

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/prober ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
