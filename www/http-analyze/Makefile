# New ports collection makefile for: http-analyze
# Version required:     1.9e
# Date created:		Fri Jul 11 06:11:41 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

DISTNAME=       http-analyze2.01
PKGNAME=        http-analyze-2.01
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.rent-a-guru.de/pub/http-analyze2.01/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	andreas@FreeBSD.org

BUILD_DEPENDS=	${PREFIX}/lib/libgd.a:${PORTSDIR}/graphics/gd

BROKEN=		gd upgrade

MAN1=		http-analyze.1

.include <bsd.port.mk>
