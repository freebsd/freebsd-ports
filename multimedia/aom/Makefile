# $FreeBSD$

PORTNAME=	aom
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0-2558
DISTVERSIONSUFFIX=	-g25daf5d22
CATEGORIES=	multimedia

# XXX Drop revert of revert when ABI changes again
# https://aomedia-review.googlesource.com/c/aom/+/96983
PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	a70e67a5fd6a.patch:-p1

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

post-patch:
# Extract (snapshot) version from the port instead of CHANGELOG
	@${REINPLACE_CMD} 's,$${AOM_ROOT}/CHANGELOG,${DISTVERSIONFULL:S/^v//},' \
		${WRKSRC}/build/cmake/version.cmake

.include <bsd.port.mk>
