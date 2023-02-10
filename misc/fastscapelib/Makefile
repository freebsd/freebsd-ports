PORTNAME=	fastscapelib
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.3-53
DISTVERSIONSUFFIX=	-g5698347
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library of efficient algorithms for topographic data
WWW=		https://fastscapelib.readthedocs.io/en/latest/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	xtensor>0:math/xtensor
RUN_DEPENDS=	xtensor>0:math/xtensor

USES=		cmake:testing

USE_GITHUB=	yes
GH_ACCOUNT=	fastscape-lem

CMAKE_TESTING_ON=	BUILD_TESTS

NO_ARCH=	yes

.include <bsd.port.mk>
