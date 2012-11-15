# Created by: arved
# $FreeBSD$

PORTNAME=	eigen
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://download.tuxfamily.org/eigen/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Lightweight library for vector and matrix math

DEPRECATED=	Development for 1.x series has long ceased, use math/eigen3
EXPIRATION_DATE=2012-12-15

USE_CMAKE=	yes
CMAKE_SOURCE_PATH=	..
WRKSRC=		${WRKDIR}/${PORTNAME}/build

post-patch:
	${MKDIR} ${WRKSRC}

.include <bsd.port.mk>
