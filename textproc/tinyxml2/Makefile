# Created by: b.f. <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tinyxml2
PORTVERSION=	6.2.0
PORTEPOCH=	1
CATEGORIES=	textproc

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Small C++ XML Parser

LICENSE=	ZLIB

OPTIONS_DEFINE=	EXAMPLES

CMAKE_OFF=	BUILD_TESTS
CMAKE_ON=	BUILD_SHARED_LIBS BUILD_STATIC_LIBS
USE_LDCONFIG=	yes
USES=		cmake dos2unix pathfix

PLIST_SUB=	PORTVERSION=${PORTVERSION}
PORTEXAMPLES=	*

GH_ACCOUNT=	leethomason
USE_GITHUB=	yes

post-patch:
	@${REINPLACE_CMD} -e '/CMAKE_DEBUG_POSTFIX/d' ${WRKSRC}/CMakeLists.txt

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} resources ${STAGEDIR}${EXAMPLESDIR}/

do-test:
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} xmltest && ./xmltest

.include <bsd.port.mk>
