PORTNAME=	vfc
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.4
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library and tool for converting vertex formats

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	akb825
GH_PROJECT=	VertexFormatConvert
GH_TUPLE=	g-truc:glm:bf71a834948186f4097caa076cd2663c69a10e1e:g_truc_glm/lib/glm \
		Tencent:rapidjson:232389d4f1012dddec4ef84861face2d2ba85709:Tencent_rapidjson/tool/rapidjson

CMAKE_ON=	VFC_SHARED
CMAKE_OFF=	VFC_BUILD_TESTS
CMAKE_TESTING_ON=	VFC_BUILD_TESTS

.include <bsd.port.mk>
