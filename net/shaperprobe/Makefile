# Created by: Josh Carroll <josh.carroll@gmail.com>
# $FreeBSD$

PORTNAME=	shaperprobe
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.cc.gatech.edu/~partha/diffprobe/
DISTNAME=	${PORTNAME}

MAINTAINER=	josh.carroll@gmail.com
COMMENT=	Utility to check for traffic shapers

LICENSE=	GPLv2

USES=		tar:tgz

MAKEFILE=	Makefile.osx
ALL_TARGET=	prober

PLIST_FILES=	bin/prober

post-patch:
# Unbreak the build against Clang
	@${REINPLACE_CMD} -E '/getLevelShift|smoothFilterRate/s,^inline ,,' \
		${WRKSRC}/tbdetect.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/prober ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
