PORTNAME=	cuttlefish
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.3
CATEGORIES=	misc
PKGNAMESUFFIX=	-texture-compressor

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Texture compression library and tool
WWW=		https://github.com/akb825/Cuttlefish

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libfreeimage.so:graphics/freeimage
TEST_DEPENDS=	ispc:devel/ispc

USES=		cmake:testing compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	akb825
GH_PROJECT=	Cuttlefish
GH_TUPLE=	akb825:etc2comp:10ec1fc4987c5a81c48c6bf6319bb77389a5f23a:akb825_etc2comp/lib/etc2comp \
		ARM-software:astc-encoder:5a5b5a1:ARM_software_astc_encoder/lib/astc-encoder \
		g-truc:glm:bf71a834948186f4097caa076cd2663c69a10e1e:g_truc_glm/lib/glm \
		akb825:PVRTexToolLib:5c0047d:akb825_PVRTexToolLib/lib/PVRTexToolLib \
		richgel999:bc7enc_rdo:e6990bc11829c072d9f9e37296f3335072aab4e4:richgel999_bc7enc_rdo/lib/bc7enc_rdo \
		GPUOpen-Tools:compressonator:38081a0:GPUOpen_Tools_compressonator/lib/compressonator \
		GameTechDev:ISPCTextureCompressor:cd0ef2cf78a80db293d7609100f027960f9e7205:GameTechDev_ISPCTextureCompressor/lib/ISPCTextureCompressor \
		akb825:libsquish:a9087786ced42a1a4ee137c1ad5bf197dd2d6b72:akb825_libsquish/lib/libsquish

CMAKE_OFF=	CUTTLEFISH_BUILD_DOCS CUTTLEFISH_BUILD_TESTS
CMAKE_ON=	CUTTLEFISH_SHARED
CMAKE_TESTING_ON=	CUTTLEFISH_BUILD_TESTS # many tests fail, see https://github.com/akb825/Cuttlefish/issues/19

CXXFLAGS_powerpc=	-maltivec

.include <bsd.port.mk>
