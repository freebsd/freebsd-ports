PORTNAME=	toml-f
DISTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	TOML parser for data serialization and deserialization in Fortran
WWW=		https://toml-f.github.io/toml-f/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

BROKEN_aarch64=	cannot find an intrinsic module named 'ieee_arithmetic'

USES=		cmake:testing fortran tar:xz
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	FREEBSD_BUILD_TESTS

post-patch: # see https://github.com/toml-f/toml-f/issues/51
	@${REINPLACE_CMD} -e 's|$${CMAKE_Fortran_COMPILER_ID}-$${CMAKE_Fortran_COMPILER_VERSION}||' ${WRKSRC}/config/CMakeLists.txt

.include <bsd.port.mk>
