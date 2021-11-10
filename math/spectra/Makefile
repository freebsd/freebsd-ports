PORTNAME=	spectra
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for large scale eigenvalue problems

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	gmake>0:devel/gmake

USES=		cmake eigen:3,build,run

USE_GITHUB=	yes
GH_ACCOUNT=	yixuan

NO_ARCH=	yes

do-test: # some tests are known to fail: https://github.com/yixuan/spectra/issues/47
	@cd ${WRKSRC}/test && ${SETENV} ${MAKE_ENV} CXXFLAGS=-I${LOCALBASE}/include/eigen3 ${GMAKE} all test

.include <bsd.port.mk>
