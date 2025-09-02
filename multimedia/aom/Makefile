PORTNAME=	aom
DISTVERSION=	3.13.0
CATEGORIES=	multimedia
MASTER_SITES=	https://storage.googleapis.com/${PORTNAME}-releases/
DISTNAME=	lib${PORTNAME}-${DISTVERSION}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	AV1 reference encoder/decoder
WWW=		https://aomedia.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${BUILD_DEPENDS_${ARCH}}
BUILD_DEPENDS_amd64=	nasm:devel/nasm
BUILD_DEPENDS_i386=	nasm:devel/nasm

USES=		cmake compiler:c++11-lib perl5
USE_PERL5=	build
USE_LDCONFIG=	yes
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	ENABLE_DOCS ENABLE_TESTS
PLIST_SUB=	VERSION=${PORTVERSION}

OPTIONS_DEFINE=	JXL VMAF
OPTIONS_DEFAULT=JXL VMAF
OPTIONS_EXCLUDE=JXL # https://bugs.chromium.org/p/aomedia/issues/detail?id=3457

JXL_DESC=		Encoding tuning for Butteraugli
JXL_LIB_DEPENDS=	libjxl.so:graphics/libjxl
JXL_USES=		pkgconfig
JXL_CMAKE_ON=		-DCONFIG_TUNE_BUTTERAUGLI:STRING=1

VMAF_DESC=		Encoding tuning for VMAF
VMAF_LIB_DEPENDS=	libvmaf.so:multimedia/vmaf
VMAF_USES=		pkgconfig
VMAF_CMAKE_ON=		-DCONFIG_TUNE_VMAF:STRING=1

post-patch:
# Extract (snapshot) version from the port instead of CHANGELOG
	@${REINPLACE_CMD} 's,$${AOM_ROOT}/CHANGELOG,${DISTVERSIONFULL:S/^v//},' \
		${WRKSRC}/build/cmake/version.cmake

.include <bsd.port.mk>
