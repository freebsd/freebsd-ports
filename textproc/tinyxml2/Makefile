PORTNAME=	tinyxml2
PORTVERSION=	11.0.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	textproc

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Small C++ XML Parser
WWW=		https://leethomason.github.io/tinyxml2/ \
		https://github.com/leethomason/tinyxml2

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake:testing compiler:c++11-lang cpe dos2unix

CMAKE_OFF=	tinyxml2_BUILD_TESTING
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	tinyxml2_BUILD_TESTING
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

USE_GITHUB=     yes
GH_ACCOUNT=     leethomason

CPE_VENDOR=	tinyxml2_project

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} resources ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
