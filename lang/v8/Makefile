# To update the port:
# The stable v8 version follows the chromium browser
# https://chromereleases.googleblog.com/search/label/Desktop%20Update
# search for "The stable channel has been updated to" XX.X.XXXX.XXX
#  -> https://github.com/chromium/chromium/blob/87.0.4280.60/DEPS
#     -> 'v8_revision': 'd2fef9fb0ac356d6cf6759f29e2b56ebea8bc58d'
# https://github.com/v8/v8/commit/d2fef9fb0ac356d6cf6759f29e2b56ebea8bc58d
#  -> Version  8.7.220.23
# then:
#  - make makesum
#  - update the various hashes (BUILD_HASH...), see below:
#    egrep "build.git|buildtools.git|clang.git|common.git|googletest.git|icu.git|zlib.git" ${WRKSRC}/DEPS
#  - make MAINTAINER_MODE=yes fetch (warning, it'll try to upload them on my account on freefall)
#  - make makesum (to update the various deps hashes)
#  - make clean ; make (and fix the patches if needed)

PORTNAME=	v8
DISTVERSION=	8.7.220.23
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	LOCAL/mikael/v8/:build \
		LOCAL/mikael/v8/:buildtools \
		LOCAL/mikael/v8/:clang \
		LOCAL/mikael/v8/:common \
		LOCAL/mikael/v8/:googletest \
		LOCAL/mikael/v8/:icu \
		LOCAL/mikael/v8/:zlib
DISTFILES=	build-${BUILD_HASH}.tar.gz:build \
		buildtools-${BUILDTOOLS_HASH}.tar.gz:buildtools \
		clang-${CLANG_HASH}.tar.gz:clang \
		common-${COMMON_HASH}.tar.gz:common \
		googletest-${GOOGLETEST_HASH}.tar.gz:googletest \
		icu-${ICU_HASH}.tar.gz:icu \
		zlib-${ZLIB_HASH}.tar.gz:zlib
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Open source JavaScript engine by Google

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	binutils>0:devel/binutils \
		gn:devel/gn \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		libunwind>0:devel/libunwind
LIB_DEPENDS=	libicudata.so:devel/icu

USES=		gnome ninja pkgconfig python:3.5+,build tar:xz
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_GNOME=	glib20

# new release every minutes
PORTSCOUT=	ignore:1

# egrep "build.git|buildtools.git|clang.git|common.git|googletest.git|icu.git|zlib.git" ${WRKSRC}/DEPS
BUILD_HASH=	38a49c12ded01dd8c4628b432cb7eebfb29e77f1
BUILDTOOLS_HASH=		3ff4f5027b4b81a6c9c36d64d71444f2709a4896
CLANG_HASH=	3017edade60658a699be776d9e282509a902ffe9
COMMON_HASH=	23ef5333a357fc7314630ef88b44c3a545881dee
GOOGLETEST_HASH=	4fe018038f87675c083d0cfb6a6b57c274fb1753
ICU_HASH=	aef20f06d47ba76fdf13abcdb033e2a408b5a94d
ZLIB_HASH=	4668feaaa47973a6f9d9f9caeb14cd03731854f1

BUILDTYPE=	Release

BINARY_ALIAS=	python=${PYTHON_CMD}

# Run "gn args out/Release --list" for all variables.
# Some parts don't have use_system_* flag, and can be turned on/off by using
# replace_gn_files.py script, some parts just turned on/off for target host
# OS "target_os == is_bsd", like libusb, libpci.
GN_ARGS+=	clang_use_chrome_plugins=false \
		is_clang=true \
		treat_warnings_as_errors=false \
		use_aura=true \
		use_lld=true \
		use_custom_libcxx=false \
		v8_use_external_startup_data=false \
		extra_cxxflags="${CXXFLAGS}" \
		extra_ldflags="${LDFLAGS}"

MAKE_ARGS=	-C out/${BUILDTYPE}

# sha256 changes everytime you download the archive, need to host them on
# freefall
# To download distfiles : as sunpoet: make MAINTAINER_MODE=yes fetch
.if defined(MAINTAINER_MODE)
do-fetch:
	${FETCH_CMD} -o ${DISTDIR}/build-${BUILD_HASH}.tar.gz \
		https://chromium.googlesource.com/chromium/src/build.git/+archive/${BUILD_HASH}.tar.gz
	${FETCH_CMD} -o ${DISTDIR}/buildtools-${BUILDTOOLS_HASH}.tar.gz \
		https://chromium.googlesource.com/chromium/src/buildtools.git/+archive/${BUILDTOOLS_HASH}.tar.gz
	${FETCH_CMD} -o ${DISTDIR}/clang-${CLANG_HASH}.tar.gz \
		https://chromium.googlesource.com/chromium/src/tools/clang.git/+archive/${CLANG_HASH}.tar.gz
	${FETCH_CMD} -o ${DISTDIR}/common-${COMMON_HASH}.tar.gz \
		https://chromium.googlesource.com/chromium/src/base/trace_event/common.git/+archive/${COMMON_HASH}.tar.gz
	${FETCH_CMD} -o ${DISTDIR}/googletest-${GOOGLETEST_HASH}.tar.gz \
		https://chromium.googlesource.com/external/github.com/google/googletest.git/+archive/${GOOGLETEST_HASH}.tar.gz
	${FETCH_CMD} -o ${DISTDIR}/icu-${ICU_HASH}.tar.gz \
		https://chromium.googlesource.com/chromium/deps/icu.git/+archive/${ICU_HASH}.tar.gz
	${FETCH_CMD} -o ${DISTDIR}/zlib-${ZLIB_HASH}.tar.gz \
		https://chromium.googlesource.com/chromium/src/third_party/zlib.git/+archive/${ZLIB_HASH}.tar.gz

