# $FreeBSD$

PORTNAME=	ascent
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0-11
DISTVERSIONSUFFIX=	-g0b137ac
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ simulation engine and differential equation solver

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	AnyarInc
GH_PROJECT=	Ascent

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	@cd ${WRKSRC}/include && ${COPYTREE_SHARE} ${PORTNAME} ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
