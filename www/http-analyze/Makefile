# New ports collection makefile for: http-analyze
# Version required:     1.9e
# Date created:		Fri Jul 11 06:11:41 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.1.1.1 1997/07/11 04:54:53 andreas Exp $
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
	${INSTALL_MAN} ${WRKSRC}/http-analyze.man \
		${PREFIX}/man/man1/http-analyze.1

.include <bsd.port.mk>
