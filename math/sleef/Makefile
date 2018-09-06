# Created by: Johannes M Dieterich <jmd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sleef
DISTVERSION=	3.3-9
DISTVERSIONSUFFIX=	-g3998463
CATEGORIES=	math

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	SIMD Library for Evaluating Elementary Functions, vectorized libm

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

IGNORE_FreeBSD_10=	base compiler too old

USES=		cmake:outsource
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	shibatch

.include <bsd.port.mk>
