PORTNAME=	cuttlefish
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.1
CATEGORIES=	misc
PKGNAMESUFFIX=	-texture-compressor

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Texture compression library and tool

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

TEST_DEPENDS=	ispc:devel/ispc

USES=		cmake:testing compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	akb825
GH_PROJECT=	Cuttlefish
GH_TUPLE=	akb825:freeimage:dae76e95cd4a9fbb58b0a6d635fd3c3f4b222076:akb825_freeimage/lib/FreeImage \
		akb825:etc2comp:10ec1fc4987c5a81c48c6bf6319bb77389a5f23a:akb825_etc2comp/lib/etc2comp \
		ARM-software:astc-encoder:f48cc27b2528286126c116f42f2792ed2fa13755:ARM_software_astc_encoder/lib/astc-encoder \
		g-truc:glm:bf71a834948186f4097caa076cd2663c69a10e1e:g_truc_glm/lib/glm \
		akb825:PVRTexToolLib:ea50a1c0fb4d8eed2f06ecc47eea80ef291b63b9:akb825_PVRTexToolLib/lib/PVRTexToolLib \
		richgel999:bc7enc_rdo:f965c3fd8a39ef91f8bf8cddb7d2eee83a95a1c2:richgel999_bc7enc_rdo/lib/bc7enc_rdo \
		GPUOpen-Tools:compressonator:a429164726337b83fd8e20871eb74f5be1d6ef1c:GPUOpen_Tools_compressonator/lib/compressonator \
		GameTechDev:ISPCTextureCompressor:14d998c02b71c356ff3a1ec1adc9243a517bbf38:GameTechDev_ISPCTextureCompressor/lib/ISPCTextureCompressor \
		akb825:libsquish:a9087786ced42a1a4ee137c1ad5bf197dd2d6b72:akb825_libsquish/lib/libsquish \
		google:googletest:703bd9caab50b139428cea1aaff9974ebee5742e:google_googletest/lib/astc-encoder/Source/GoogleTest

CMAKE_OFF=	CUTTLEFISH_BUILD_DOCS CUTTLEFISH_BUILD_TESTS
CMAKE_ON=	CUTTLEFISH_SHARED
CMAKE_TESTING_ON=	CUTTLEFISH_BUILD_TESTS

.include <bsd.port.mk>
