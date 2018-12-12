# $FreeBSD$

PORTNAME=	mod_pagespeed
PORTVERSION=	1.12.34.2
PORTREVISION=	17
PORTEPOCH=	1
CATEGORIES=	www devel
MASTER_SITES=	LOCAL/mmokhi:boringssl,chromium_base,chromium_build,googleurl,gflags_arch,gflags_src,libjpeg_turbo_src,yasm_patched,libwebp,modpb64 \
		https://dl.google.com/closure-compiler/:closurezip
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DISTFILES=	${NON_GH_DISTS}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	mmokhi@FreeBSD.org
COMMENT=	Apache module for rewriting web pages to reduce latency

LICENSE=	APACHE20

BUILD_DEPENDS=	bash:shells/bash \
		curl:ftp/curl \
		closure-compiler:www/closure-compiler \
		greadlink:sysutils/coreutils \
		gsed:textproc/gsed \
		gyp:devel/py-gyp@${PY_FLAVOR} \
		flock:sysutils/flock \
		${LOCALBASE}/include/apr-1/apr_pools.h:devel/apr1
LIB_DEPENDS=	libpng.so:graphics/png \
		libprotobuf.so:devel/protobuf \
		libgrpc.so:devel/grpc \
		libapr-1.so:devel/apr1 \
		libaprutil-1.so:devel/apr1 \
		libexpat.so:textproc/expat2 \
		libicutu.so:devel/icu \
		libopencv_video.so:graphics/opencv

USES=		apache:2.2+ compiler:c++14-lang gperf jpeg gmake localbase \
		pkgconfig python:2.7 shebangfix ssl tar:xz
SHEBANG_GLOB=	*.gyp *.gypi *.py *.sh
SHEBANG_FILES=	build/fix_proto_and_invoke_protoc

WRKSRC=		${WRKSRC_maindist}
DOCSDIR=	${PREFIX}/share/doc/apache${APACHE_VERSION}
CACHEDIR=	/var/cache/mod_pagespeed
LOGSDIR=	/var/log/pagespeed
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/apr-1 -I${WRKSRC} \
		-Wno-error -Wno-deprecated-register -Wno-char-subscripts \
		-frtti -fexceptions -fPIC
BUILDTYPE=	Release
MAKE_ENV+=	BUILDTYPE=${BUILDTYPE}
CLR_VERSION=	20161024
GYP_DEFINES+=	os_posix=1 \
		support_posix_shared_mem=1 \
		use_system_libs=1 \
		use_system_protobuf=1 \
		use_system_openssl=1 \
		use_system_apache_dev=1 \
		use_system_libjpeg=1 \
		use_system_libpng=1 \
		use_system_zlib=1 \
		use_system_icu=1 \
		use_system_yasm=1 \
		use_system_libxml=1 \
		use_system_sqlite=1 \
		use_system_opencv=1 \
		use_system_fontconfig=1 \
		target_arch=${ARCH} \
		system_include_path_apr=${LOCALBASE}/include/apr-1 \
		system_include_path_aprutil=${LOCALBASE}/include/apr-1 \
		system_include_path_httpd=${LOCALBASE}/include/apache24 \
		system_include_path_execinfo=${LOCALBASE}/include \
		system_include_path_icu=${LOCALBASE}/include \
		include_dirs=${LOCALBASE}/include \
		python_ver=${PYTHON_VER} \
		fastbuild=2
NON_GH_DISTS=	version_for_cocoapods_6.0-46-g07e78061.tar.gz:boringssl \
		ccf3c2f32.tar.gz:chromium_base \
		06b7bd9c.tar.gz:chromium_build \
		405b6e1.tar.gz:googleurl \
		gflags-master.tar.gz:gflags_arch \
		src-master.tar.gz:gflags_src \
		7260e4d.tar.gz:libjpeg_turbo_src \
		7da28c6.tar.gz:yasm_patched \
		v0.5.1.tar.gz:libwebp \
		aae6075.tar.gz:modpb64 \
		compiler-${CLR_VERSION}.zip:closurezip
