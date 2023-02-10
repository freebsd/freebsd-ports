PORTNAME=	mathpresso
DISTVERSION=	g20230108
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Mathematical expression parser and JIT compiler
WWW=		https://github.com/kobalicek/mathpresso

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libasmjit.so:devel/asmjit

USES=		cmake:testing localbase:ldflags
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	kobalicek
GH_TAGNAME=	734c292

CMAKE_ARGS=	-DASMJIT_CFLAGS="-I${LOCALBASE}/include" -DASMJIT_LIBS=asmjit
CMAKE_TESTING_ON=	MATHPRESSO_TEST
CMAKE_TESTING_TARGET=	mptest

post-test:
	@cd ${TEST_WRKSRC} && ./mptest

.include <bsd.port.mk>
