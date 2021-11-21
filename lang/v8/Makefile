# We follow the stable channel on https://omahaproxy.appspot.com/
# https://chromium.googlesource.com/v8/v8/+/refs/heads/9.6-lkgr

PORTNAME=	v8
PORTVERSION=	9.6.180.12
CATEGORIES=	lang
MASTER_SITES=	LOCAL/sunpoet/v8/${PORTVERSION:R:R}
DISTFILES=	v8-${PORTVERSION}.tar.gz \
		build-${BUILD_REV}.tar.gz \
		buildtools-${BUILDTOOLS_REV}.tar.gz \
		clang-${CLANG_REV}.tar.gz \
		common-${COMMON_REV}.tar.gz \
		googletest-${GOOGLETEST_REV}.tar.gz \
		icu-${ICU_REV}.tar.gz \
		zlib-${ZLIB_REV}.tar.gz
EXTRACT_ONLY=	${DISTNAME}.tar.gz
DIST_SUBDIR=	v8/${PORTVERSION:R:R}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Open source JavaScript engine by Google

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	binutils>=0:devel/binutils \
		gn:devel/gn \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR}
LIB_DEPENDS=	libicudata.so:devel/icu

USES=		compiler:c++17-lang cpe gnome ninja pkgconfig python:3.5+,build tar:xz
USE_GNOME=	glib20

BINARY_ALIAS=	python3=${PYTHON_CMD}
MAKE_ARGS=	-C out/Release
NO_WRKSUBDIR=	yes
USE_LDCONFIG=	yes

SUB_FILES=	v8.pc v8_libbase.pc v8_libplatform.pc

#USE_GITHUB=	yes

CPE_VENDOR=	google

CONFLICTS_INSTALL=	v8-beta

BUILD_REV=	ebad8533842661f66b9b905e0ee9890a32f628d5
BUILDTOOLS_REV=	a9bc3e283182a586998338a665c7eae17406ec54
CLANG_REV=	c06edd1f455183fc89e9f8c2cf745db8f564d8ea
COMMON_REV=	68d816952258c9d817bba656ee2664b35507f01b
GOOGLETEST_REV=	3b49be074d5c1340eeb447e6a8e78427051e675a
ICU_REV=	3f443830bd52d3aa5fab3c1aa2b6d0848bb5039d
ZLIB_REV=	dfa96e81458fb3b39676e45f7e9e000dff789b05

# Run "gn args --list out/Release" for all variables.
# Some parts don't have use_system_* flag, and can be turned on/off by using
# replace_gn_files.py script, some parts just turned on/off for target host
# OS "target_os == is_bsd", like libusb, libpci.
GN_ARGS+=	clang_use_chrome_plugins=false \
		extra_cxxflags="${CXXFLAGS}" \
		extra_ldflags="${LDFLAGS}" \
		is_clang=true \
		treat_warnings_as_errors=false \
		use_aura=true \
		use_lld=true \
		use_custom_libcxx=false \
		v8_use_external_startup_data=false

post-extract:
	@${MKDIR} ${WRKSRC}/base/trace_event/common ${WRKSRC}/build ${WRKSRC}/buildtools ${WRKSRC}/third_party/googletest/src ${WRKSRC}/third_party/icu ${WRKSRC}/third_party/zlib ${WRKSRC}/tools/clang
	@${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/build-${BUILD_REV}.tar.gz -C ${WRKSRC}/build
	@${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/buildtools-${BUILDTOOLS_REV}.tar.gz -C ${WRKSRC}/buildtools
	@${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/clang-${CLANG_REV}.tar.gz -C ${WRKSRC}/tools/clang
	@${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/common-${COMMON_REV}.tar.gz -C ${WRKSRC}/base/trace_event/common
	@${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/googletest-${GOOGLETEST_REV}.tar.gz -C ${WRKSRC}/third_party/googletest/src
	@${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/icu-${ICU_REV}.tar.gz -C ${WRKSRC}/third_party/icu
	@${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/zlib-${ZLIB_REV}.tar.gz -C ${WRKSRC}/third_party/zlib

post-patch:
	@${REINPLACE_CMD} -i '' 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/build/toolchain/gcc_toolchain.gni ${WRKSRC}/buildtools/third_party/libc++/BUILD.gn
	# https://github.com/klzgrad/naiveproxy/blob/master/src/build/config/gclient_args.gni
	${ECHO_CMD} 'checkout_google_benchmark = false' > ${WRKSRC}/build/config/gclient_args.gni

# Use ICU from ports and create needed directory
pre-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${PYTHON_CMD} ./build/linux/unbundle/replace_gn_files.py --system-libraries icu # || ${FALSE}
	@${MKDIR} ${WRKSRC}/out/Release/gen/shim_headers/icui18n_shim/third_party/icu/source/i18n/unicode ${WRKSRC}/out/Release/gen/shim_headers/icuuc_shim/third_party/icu/source/common/unicode
	@${MKDIR} ${WRKSRC}/out/Release/gen/include
	@${CP} -R ${LOCALBASE}/include/unicode ${WRKSRC}/out/Release/gen/include/unicode

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} gn gen out/Release --args='${GN_ARGS}'

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/cppgc ${STAGEDIR}${PREFIX}/include/libplatform
	${INSTALL_PROGRAM} ${WRKSRC}/out/Release/d8 ${STAGEDIR}${PREFIX}/bin/d8
	${INSTALL_PROGRAM} ${WRKSRC}/out/Release/mkgrokdump ${STAGEDIR}${PREFIX}/bin/mkgrokdump
	${INSTALL_PROGRAM} ${WRKSRC}/out/Release/mksnapshot ${STAGEDIR}${PREFIX}/bin/mksnapshot
	${INSTALL_LIB} ${WRKSRC}/out/Release/libchrome_zlib.so ${STAGEDIR}${PREFIX}/lib/libchrome_zlib.so
	${INSTALL_LIB} ${WRKSRC}/out/Release/libcppgc.so ${STAGEDIR}${PREFIX}/lib/libcppgc.so
	${INSTALL_LIB} ${WRKSRC}/out/Release/libv8.so ${STAGEDIR}${PREFIX}/lib/libv8.so
	${INSTALL_LIB} ${WRKSRC}/out/Release/libv8_libbase.so ${STAGEDIR}${PREFIX}/lib/libv8_libbase.so
	${INSTALL_LIB} ${WRKSRC}/out/Release/libv8_libplatform.so ${STAGEDIR}${PREFIX}/lib/libv8_libplatform.so
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${STAGEDIR}${PREFIX}/include/
	cd ${WRKSRC}/include/cppgc && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/cppgc '-name *\.h'
	${INSTALL_DATA} ${WRKSRC}/include/libplatform/*.h ${STAGEDIR}${PREFIX}/include/libplatform/
	${INSTALL_DATA} ${WRKDIR}/v8*.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/

.include <bsd.port.mk>
