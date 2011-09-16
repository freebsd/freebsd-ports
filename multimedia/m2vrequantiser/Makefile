# New ports collection makefile for:   m2vrequantiser
# Date created: 	Thu Sep 14 20:47:38 CEST 2011
# Whom: 		Juergen Lock <nox@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	m2vrequantiser
PORTVERSION=	1.1
CATEGORIES=	multimedia
MASTER_SITES=	http://launchpadlibrarian.net/52366061/
DISTNAME=	M2VRequantiser-v${PORTVERSION}

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Requantize MPEG-2 streams without recompressing

PATCH_STRIP=	-p1
CFLAGS+=	-Duint=unsigned
MAKE_ARGS+=	CC=${CC} CXX=${CXX}
PLIST_FILES+=	bin/M2VRequantiser

.include <bsd.port.mk>
