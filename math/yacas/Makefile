PORTNAME=	yacas
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.1
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Yet Another Computer Algebra System
WWW=		https://www.yacas.org/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	bash:shells/bash \
		googletest>0:devel/googletest

USES=		cmake:testing compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	grzegorzmazur

PLIST_SUB=	SHLIB_VERSION=${PORTVERSION:S/.//}.0

CMAKE_TESTING_ON=	ENABLE_CYACAS_UNIT_TESTS

CMAKE_OFF=	ENABLE_DOCS \
		ENABLE_CYACAS_BENCHMARKS \
		ENABLE_CYACAS_KERNEL \
		ENABLE_CYACAS_GUI \
		ENABLE_JYACAS \

CMAKE_ON=	ENABLE_CYACAS_CONSOLE

post-patch:
#	Can't use USES=shebangfix here, because the path appears several
#	times in the file.
	@${REINPLACE_CMD} -e 's| /bin/bash| ${LOCALBASE}/bin/bash|g' \
		${WRKSRC}/tests/test-yacas
	@${REINPLACE_CMD} -e '/^install/s|^|#|' \
		${WRKSRC}/tests/CMakeLists.txt

.include <bsd.port.mk>
