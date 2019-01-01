# Created by: b.f. <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tinyxml2
PORTVERSION=	7.0.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	textproc

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Small C++ XML Parser

LICENSE=	ZLIB

OPTIONS_DEFINE=	EXAMPLES

CMAKE_OFF=	BUILD_TESTS
CMAKE_ON=	BUILD_SHARED_LIBS
USES=		cmake:insource compiler:c++11-lang dos2unix pathfix
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}
PORTEXAMPLES=	*

GH_ACCOUNT=	leethomason
USE_GITHUB=	yes

post-patch:
	@${REINPLACE_CMD} -e '/CMAKE_DEBUG_POSTFIX/d' ${WRKSRC}/CMakeLists.txt

post-install:
	${AR} cq ${STAGEDIR}${PREFIX}/lib/libtinyxml2.a ${WRKSRC}/CMakeFiles/tinyxml2.dir/tinyxml2.cpp.o
	
post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} resources ${STAGEDIR}${EXAMPLESDIR}/

do-test:
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} xmltest && ./xmltest

.include <bsd.port.mk>
