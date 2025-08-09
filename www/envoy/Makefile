PORTNAME=	envoy
PORTVERSION=	1.26.1
DISTVERSIONPREFIX=	v
PORTREVISION=	10
CATEGORIES=	www
MASTER_SITES=	https://storage.googleapis.com/quiche-envoy-integration/:gurl
DISTFILES=	dd4080fec0b443296c0ed0036e1e776df8813aa7${EXTRACT_SUFX}:gurl

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Edge and service proxy for cloud-native applications
WWW=		https://www.envoyproxy.io/

LICENSE=	APACHE20

BROKEN_SSL=	base openssl libressl libressl-devel
BROKEN_SSL_REASON=	requires BoringSSL

BUILD_DEPENDS=	${NONEXISTENT}:devel/grpc:patch \
		${NONEXISTENT}:devel/protobuf:patch \
		${LOCALBASE}/include/flatbuffers/reflection.h:devel/flatbuffers \
		${LOCALBASE}/include/nlohmann/json.hpp:devel/nlohmann-json \
		${LOCALBASE}/include/spdlog/spdlog.h:devel/spdlog \
		${LOCALBASE}/include/tclap/CmdLine.h:devel/tclap12
LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libbrotlidec.so:archivers/brotli \
		libcares.so:dns/c-ares \
		libcircllhist.so:devel/libcircllhist \
		libcurl.so:ftp/curl \
		libevent.so:devel/libevent-devel \
		libfmt.so:devel/libfmt \
		libgpr.so:devel/grpc \
		libicuuc.so:devel/icu \
		libnghttp2.so:www/libnghttp2 \
		libprotobuf.so:devel/protobuf \
		libre2.so:devel/re2 \
		libxxhash.so:devel/xxhash \
		libyaml-cpp.so:devel/yaml-cpp \
		libzstd.so:archivers/zstd

USES=		compiler:c++17-lang cpe gmake python:build shebangfix ssl
CPE_VENDOR=	${PORTNAME}proxy
SHEBANG_FILES=	examples/*/verify.sh examples/grpc-bridge/client/client.py \
		examples/shared/postgres/docker-healthcheck.sh
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}proxy bufbuild:pgv cncf:xds googleapis:gapis \
		census-instrumentation:ocp prometheus:pcm google:quiche \
		open-telemetry:otp google:cel
GH_PROJECT=	protoc-gen-validate:pgv xds:xds googleapis:gapis \
		opencensus-proto:ocp client_model:pcm quiche:quiche \
		opentelemetry-proto:otp cel-cpp:cel
GH_TAGNAME=	v0.10.1:pgv 46e39c7:xds 114a745:gapis v0.4.1:ocp 147c58e:pcm \
		37de4f7:quiche v0.19.0:otp 11f9d66:cel

_GRPC_WRKSRC=		${MAKE} -C ${PORTSDIR}/devel/grpc -V WRKSRC
_PROTOBUF_WRKSRC=	${MAKE} -C ${PORTSDIR}/devel/protobuf -V WRKSRC

PLIST_FILES=	bin/envoy
PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

post-extract:
	${LN} -s \
		 ../../client_model-147c58e/io \
		 ../../googleapis-114a745/google \
		 ../../opencensus-proto-0.4.1/src/opencensus \
		 ../../opentelemetry-proto-0.19.0/opentelemetry \
		 ../../protoc-gen-validate-0.10.1/validate \
		 ../../xds-46e39c7/udpa ../../xds-46e39c7/xds \
		 ${_GRPC_WRKSRC:sh}/src ${WRKSRC}/api

post-patch:
	@${REINPLACE_CMD} -e 's,__APPLE__,__${OPSYS}__,' \
		${WRKSRC}/source/common/network/address_impl.cc
	@${REINPLACE_CMD} -e 's,O_SYMLINK,O_NOFOLLOW,' \
		${WRKSRC}/source/common/filesystem/kqueue/watcher_impl.cc
	@${REINPLACE_CMD} -e '/opentracing::v/s,v2,v3,' \
		${WRKSRC}/source/extensions/tracers/common/ot/opentracing_driver_impl.cc
	@${REINPLACE_CMD} -e '23s,^,#include "absl/status/status.h",' \
		${WRKDIR}/cel-cpp-11f9d66/eval/public/ast_traverse.cc
	@${REINPLACE_CMD} -e '/^#include "eval\/testutil\/test_message/d' \
		${WRKDIR}/cel-cpp-11f9d66/eval/public/structs/cel_proto_wrap_util.cc

do-configure:
	${ECHO_CMD} '#define BUILD_VERSION_NUMBER "${PORTVERSION}"' \
		> ${WRKSRC}/source/common/version/version_number.h
	cd ${WRKSRC} && PYTHONPATH=. ${PYTHON_CMD} \
		tools/api_versioning/generate_api_version_header.py \
		API_VERSION.txt > \
		${WRKSRC}/source/common/version/api_version_number.h
	${LN} -s kqueue/watcher_impl.h posix/filesystem_impl.h \
		posix/directory_iterator_impl.h \
		${WRKSRC}/source/common/filesystem
	${LN} -s posix/os_sys_calls_impl.h ${WRKSRC}/source/common/api
	${LN} -s posix/signal_impl.h ${WRKSRC}/source/common/event
	${LN} -s posix/thread_impl.h ${WRKSRC}/source/common/common
	${LN} -s standard/logger_impl.h ${WRKSRC}/source/common/common
	${LN} -s ../../quiche-37de4f7/quiche ${WRKSRC}/source
	${LN} -s source/common/quic/platform ${WRKSRC}/quiche_platform_impl
	${LN} -s ${_PROTOBUF_WRKSRC:sh}/src/google ${WRKDIR}

do-build:
	${MAKE_CMD} -C ${WRKSRC} -f ${FILESDIR}/makefile-genproto
	${MAKE_CMD} ${_MAKE_JOBS} -C ${WRKSRC}/source \
		-f ${FILESDIR}/makefile-main all

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/source/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -a ${WRKSRC}/examples/ ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
