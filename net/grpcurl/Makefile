PORTNAME=	grpcurl
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.7
PORTREVISION=	11
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
		census-instrumentation:opencensus-proto:v0.2.1:census_instrumentation_opencensus_proto/vendor/github.com/census-instrumentation/opencensus-proto \
		cncf:udpa:5459f2c99403:cncf_udpa_go/vendor/github.com/cncf/udpa \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		envoyproxy:go-control-plane:668b12f5399d:envoyproxy_go_control_plane/vendor/github.com/envoyproxy/go-control-plane \
		envoyproxy:protoc-gen-validate:v0.1.0:envoyproxy_protoc_gen_validate/vendor/github.com/envoyproxy/protoc-gen-validate \
		go-check:check:41f04d3bba15:go_check_check/vendor/gopkg.in/check.v1 \
		go-yaml:yaml:v2.2.8:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:appengine:v1.6.5:golang_appengine/vendor/google.golang.org/appengine \
		golang:net:4c5254603344:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:c3d80250170d:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:xerrors:9bdfabe68543:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:v0.5.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:cb27e3aa2013:google_go_genproto/vendor/google.golang.org/genproto \
		google:uuid:v1.1.2:google_uuid/vendor/github.com/google/uuid \
		googleapis:google-cloud-go:v0.56.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		grpc:grpc-go:v1.37.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		jhump:protoreflect:v1.10.1:jhump_protoreflect/vendor/github.com/jhump/protoreflect \
		protocolbuffers:protobuf-go:a709e31e5d12:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf

GO_BUILDFLAGS=	-ldflags "-X main.version=${DISTVERSIONPREFIX}${PORTVERSION} -s -w"
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/grpcurl

.include <bsd.port.mk>
