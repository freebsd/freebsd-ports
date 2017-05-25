# Created by: b.f. <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tinyxml2
PORTVERSION=	4.0.1
PORTEPOCH=	1
CATEGORIES=	textproc

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Small C++ XML Parser

LICENSE=	ZLIB

CMAKE_ARGS=	-DBUILD_SHARED_LIBS:BOOL=ON -DBUILD_STATIC_LIBS:BOOL=ON
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USES=		cmake dos2unix

GH_ACCOUNT=	leethomason

PLIST_FILES=	include/tinyxml2.h \
		lib/libtinyxml2.a \
		lib/libtinyxml2.so \
		lib/libtinyxml2.so.4 \
		lib/libtinyxml2.so.4.0.1 \
		libdata/pkgconfig/tinyxml2.pc
PORTEXAMPLES=	xmltest.cpp resources

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's@(DESTINATION )(.*)(/pkgconfig)@\1${PREFIX}/libdata\3@' \
		${WRKSRC}/CMakeLists.txt

check regression-test test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test ; \
	./test

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC}; ${COPYTREE_SHARE} "${PORTEXAMPLES}" ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
