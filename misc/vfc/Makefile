PORTNAME=	vfc
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.6
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
GH_TUPLE=	g-truc:glm:0af55cc:g_truc_glm/lib/glm \
		Tencent:rapidjson:858451e:Tencent_rapidjson/tool/rapidjson

CMAKE_ON=	VFC_SHARED
CMAKE_OFF=	VFC_BUILD_TESTS
CMAKE_TESTING_ON=	VFC_BUILD_TESTS

CXXFLAGS+=	${CXXFLAGS_${ARCH}}
CXXFLAGS_armv7=	-mfpu=neon-fp16

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:tu}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

# 100% tests passed, 0 tests failed out of 4

.include <bsd.port.mk>
