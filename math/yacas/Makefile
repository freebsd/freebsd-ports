# Created by: ijliao
# $FreeBSD$

PORTNAME=	yacas
PORTVERSION=	1.8.0
PORTREVISION=	0
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Yet Another Computer Algebra System

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	bash:shells/bash \

BUILD_DEPENDS=	googletest>0:devel/googletest

CMAKE_ARGS=	-DENABLE_DOCS:BOOL=OFF \
		-DENABLE_CYACAS_CONSOLE:BOOL=ON \
		-DENABLE_CYACAS_KERNEL:BOOL=OFF \
		-DENABLE_CYACAS_GUI:BOOL=OFF \
		-DENABLE_JYACAS:BOOL=OFF \
		-DENABLE_CYACAS_UNIT_TESTS:BOOL=ON \
		-DENABLE_CYACAS_BENCHMARKS:BOOL=OFF

TEST_TARGET=	test

USES=		cmake compiler:c++17-lang
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	grzegorzmazur

PLIST_SUB=	SHLIB_VERSION=${PORTVERSION:S/.//}.0

post-patch:
#	Can't use USES=shebangfix here, cause the path appears several
#	times in the file.
	@${REINPLACE_CMD} -e 's| /bin/bash| ${LOCALBASE}/bin/bash|g' \
		${WRKSRC}/tests/test-yacas
	@${REINPLACE_CMD} -e '/^install/s|^|#|' \
		${WRKSRC}/tests/CMakeLists.txt

.include <bsd.port.mk>
