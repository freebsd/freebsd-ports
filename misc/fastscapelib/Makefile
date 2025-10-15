PORTNAME=	fastscapelib
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library of efficient algorithms for topographic data
WWW=		https://fastscapelib.readthedocs.io/en/latest/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	healpix>0:science/healpix \
		xtensor>0:math/xtensor
RUN_DEPENDS=	healpix>0:science/healpix \
		xtensor>0:math/xtensor

USES=		cmake:testing

USE_GITHUB=	yes
GH_ACCOUNT=	fastscape-lem

CMAKE_TESTING_ON=	FS_BUILD_TESTS

NO_ARCH=	yes

# tests as of 0.3.0: 100% tests passed, 0 tests failed out of 162

.include <bsd.port.mk>