WRKSRC_boringssl=	${WRKSRC}/third_party/boringssl/src
WRKSRC_chromium_base=	${WRKSRC}/third_party/chromium/src/base
WRKSRC_chromium_build=	${WRKSRC}/third_party/chromium/src/build
WRKSRC_googleurl=	${WRKSRC}/third_party/chromium/src/googleurl
WRKSRC_gflags_arch=	${WRKSRC}/third_party/gflags/arch
WRKSRC_gflags_src=	${WRKSRC}/third_party/gflags/src
WRKSRC_libjpeg_turbo_src=	${WRKSRC}/third_party/libjpeg_turbo/src
WRKSRC_yasm_patched=	${WRKSRC}/third_party/libjpeg_turbo/yasm/source/patched-yasm
WRKSRC_libwebp=		${WRKSRC}/third_party/libwebp
WRKSRC_modpb64=		${WRKSRC}/third_party/modp_b64
WRKSRC_closurezip=	${WRKSRC}/tools/closure

.for _group in ${_GITHUB_GROUPS:NDEFAULT}
EXTRACT_ONLY:=	${EXTRACT_ONLY} ${DISTFILE_${_group}}:${_group}
.endfor

#grpc changed from objective-c-v1.0.0-pre1-254-g2a69139aa7 to v1.6.0
USE_GITHUB=	nodefault
GH_ACCOUNT=	pagespeed
GH_TUPLE=	apache:incubator-pagespeed-mod:a5cfe15:maindist \
		google:googlemock:release-1.7.0:gmock/testing/gmock \
		google:googletest:release-1.7.0:gtest/testing/gtest \
		apache:apr:1.5.1:apr/third_party/apr/src \
		apache:apr-util:1.5.4:aprutil/third_party/aprutil/src \
		google:brotli:v0.4.0-89-g882f418:brotli/third_party/brotli/src \
		google:closure-library:v20161024:closurelib/third_party/closure_library \
		apache:incubator-pagespeed-drp:e9b72ea:domain_registry_provider/third_party/domain_registry_provider \
		pagespeed:giflib:99deb45:giflib/third_party/giflib \
		google:sparsehash:sparsehash-1.7:sparsehash/third_party/google-sparsehash/src \
		grpc:grpc:objective-c-v1.0.0-pre1-254-g2a69139aa7:grpc/third_party/grpc/src \
		redis:hiredis:v0.13.3:hiredis/third_party/hiredis/src \
		apache:httpd:2.2.29:httpd/third_party/httpd/src \
		apache:httpd:2.4.10:httpd24/third_party/httpd24/src \
		apache:incubator-pagespeed-icu:1b32282:icu/third_party/icu \
		open-source-parsers:jsoncpp:1.0.0:jsoncpp/third_party/jsoncpp/src \
		glennrp:libpng:libpng-1.2.56-signed:libpng/third_party/libpng/src \
		pagespeed:mod_fcgid:c63f176:mod__fcgid/third_party/mod_fcgid \
		nghttp2:nghttp2:v1.16.0-24-gf4474d57:nghttp2/third_party/nghttp2 \
		apache:incubator-pagespeed-optipng:e9a5bd6:optipng/third_party/optipng \
		google:protobuf:v3.0.0-beta-4-74-ge8ae137c:protobuf/third_party/protobuf/src \
		google:re2:2016-09-01:re2/third_party/re2/src \
		apache:serf:1.3.8:serf/third_party/serf/src \
		apache:incubator-pagespeed-zlib:1f93ffd:zlib/third_party/zlib \
		nanopb:nanopb:f8ac463:grpcnanopb/third_party/grpc/src/third_party/nanopb

