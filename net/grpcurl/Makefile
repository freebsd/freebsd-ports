PORTNAME=	grpcurl
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.3
PORTREVISION=	4
CATEGORIES=	net

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Command-line tool that lets you interact with gRPC servers
WWW=		https://github.com/fullstorydev/grpcurl

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	fullstorydev
GH_SUBDIR=	src/github.com/fullstorydev/grpcurl

GH_TUPLE=	\
		bufbuild:protocompile:v0.10.0:bufbuild_protocompile/vendor/github.com/bufbuild/protocompile \
		census-instrumentation:opencensus-proto:v0.4.1:census_instrumentation_opencensus_proto/vendor/github.com/census-instrumentation/opencensus-proto \
		cespare:xxhash:v2.2.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cncf:udpa:c52dc94e7fbe:cncf_udpa_go/vendor/github.com/cncf/udpa \
		cncf:xds:523115ebc101:cncf_xds_go/vendor/github.com/cncf/xds \
		envoyproxy:go-control-plane:v0.11.1:envoyproxy_go_control_plane/vendor/github.com/envoyproxy/go-control-plane \
		envoyproxy:protoc-gen-validate:v1.0.2:envoyproxy_protoc_gen_validate/vendor/github.com/envoyproxy/protoc-gen-validate \
		golang:appengine:v1.6.8:golang_appengine/vendor/google.golang.org/appengine \
		golang:net:v0.22.0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:v0.14.0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.4:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:v0.6.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.18.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.14.0:golang_text/vendor/golang.org/x/text \
		google:go-genproto:bbf56f31fb17:google_go_genproto/vendor/google.golang.org/genproto \
		googleapis:google-cloud-go:compute/v1.23.3:googleapis_google_cloud_go_compute/vendor/cloud.google.com/go \
		grpc:grpc-go:v1.61.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		jhump:protoreflect:v1.16.0:jhump_protoreflect/vendor/github.com/jhump/protoreflect \
		protocolbuffers:protobuf-go:98873a205002:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf

GO_BUILDFLAGS=	-ldflags "-X main.version=${DISTVERSIONPREFIX}${PORTVERSION} -s -w"
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/grpcurl

.include <bsd.port.mk>
