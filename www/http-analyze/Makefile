# New ports collection makefile for: http-analyze
# Version required:     1.9e
# Date created:		Fri Jul 11 06:11:41 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id$
#

DISTNAME=       http-analyze1.9e
PKGNAME=        http-analyze-1.9
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.rent-a-guru.de/pub/

BUILD_DEPENDS=	${PREFIX}/lib/libgd.a:${PORTSDIR}/graphics/gd

MAINTAINER=	andreas@FreeBSD.ORG

MAN1=		http-analyze.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/http-analyze ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/http-analyze.man \
		${PREFIX}/man/man1/http-analyze.1

.include <bsd.port.mk>
