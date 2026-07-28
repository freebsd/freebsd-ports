PORTNAME=	shaka-packager
DISTVERSIONPREFIX=	v
DISTVERSION=	3.9.3
CATEGORIES=	multimedia

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Media packaging SDK and tool for DASH and HLS
WWW=		https://github.com/shaka-project/shaka-packager

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/nlohmann/json.hpp:devel/nlohmann-json \
		${PYTHON_PKGNAMEPREFIX}protobuf>0:devel/py-protobuf@${PY_FLAVOR}
LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libcurl.so:ftp/curl \
		libmbedtls.so:security/mbedtls3 \
		libpng.so:graphics/png \
		libprotobuf.so:devel/protobuf \
		libwebm.so:multimedia/libwebm

USES=		cmake compiler:c++17-lang gnome pkgconfig python:build

USE_GITHUB=	yes
GH_ACCOUNT=	shaka-project

USE_GNOME=	libxml2

# Provide the version string explicitly; the build is from a tarball, so the
# git-based version detection would otherwise report "unknown-version".
CMAKE_ARGS=	-DPACKAGER_VERSION=${DISTVERSIONFULL}

# Link against the system libraries instead of the bundled copies, per the
# upstream USE_SYSTEM_DEPENDENCIES option.  Only the two command line tools are
# built (ALL_TARGET); the unit test suite (which needs a bundled mongoose and
# googletest) is skipped.  CMAKE_SKIP_INSTALL_ALL_DEPENDENCY keeps the staging
# step from rebuilding the full "all" target (and thus the tests).
CMAKE_ON=	USE_SYSTEM_DEPENDENCIES \
		CMAKE_SKIP_INSTALL_ALL_DEPENDENCY

ALL_TARGET=	mpd_generator packager

PLIST_FILES=	bin/mpd_generator \
		bin/packager

post-patch:
	@cd ${WRKSRC}/packager && ${GREP} -rlE 'absl::(Reader|Writer)?MutexLock' . | \
		${XARGS} ${REINPLACE_CMD} -E 's/(absl::(Reader|Writer)?MutexLock[[:space:]]+[[:alnum:]_]+\()([[:alnum:]_])/\1\&\3/g'
	${REINPLACE_CMD} -e 's|mutex->unlock()|mutex->Unlock()|' \
		${WRKSRC}/packager/file/threaded_io_file.cc

.include <bsd.port.mk>
