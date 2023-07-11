PORTNAME=	hyperdeal
DISTVERSION=	g20230706
CATEGORIES=	math

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	6552f1e745f2fa03573b005e93104b0663a44c23.patch:-p1 # https://github.com/hyperdeal/hyperdeal/pull/117/commits

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Finite-element library for partial differential equations
WWW=		https://github.com/hyperdeal/hyperdeal

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE.MD

LIB_DEPENDS=	libdeal_II.so:math/deal.ii # many other dependencies are erroneously induced by deal.ii, see https://github.com/dealii/dealii/issues/15714

USES=		cmake
USE_LDCONFIG=	yes
USE_CXXSTD=	c++17 # workaround for https://github.com/hyperdeal/hyperdeal/issues/115

CXXFLAGS+=	-fPIC
CMAKE_ON=	BUILD_SHARED_LIBS

USE_GITHUB=	yes
GH_TAGNAME=	b73a216

do-install:
	# headers
	cd ${WRKSRC}/include && ${COPYTREE_SHARE} hyper.deal  ${STAGEDIR}${PREFIX}/include
	${RM} ${STAGEDIR}${PREFIX}/include/hyper.deal/base/revision.h.in
	${INSTALL_DATA} ${BUILD_WRKSRC}/include/hyper.deal/base/revision.h ${STAGEDIR}${PREFIX}/include/hyper.deal/base
	# lib
	${INSTALL_LIB} ${BUILD_WRKSRC}/libhyperdeal.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
