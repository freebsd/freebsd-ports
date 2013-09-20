# Created by: Josh Carroll <josh.carroll@gmail.com>
# $FreeBSD$

PORTNAME=	shaperprobe
PORTVERSION=	0.2
CATEGORIES=	net
MASTER_SITES=	http://www.cc.gatech.edu/~partha/diffprobe/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	josh.carroll@gmail.com
COMMENT=	Utility to check for traffic shapers

LICENSE=	GPLv2

MAKEFILE=	Makefile.osx
PLIST_FILES=	bin/prober

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/prober ${PREFIX}/bin/

.include <bsd.port.mk>
