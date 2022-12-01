PORTNAME=	cuttlefish
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.0
CATEGORIES=	misc
PKGNAMESUFFIX=	-texture-compressor

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Texture compression library and tool
WWW=		https://github.com/akb825/Cuttlefish

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libfreeimage.so:graphics/freeimage
TEST_DEPENDS=	ispc:devel/ispc

USES=		cmake:testing compiler:c++11-lang dos2unix

USE_GITHUB=	yes
GH_ACCOUNT=	akb825
GH_PROJECT=	Cuttlefish
GH_TUPLE=	akb825:freeimage:f213e48116964f273412dbd7337b03a32d52ec29:akb825_freeimage/lib/FreeImage \
		akb825:etc2comp:10ec1fc4987c5a81c48c6bf6319bb77389a5f23a:akb825_etc2comp/lib/etc2comp \
		ARM-software:astc-encoder:43d5f57babf0904f9e4222dc3644790d8e41aab4:ARM_software_astc_encoder/lib/astc-encoder \
		g-truc:glm:bf71a834948186f4097caa076cd2663c69a10e1e:g_truc_glm/lib/glm \
		akb825:PVRTexToolLib:ea50a1c0fb4d8eed2f06ecc47eea80ef291b63b9:akb825_PVRTexToolLib/lib/PVRTexToolLib \
		richgel999:bc7enc_rdo:e6990bc11829c072d9f9e37296f3335072aab4e4:richgel999_bc7enc_rdo/lib/bc7enc_rdo \
		GPUOpen-Tools:compressonator:bab59d4330e64612a1bb0c18dce0f70b48fef395:GPUOpen_Tools_compressonator/lib/compressonator \
		GameTechDev:ISPCTextureCompressor:cd0ef2cf78a80db293d7609100f027960f9e7205:GameTechDev_ISPCTextureCompressor/lib/ISPCTextureCompressor \
		akb825:libsquish:a9087786ced42a1a4ee137c1ad5bf197dd2d6b72:akb825_libsquish/lib/libsquish \
		google:googletest:703bd9caab50b139428cea1aaff9974ebee5742e:google_googletest/lib/astc-encoder/Source/GoogleTest

CMAKE_OFF=	CUTTLEFISH_BUILD_DOCS CUTTLEFISH_BUILD_TESTS
CMAKE_ON=	CUTTLEFISH_SHARED
CMAKE_TESTING_ON=	CUTTLEFISH_BUILD_TESTS

CXXFLAGS_powerpc=	-maltivec

.include <bsd.port.mk>
