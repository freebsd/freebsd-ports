PORTNAME=	dionysus
PORTVERSION=	g20210521
CATEGORIES=	math
PKGNAMESUFFIX=	-topology-library

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for computing persistent homology

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/include/boost/range/adaptors.hpp:devel/boost-libs
RUN_DEPENDS=	${LOCALBASE}/include/boost/range/adaptors.hpp:devel/boost-libs

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	mrzv
GH_TAGNAME=	ae27bb1

CMAKE_OFF=	build_examples build_python_bindings

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	cd ${WRKSRC}/include && ${COPYTREE_SHARE} ${PORTNAME} ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
