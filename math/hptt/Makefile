PORTNAME=	hptt
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.5-18
PORTREVISION=	1
DISTVERSIONSUFFIX=	-g9425386
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High-Performance Tensor Transpose library
WWW=		https://github.com/springer13/hptt

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

TEST_DEPENDS=	gmake:devel/gmake

USES=		cmake:testing compiler:c++11-lang
USE_GCC=	yes # workaround for https://github.com/springer13/hptt/issues/21

USE_GITHUB=	yes
GH_ACCOUNT=	springer13

CMAKE_ON=	BUILD_SHARED_LIBS

do-test: # tests fail to build, see https://github.com/springer13/hptt/issues/23
	@cd ${WRKSRC}/testframework && ${SETENV} ${MAKE_ENV} ${GMAKE} FREEBSD_GCC_DEFAULT=${GCC_DEFAULT} all

.include <bsd.port.mk>
