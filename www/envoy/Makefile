# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	envoy
PORTVERSION=	1.10.0
DISTVERSIONPREFIX=	v
PORTREVISION=	8
CATEGORIES=	www

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Edge and service proxy for cloud-native applications

LICENSE=	APACHE20

BROKEN_i386=	makes a lot of 64-bit assumptions (patches welcome)
BROKEN_SSL=	base openssl libressl libressl-devel
BROKEN_SSL_REASON=	requires BoringSSL

BUILD_DEPENDS=	${LOCALBASE}/include/absl/base/thread_annotations.h:devel/abseil \
		${LOCALBASE}/include/fmt/format.h:devel/libfmt \
		${LOCALBASE}/include/rapidjson/document.h:devel/rapidjson \
		${LOCALBASE}/include/spdlog/spdlog.h:devel/spdlog \
		${LOCALBASE}/include/tclap/CmdLine.h:devel/tclap
LIB_DEPENDS=	libcircllhist.so:devel/libcircllhist \
		libevent.so:devel/libevent \
		libfmt.so:devel/libfmt \
		libgpr.so:devel/grpc \
		libprotobuf.so:devel/protobuf \
		libxxhash.so:devel/xxhash \
		libyaml-cpp.so:devel/yaml-cpp \
		libcares.so:dns/c-ares \
		libhttp_parser.so:www/http-parser \
		libnghttp2.so:www/libnghttp2

USES=		compiler:c++14-lang gmake ssl
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}proxy gogo:protobuf googleapis:gapis \
		prometheus:pm grpc:grpc
GH_PROJECT=	protoc-gen-validate:validate protobuf:protobuf \
		googleapis:gapis client_model:pm grpc:grpc
GH_TAGNAME=	v0.1.0:validate v1.1.1:protobuf b4c73fa:gapis \
		fd36f42:pm v1.22.0:grpc

PLIST_FILES=	bin/envoy
PORTEXAMPLES=	cors/backend/front-envoy.yaml \
		cors/backend/service-envoy.yaml \
		cors/frontend/front-envoy.yaml \
		cors/frontend/service-envoy.yaml \
		front-proxy/front-envoy.yaml \
		front-proxy/service-envoy.yaml \
		grpc-bridge/config/s2s-grpc-envoy.yaml \
		grpc-bridge/config/s2s-python-envoy.yaml \
		jaeger-tracing/front-envoy-jaeger.yaml \
		jaeger-tracing/service1-envoy-jaeger.yaml \
		jaeger-tracing/service2-envoy-jaeger.yaml \
		lua/envoy.yaml \
		zipkin-tracing/front-envoy-zipkin.yaml \
		zipkin-tracing/service1-envoy-zipkin.yaml \
		zipkin-tracing/service2-envoy-zipkin.yaml

OPTIONS_DEFINE=	EXAMPLES

post-extract:
	${LN} -s ../../client_model-fd36f42/metrics.proto \
		 ../../googleapis-b4c73fa/google \
		 ../../grpc-1.22.0/src \
		 ../../protobuf-1.1.1/gogoproto \
		 ../../protoc-gen-validate-0.1.0/validate ${WRKSRC}/api

post-patch:
	@${REINPLACE_CMD} -e '/<endian\.h>/d' \
		${WRKSRC}/source/common/common/byte_order.h
	@${REINPLACE_CMD} -e 's,__APPLE__,__${OPSYS}__,' \
		${WRKSRC}/source/common/network/address_impl.cc \
		${WRKSRC}/source/common/network/udp_listener_impl.cc
	@${REINPLACE_CMD} -e 's,O_SYMLINK,O_NOFOLLOW,' \
		${WRKSRC}/source/common/filesystem/kqueue/watcher_impl.cc
	@${REINPLACE_CMD} -e '/#include/s,\.validate,,' \
		${WRKSRC}/source/extensions/access_loggers/file/config.cc \
		${WRKSRC}/source/server/overload_manager_impl.h

do-configure:
	${ECHO_CMD} '#define BUILD_VERSION_NUMBER "${PORTVERSION}"' \
		> ${WRKSRC}/source/common/common/version_number.h
	${LN} -s kqueue/watcher_impl.h posix/filesystem_impl.h \
		posix/directory_iterator_impl.h \
		${WRKSRC}/source/common/filesystem
	${LN} -s posix/platform_impl.h ${WRKSRC}/source/exe
	${LN} -s posix/thread_impl.h ${WRKSRC}/source/common/common

do-build:
	${MAKE_CMD} -C ${WRKSRC}/api -f ${FILESDIR}/makefile-genproto
	${MAKE_CMD} ${_MAKE_JOBS} -C ${WRKSRC}/source \
		-f ${FILESDIR}/makefile-main

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/source/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${TAR} -cf - -C ${WRKSRC}/examples ${PORTEXAMPLES} | \
		${TAR} -xf - -C ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
