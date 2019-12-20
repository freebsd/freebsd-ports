# $FreeBSD$

PORTNAME=	palisade
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.0.b.20191219
CATEGORIES=	security math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PALISADE lattice cryptography library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/License.md

BUILD_DEPENDS=	autoconf:devel/autoconf # possibly a mistake in the project

USES=		cmake:noninja localbase
USE_GITLAB=	yes
USE_GITHUB=	nodefault
GL_PROJECT=	palisade-development
GL_COMMIT=	db57986b98596b176ca4d1f8426fb4d9af35515c
GH_TUPLE=	\
		JerryRyan:cereal:181fbcd3:cereal/third-party/cereal \
		google:benchmark:c50ac68c:benchmark/third-party/google-benchmark \
		google:googletest:78fdd6c0:google_test/third-party/google-test \
		gperftools:gperftools:c1d546d7:gperftools/third-party/gperftools
USE_GCC=	any # clang fails: fatal error: 'quadmath.h' file not found
USE_LDCONFIG=	yes

TEST_TARGET=	testall

CMAKE_ON=	BUILD_TESTING

CXXFLAGS+=	-I${WRKSRC}/third-party/google-test/googletest

post-extract: # post-extract to not interfere with patches in files/, see https://gitlab.com/palisade/palisade-release/issues/4
	@${FIND} ${WRKSRC} -name CMakeLists.txt | ${XARGS} ${REINPLACE_CMD} -e 's|DESTINATION palisade/|DESTINATION |'

.include <bsd.port.mk>
