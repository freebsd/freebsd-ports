# $FreeBSD$

PORTNAME=	spectra
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.2
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for large scale eigenvalue problems

LICENSE=	MPL20

USES=		eigen:3,run
USE_GITHUB=	yes
GH_ACCOUNT=	yixuan
NO_BUILD=	yes
NO_ARCH=	yes

TEST_RUN_DEPENDS=	gmake>0:devel/gmake

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} include ${STAGEDIR}${PREFIX}

do-test: # some tests are known to fail: https://github.com/yixuan/spectra/issues/47
	@cd ${WRKSRC}/test && ${SETENV} ${MAKE_ENV} CXXFLAGS=-I${LOCALBASE}/include/eigen3 ${GMAKE} all test

.include <bsd.port.mk>
