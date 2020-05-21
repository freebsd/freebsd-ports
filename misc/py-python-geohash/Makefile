# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	python-geohash
DISTVERSION=	0.8.5
PORTREVISION=	2
CATEGORIES=	misc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast, accurate python geohashing library

LICENSE=	APACHE20 MIT BSD3CLAUSE
LICENSE_COMB=	multi

USES=		python
USE_PYTHON=	autoplist distutils

post-install:
	@${STRIP_CMD} ${STAGEDIR}/${PYTHON_SITELIBDIR}/_geohash.so

.include <bsd.port.mk>
