PORTNAME=	btor2tools
DISTVERSION=	1.0.3
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Generic parser and tool package for the BTOR2 format
WWW=		https://github.com/Boolector/btor2tools

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake cpe
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM:STRING=3.5 # CMake 4 compatibility, see https://github.com/hwmcc/btor2tools/issues/33

CPE_VENDOR=	${PORTNAME}_project

USE_GITHUB=	yes
GH_ACCOUNT=	Boolector
GH_TAGNAME=	037f1fa

MAKEFILE=	makefile

PLIST_FILES=	bin/btorsim \
		bin/btorsplit \
		bin/catbtor \
		include/btor2parser.h \
		lib/libbtor2parser.so

do-test:
	@cd ${WRKSRC} && LD_LIBRARY_PATH=${STAGEDIR}${PREFIX}/lib BINDIR=${BUILD_WRKSRC}/bin test/runtests.sh

# tests as of 1.0.3: 67 ok 67 total

.include <bsd.port.mk>
