# New ports collection makefile for:	eigen
# Date created:				2008-01-18
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	eigen
PORTVERSION=	3.1.0
CATEGORIES=	math
MASTER_SITES=	https://bitbucket.org/${PORTNAME}/${PORTNAME}/get/
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Lightweight library for vector and matrix math

LICENSE=	LGPL3 GPLv2
LICENSE_COMB=	dual

USE_BZIP2=	yes
USE_CMAKE=	yes
CMAKE_OUTSOURCE=yes
CMAKE_ENV+=	PKG_CONFIG_LIBDIR="${CMAKE_INSTALL_PREFIX}/libdata"
NO_BUILD=	yes

LATEST_LINK=	${PORTNAME}3

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME}-ca142d0540d3

.include <bsd.port.mk>
