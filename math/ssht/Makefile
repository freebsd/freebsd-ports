PORTNAME=	ssht
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast and exact spin spherical harmonic transforms

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	fftw3>0:math/fftw3 # see https://github.com/astro-informatics/ssht/issues/6

USES=		cmake:testing pkgconfig # tests clone cmocka, see https://github.com/astro-informatics/ssht/issues/63

USE_GITHUB=	yes
GH_ACCOUNT=	astro-informatics

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTING

.include <bsd.port.mk>
