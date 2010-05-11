# New ports collection makefile for:	eigen
# Date created:				2008-01-18
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	eigen
PORTVERSION=	2.0.12
PORTEPOCH=	1
CATEGORIES=	math
MASTER_SITES=	http://bitbucket.org/eigen/eigen/get/
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Lightweight library for vector and matrix math

USE_BZIP2=	yes
USE_CMAKE=	yes

LATEST_LINK=	${PORTNAME}2

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|share/pkgconfig|libdata/pkgconfig|g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
