# $FreeBSD$

PORTNAME=	s2geometry
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0-27
DISTVERSIONSUFFIX=	-g0c4c460
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Geometry library for manipulating geometric shapes

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang ssl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	google

CMAKE_OFF=	BUILD_EXAMPLES

.include <bsd.port.mk>
