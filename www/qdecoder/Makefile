# New ports collection makefile for:    qDecoder library
# Version required:     5
# Date created:         Sep 10 1999
# Whom:                 CHOI Junho <cjh@kr.freebsd.org>
#
# $FreeBSD$
#

DISTNAME=	qDecoder-5.0.8
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.hongik.com/pub/qDecoder/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	cjh@kr.FreeBSD.org

post-install:
	${MKDIR} ${PREFIX}/share/examples/qDecoder
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/examples/qDecoder
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/qDecoder

.include <bsd.port.mk>