post-extract:
.	for _D in ${NON_GH_DISTS}
	DGROUP=${_D:S/^${_D:C/:[^:]+$//}//:S/^://}
	DFILE=${_D:C/:[^-:][^:]*$//}
	${MKDIR} ${WRKSRC_${_D:S/^${_D:C/:[^:]+$//}//:S/^://}} && cd ${EXTRACT_WRKDIR} && \
	    ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DIST_SUBDIR}/${_D:C/:[^-:][^:]*$//} \
	    ${EXTRACT_AFTER_ARGS} -C ${WRKSRC_${_D:S/^${_D:C/:[^:]+$//}//:S/^://}}
.	endfor
	${CP} ${DISTDIR}/${DIST_SUBDIR}/compiler-${CLR_VERSION}.zip ${WRKSRC_closurezip}

post-patch:
	( cd ${BUILD_WRKSRC}/third_party/google-sparsehash/gen/arch && \
	    ${CP} -R linux freebsd && \
	    cd ${BUILD_WRKSRC}/third_party/google-sparsehash/gen/arch/freebsd && \
	    ${MV} ia32 i386 && ${MV} x64 amd64 )
	${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE},g" \
	    ${WRKSRC}/base/base.gypi ${WRKSRC}/third_party/serf/select_openssl.gyp
	${REINPLACE_CMD} -e "s,%%PORTSSTAGE%%,${STAGEDIR},g" \
	    ${WRKSRC}/install/Makefile
	${FIND} ${WRKSRC} -type f \( -name "*.gyp" -o -name "*.gypi" \) -exec \
	    ${REINPLACE_CMD} -e "s/'python'/'${PYTHON_VERSION}'/g" {} \;

do-configure:
	cd ${WRKSRC} && \
	    GYP_DEFINES="${GYP_DEFINES}" CC=${CC} CXX=${CXX} \
	    ${PYTHON_CMD} build/gyp_chromium --depth=.

do-build:
	cd ${WRKSRC} && \
	${GMAKE} ${MAKE_ENV} builddir=${WRKSRC}/${BUILDTYPE} \
	    CFLAGS_${BUILDTYPE}="${CFLAGS}" CXXFLAGS_${BUILDTYPE}="${CFLAGS}" \
	    AR.host=/usr/bin/ar AR.target=/usr/bin/ar CC.host=${CC} CC.target=${CC} \
	    CXX.host=${CXX} CXX.target=${CXX} BUILDTYPE=${BUILDTYPE}

do-install:
	cd ${WRKSRC}/install && ${MKDIR} FreeBSD && \
	echo ' \
	APACHE_ROOT=${PREFIX} \
	APACHE_MODULES=${PREFIX}/${APACHEMODDIR} \
	APACHE_CONF_DIR=${PREFIX}/${APACHEETCDIR} \
	APACHE_DOC_ROOT=${DOCSDIR} \
	APACHE_CONTROL_PROGRAM=${HTTPD} \
	APACHE_PROGRAM=apache${APACHE_VERSION} \
	APACHE_START="service apache24 start" \
	APACHE_PIDFILE="/var/run/httpd.pid" \
	APACHE_USER=www \
	DISTRO_NAME=FreeBSD' > FreeBSD/make_vars.mk && \
	${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR} && \
	${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEETCDIR} && \
	${MKDIR} ${STAGEDIR}${DOCSDIR} && \
	${GMAKE} ${MAKE_ENV} V=1 builddir=${WRKSRC}/${BUILDTYPE} \
	    CFLAGS_${BUILDTYPE}="${CFLAGS}" CXXFLAGS_${BUILDTYPE}="${CFLAGS}" \
	    AR.host=/usr/bin/ar AR.target=/usr/bin/ar CC.host=${CC} CC.target=${CC} \
	    CXX.host=${CXX} CXX.target=${CXX} BUILDTYPE=${BUILDTYPE} \
	    APACHE_ROOT=${PREFIX} BINDIR=${PREFIX}/bin \
	    APACHE_MODULES=${PREFIX}/${APACHEMODDIR} \
	    APACHE_CONF_DIR=${PREFIX}/${APACHEETCDIR} \
	    APACHE_DOC_ROOT=${DOCSDIR} \
	    APACHE_CONTROL_PROGRAM=${HTTPD} APACHE_PROGRAM=apache${APACHE_VERSION} \
	    APACHE_START="service apache24 start" APACHE_PIDFILE="/var/run/httpd.pid" \
	    APACHE_USER=www DISTRO_NAME=FreeBSD MOD_PAGESPEED_ROOT=${WRKSRC} \
	    PAGESPEED_MODULE=${WRKSRC}/Release/libmod_pagespeed.so \
	    PAGESPEED_MODULE_24=${WRKSRC}/Release/libmod_pagespeed_ap24.so \
	    PAGESPEED_JS_MINIFY=${WRKSRC}/Release/js_minify \
	    MOD_PAGESPEED_CACHE=${CACHEDIR} \
	    MOD_PAGESPEED_LOG=${LOGSDIR} staging install
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/*

.include <bsd.port.mk>
