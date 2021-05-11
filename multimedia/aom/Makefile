PORTNAME=	aom
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.0
CATEGORIES=	multimedia

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	86874609267d.patch:-p1 # https://bugs.chromium.org/p/aomedia/issues/detail?id=3050

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

OPTIONS_DEFINE=	VMAF

VMAF_DESC=		Encoding tuning for VMAF
VMAF_LIB_DEPENDS=	libvmaf.so:multimedia/vmaf
VMAF_USES=		localbase:ldflags pkgconfig
VMAF_CMAKE_ON=		-DCONFIG_TUNE_VMAF:STRING=1

post-patch:
# Extract (snapshot) version from the port instead of CHANGELOG
	@${REINPLACE_CMD} 's,$${AOM_ROOT}/CHANGELOG,${DISTVERSIONFULL:S/^v//},' \
		${WRKSRC}/build/cmake/version.cmake

.include <bsd.port.mk>
