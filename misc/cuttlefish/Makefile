PORTNAME=	cuttlefish
DISTVERSIONPREFIX=	v
DISTVERSION=	2.10.0
CATEGORIES=	misc
PKGNAMESUFFIX=	-texture-compressor

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Texture compression library and tool
WWW=		https://github.com/akb825/Cuttlefish

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_i386=	compilation fails: error: '__builtin_ia32_roundss' needs target feature sse4.1

LIB_DEPENDS=	libfreeimage.so:graphics/freeimage
TEST_DEPENDS=	ispc:devel/ispc

USES=		cmake:testing compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	akb825
GH_PROJECT=	Cuttlefish
GH_TUPLE=	akb825:etc2comp:10ec1fc4987c5a81c48c6bf6319bb77389a5f23a:akb825_etc2comp/lib/etc2comp \
		ARM-software:astc-encoder:30aabb3:ARM_software_astc_encoder/lib/astc-encoder \
		g-truc:glm:a532f5b:g_truc_glm/lib/glm \
		akb825:PVRTexToolLib:7fe2862:akb825_PVRTexToolLib/lib/PVRTexToolLib \
		richgel999:bc7enc_rdo:e6990bc11829c072d9f9e37296f3335072aab4e4:richgel999_bc7enc_rdo/lib/bc7enc_rdo \
		GPUOpen-Tools:compressonator:9da0bc2:GPUOpen_Tools_compressonator/lib/compressonator \
		GameTechDev:ISPCTextureCompressor:79ddbc9:GameTechDev_ISPCTextureCompressor/lib/ISPCTextureCompressor \
		akb825:libsquish:a9087786ced42a1a4ee137c1ad5bf197dd2d6b72:akb825_libsquish/lib/libsquish

CMAKE_OFF=	CUTTLEFISH_BUILD_DOCS CUTTLEFISH_BUILD_TESTS
CMAKE_ON=	CUTTLEFISH_SHARED
CMAKE_TESTING_ON=	CUTTLEFISH_BUILD_TESTS # many tests fail, see https://github.com/akb825/Cuttlefish/issues/19

CXXFLAGS_armv7=	-mfpu=neon-fp16
CXXFLAGS_powerpc=	-maltivec

# tests as of 2.10.0: 100% tests passed, 0 tests failed out of 96

.include <bsd.port.mk>
