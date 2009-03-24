# New ports collection makefile for:	eigen
# Date created:				2008-01-18
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	eigen
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://download.tuxfamily.org/eigen/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Lightweight library for vector and matrix math

USE_CMAKE=	yes
CMAKE_SOURCE_PATH=	..
WRKSRC=		${WRKDIR}/${PORTNAME}/build

post-patch:
	${MKDIR} ${WRKSRC}

.include <bsd.port.mk>
