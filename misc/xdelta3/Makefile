# New ports collection makefile for:		xdelta
# Date created:    01 April 2007
# Whom:            Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	xdelta
DISTVERSION=	3.0.0
PORTREVISION?=	1
PORTEPOCH?=	1
CATEGORIES?=	misc devel
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}${DISTVERSION}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	Open-source binary diff, VCDIFF/RFC 3284 delta compression

USE_GMAKE=	yes
PLIST_FILES?=	bin/xdelta3

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64" && ${SLAVE_PORT:Myes}
BROKEN=		Does not compile on sparc64
.endif

post-patch:	master-post-patch

master-post-patch:	.SILENT
	${REINPLACE_CMD} -e '/^CFLAGS/s/=/+&/' \
		-e 's/-O3//; s/-g//' \
		-e '/^all:/,/^$$/ { s/:.*/: xdelta3/; s/make/$$(MAKE)/; }' \
		${WRKSRC}/Makefile

.if ${SLAVE_PORT:Mno}
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdelta3 ${PREFIX}/bin/
.endif

.if !target(test)
test:	build
	${WRKSRC}/xdelta3 test
.endif

.if !target(regression-test)
regression-test: build
	${WRKSRC}/testing/xdelta3-regtest
.endif

.include <bsd.port.post.mk>
