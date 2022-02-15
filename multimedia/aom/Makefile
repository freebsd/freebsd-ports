PORTNAME=	aom
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.0
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	AV1 reference encoder/decoder

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${BUILD_DEPENDS_${ARCH}}
BUILD_DEPENDS_amd64=	nasm:devel/nasm
BUILD_DEPENDS_i386=	nasm:devel/nasm

USES=		cmake compiler:c++11-lib perl5
USE_GITHUB=	yes
USE_PERL5=	build
USE_LDCONFIG=	yes
GH_ACCOUNT=	jbeich # mirror
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	ENABLE_DOCS ENABLE_TESTS

OPTIONS_DEFINE=	JXL VMAF
OPTIONS_DEFAULT=VMAF

JXL_DESC=		Encoding tuning for Butteraugli
JXL_LIB_DEPENDS=	libjxl.so:graphics/libjxl
JXL_USES=		pkgconfig
JXL_CMAKE_ON=		-DCONFIG_TUNE_BUTTERAUGLI:STRING=1
JXL_BROKEN=		fails to build after \
			https://aomedia.googlesource.com/aom/+/dba4f0f3efda%5E!/ \
			https://aomedia.googlesource.com/aom/+/b89e8f8f7a2c%5E!/

VMAF_DESC=		Encoding tuning for VMAF
VMAF_LIB_DEPENDS=	libvmaf.so:multimedia/vmaf
VMAF_USES=		pkgconfig
VMAF_CMAKE_ON=		-DCONFIG_TUNE_VMAF:STRING=1

post-patch:
# Extract (snapshot) version from the port instead of CHANGELOG
	@${REINPLACE_CMD} 's,$${AOM_ROOT}/CHANGELOG,${DISTVERSIONFULL:S/^v//},' \
		${WRKSRC}/build/cmake/version.cmake

.include <bsd.port.mk>
