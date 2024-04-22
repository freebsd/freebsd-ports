PORTNAME=	vfc
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.4
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library and tool for converting vertex formats
WWW=		https://github.com/akb825/VertexFormatConvert

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

NOT_FOR_ARCHS=	armv6
NOT_FOR_ARCHS_REASON=	requires NEON with FP16 support on ARM

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++14-lang

USE_GITHUB=	yes
GH_ACCOUNT=	akb825
GH_PROJECT=	VertexFormatConvert
GH_TUPLE=	g-truc:glm:bf71a834948186f4097caa076cd2663c69a10e1e:g_truc_glm/lib/glm \
		Tencent:rapidjson:a95e013:Tencent_rapidjson/tool/rapidjson

CMAKE_ON=	VFC_SHARED
CMAKE_OFF=	VFC_BUILD_TESTS
CMAKE_TESTING_ON=	VFC_BUILD_TESTS

CXXFLAGS+=	${CXXFLAGS_${ARCH}}
CXXFLAGS_armv7=	-mfpu=neon-fp16

.include <bsd.port.mk>
