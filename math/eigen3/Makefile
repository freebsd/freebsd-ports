# New ports collection makefile for:	eigen
# Date created:				2008-01-18
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	eigen
DISTVERSION=	2.0.52
CATEGORIES=	math
MASTER_SITES=	http://ns.ael.ru/~fluffy.khv/ \
		http://download.tuxfamily.org/eigen/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Lightweight library for vector and matrix math

USE_BZIP2=	yes
USE_CMAKE=	yes

LATEST_LINK=	${PORTNAME}2

post-patch:
	@${REINPLACE_CMD} -e 's|lib/pkgconfig|libdata/pkgconfig|g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