. if ${USER} == ${MAINTAINER:C/@.*//}
.  for f in build-${BUILD_HASH} buildtools-${BUILDTOOLS_HASH} \
		clang-${CLANG_HASH} common-${COMMON_HASH} \
		googletest-${GOOGLETEST_HASH} icu-${ICU_HASH} \
		zlib-${ZLIB_HASH}
	scp ${DISTDIR}/${f}.tar.gz \
	    sunpoet@freefall.freebsd.org:public_distfiles/v8
.  endfor
. endif
.endif # defined(MAINTAINER_MODE)

post-extract:
	${MKDIR} \
		${WRKSRC}/base/trace_event/common \
		${WRKSRC}/build \
		${WRKSRC}/buildtools \
		${WRKSRC}/third_party/googletest/src \
		${WRKSRC}/third_party/icu \
		${WRKSRC}/third_party/zlib \
		${WRKSRC}/tools/clang
	${TAR} -xf ${DISTDIR}/build-${BUILD_HASH}.tar.gz  -C ${WRKSRC}/build
	${TAR} -xf ${DISTDIR}/buildtools-${BUILDTOOLS_HASH}.tar.gz  -C ${WRKSRC}/buildtools
	${TAR} -xf ${DISTDIR}/clang-${CLANG_HASH}.tar.gz  -C ${WRKSRC}/tools/clang
	${TAR} -xf ${DISTDIR}/common-${COMMON_HASH}.tar.gz  -C ${WRKSRC}/base/trace_event/common
	${TAR} -xf ${DISTDIR}/googletest-${GOOGLETEST_HASH}.tar.gz  -C ${WRKSRC}/third_party/googletest/src
	${TAR} -xf ${DISTDIR}/icu-${ICU_HASH}.tar.gz -C ${WRKSRC}/third_party/icu
	${TAR} -xf ${DISTDIR}/zlib-${ZLIB_HASH}.tar.gz -C ${WRKSRC}/third_party/zlib

post-patch:
	${REINPLACE_CMD} "s|%%LOCALBASE%%|${LOCALBASE}|" \
		${WRKSRC}/build/toolchain/gcc_toolchain.gni \
		${WRKSRC}/buildtools/third_party/libc++/BUILD.gn

# google sucks, this file is needed but absent in the build* archive
# https://github.com/klzgrad/naiveproxy/blob/master/src/build/config/gclient_args.gni
	${TOUCH} ${WRKSRC}/build/config/gclient_args.gni
	${ECHO} "checkout_google_benchmark = false" >> ${WRKSRC}/build/config/gclient_args.gni

pre-configure:
	# use system libraries for ICU
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${PYTHON_CMD} \
		./build/linux/unbundle/replace_gn_files.py --system-libraries \
		icu || ${FALSE}
	# google build system is too stupid to create needed directory and
	# use system headers for ICU
	${MKDIR} ${WRKSRC}/out/${BUILDTYPE}/gen/shim_headers/icuuc_shim/third_party/icu/source/common/unicode \
		 ${WRKSRC}/out/${BUILDTYPE}/gen/shim_headers/icui18n_shim/third_party/icu/source/i18n/unicode \
		 ${WRKSRC}/out/${BUILDTYPE}/gen/include
	${CP} -R ${LOCALBASE}/include/unicode ${WRKSRC}/out/${BUILDTYPE}/gen/include

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} gn gen out/${BUILDTYPE} --args='${GN_ARGS}'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out/${BUILDTYPE}/d8 ${STAGEDIR}${PREFIX}/bin/d8
#	${INSTALL_PROGRAM} ${WRKSRC}/out/${BUILDTYPE}/d8 ${STAGEDIR}${PREFIX}/bin/cctest
#	${INSTALL_PROGRAM} ${WRKSRC}/out/${BUILDTYPE}/mksnapshot ${STAGEDIR}${PREFIX}/bin/mksnapshot
#	${INSTALL_PROGRAM} ${WRKSRC}/out/${BUILDTYPE}/mkgrokdump ${STAGEDIR}${PREFIX}/bin/mkgrokdump
	${INSTALL_LIB} ${WRKSRC}/out/${BUILDTYPE}/libv8.so ${STAGEDIR}${PREFIX}/lib/libv8.so
	${INSTALL_LIB} ${WRKSRC}/out/${BUILDTYPE}/libv8_libbase.so ${STAGEDIR}${PREFIX}/lib/libv8_libbase.so
	${INSTALL_LIB} ${WRKSRC}/out/${BUILDTYPE}/libv8_libplatform.so ${STAGEDIR}${PREFIX}/lib/libv8_libplatform.so
	${INSTALL_LIB} ${WRKSRC}/out/${BUILDTYPE}/libchrome_zlib.so ${STAGEDIR}${PREFIX}/lib/libchrome_zlib.so

	${INSTALL_DATA} ${WRKSRC}/include/*.h ${STAGEDIR}${PREFIX}/include/
	${MKDIR} ${STAGEDIR}${PREFIX}/include/libplatform \
	         ${STAGEDIR}${PREFIX}/include/cppgc
	${INSTALL_DATA} ${WRKSRC}/include/libplatform/*.h ${STAGEDIR}${PREFIX}/include/libplatform/
	cd ${WRKSRC}/include/cppgc && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/cppgc " -name *\.h"
	${INSTALL_DATA} ${FILESDIR}/*.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig
	${REINPLACE_CMD} "s|%%PREFIX%%|${PREFIX}|" \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/*

.include <bsd.port.mk>
