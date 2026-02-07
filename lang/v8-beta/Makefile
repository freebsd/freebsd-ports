# We follow the beta channel on https://omahaproxy.appspot.com/
# https://chromium.googlesource.com/v8/v8/+/refs/heads/10.4-lkgr

PORTNAME=	v8
PORTVERSION=	10.4.132.20
PORTREVISION=	4
CATEGORIES=	lang
MASTER_SITES=	LOCAL/sunpoet/v8/${PORTVERSION:R:R}:local
PKGNAMESUFFIX=	-beta
DISTFILES=	build-${BUILD_REV}.tar.gz:local \
		buildtools-${BUILDTOOLS_REV}.tar.gz:local \
		clang-${CLANG_REV}.tar.gz:local \
		common-${COMMON_REV}.tar.gz:local \
		googletest-${GOOGLETEST_REV}.tar.gz:local \
		icu-${ICU_REV}.tar.gz:local \
		zlib-${ZLIB_REV}.tar.gz:local
DIST_SUBDIR=	v8/${PORTVERSION:R:R}
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source JavaScript engine by Google
WWW=		https://v8.dev/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 i386

BUILD_DEPENDS=	binutils>=0:devel/binutils \
		gn:devel/gn \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR}
LIB_DEPENDS=	libicudata.so:devel/icu

USES=		compiler:c++17-lang cpe gnome ninja pkgconfig python:build tar:xz
USE_GNOME=	glib20

BINARY_ALIAS=	python3=${PYTHON_CMD}
MAKE_ARGS=	-C out/Release
USE_LDCONFIG=	yes

SUB_FILES=	v8.pc v8_libbase.pc v8_libplatform.pc

USE_GITHUB=	yes

CPE_VENDOR=	google

CONFLICTS_INSTALL=	v8

BUILD_REV=	a56852668f892151fc97343b57af15e82db2e798
BUILDTOOLS_REV=	8b16338d17cd71b04a6ba28da7322ab6739892c2
CLANG_REV=	4e79fda976d9c3f12c8bfbec297bd27dd70a1343
COMMON_REV=	d115b033c4e53666b535cbd1985ffe60badad082
GOOGLETEST_REV=	af29db7ec28d6df1c7f0f745186884091e602e07
ICU_REV=	165825933050109d8331d0faa56cc9f52460fbbf
ZLIB_REV=	64bbf988543996eb8df9a86877b32917187eba8f

# Run "gn args --list out/Release" for all variables.
# Some parts don't have use_system_* flag, and can be turned on/off by using
# replace_gn_files.py script, some parts just turned on/off for target host
# OS "target_os == is_bsd", like libusb, libpci.
GN_ARGS+=	clang_use_chrome_plugins=false \
		extra_cxxflags="${CXXFLAGS}" \
		extra_ldflags="${LDFLAGS}" \
		is_clang=true \
		is_component_build=true \
		is_debug=false \
		treat_warnings_as_errors=false \
		use_aura=true \
		use_lld=true \
		use_custom_libcxx=false \
		v8_use_external_startup_data=false

OPTIONS_DEFINE=	EXAMPLES

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
	@${ECHO_CMD} 'checkout_google_benchmark = false' > ${WRKSRC}/build/config/gclient_args.gni

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
	${INSTALL_PROGRAM} ${WRKSRC}/out/Release/v8_shell ${STAGEDIR}${PREFIX}/bin/v8_shell
	${INSTALL_LIB} ${WRKSRC}/out/Release/libchrome_zlib.so ${STAGEDIR}${PREFIX}/lib/libchrome_zlib.so
	${INSTALL_LIB} ${WRKSRC}/out/Release/libcppgc.so ${STAGEDIR}${PREFIX}/lib/libcppgc.so
	${INSTALL_LIB} ${WRKSRC}/out/Release/libv8.so ${STAGEDIR}${PREFIX}/lib/libv8.so
	${INSTALL_LIB} ${WRKSRC}/out/Release/libv8_libbase.so ${STAGEDIR}${PREFIX}/lib/libv8_libbase.so
	${INSTALL_LIB} ${WRKSRC}/out/Release/libv8_libplatform.so ${STAGEDIR}${PREFIX}/lib/libv8_libplatform.so
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${STAGEDIR}${PREFIX}/include/
	cd ${WRKSRC}/include/cppgc && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/cppgc '-name *\.h'
	${INSTALL_DATA} ${WRKSRC}/include/libplatform/*.h ${STAGEDIR}${PREFIX}/include/libplatform/
	${INSTALL_DATA} ${WRKDIR}/v8*.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/out/Release/v8_simple_* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
