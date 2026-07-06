PORTNAME=	assimp
DISTVERSIONPREFIX=	v
DISTVERSION=	6.0.5
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to import various 3D model formats in a uniform manner
WWW=		https://www.assimp.org \
		https://github.com/assimp/assimp

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rapidjson>0:devel/rapidjson \
		utf8cpp>0:devel/utf8cpp

USES=		cmake:testing compiler:c++17-lang cpe localbase:ldflags \
		pathfix pkgconfig minizip
USE_LDCONFIG=	yes

USE_GITHUB=	yes

EXTRACT_AFTER_ARGS=	--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/contrib/rapidjson	\
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/contrib/unzip \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/contrib/utf8cpp \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/contrib/zlib \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/test \
			--no-same-owner --no-same-permissions

CXXFLAGS+=	-I${LOCALBASE}/include/utf8cpp

CMAKE_TESTING_ON=	ASSIMP_BUILD_TESTS
CMAKE_TESTING_TARGET=

CMAKE_OFF=		ASSIMP_BUILD_TESTS \
			ASSIMP_BUILD_MINIZIP \
			ASSIMP_BUILD_ZLIB \
			BUILD_STATIC_LIBS

pre-test:
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
	    -C ${WRKDIR} --include ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/test \
	    --no-same-owner --no-same-permissions
	@${RLN} ${WRKSRC}/test ${CONFIGURE_WRKSRC}/test

post-test:
	@cd ${BUILD_WRKSRC} && \
		${BUILD_WRKSRC}/bin/unit

.include <bsd.port.mk>
