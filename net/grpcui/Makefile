PORTNAME=	grpcui
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
PORTREVISION=	4
CATEGORIES=	net www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Interactive web UI for gRPC, along the lines of postman

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	fullstorydev
GH_SUBDIR=	src/github.com/fullstorydev/grpcui
GH_TUPLE=	\
		census-instrumentation:opencensus-proto:v0.2.1:census_instrumentation_opencensus_proto/vendor/github.com/census-instrumentation/opencensus-proto \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cncf:udpa:04548b0d99d4:cncf_udpa_go/vendor/github.com/cncf/udpa \
		cncf:xds:cb28da3451f1:cncf_xds_go/vendor/github.com/cncf/xds \
		envoyproxy:go-control-plane:cf90f659a021:envoyproxy_go_control_plane/vendor/github.com/envoyproxy/go-control-plane \
		envoyproxy:protoc-gen-validate:v0.1.0:envoyproxy_protoc_gen_validate/vendor/github.com/envoyproxy/protoc-gen-validate \
		fullstorydev:grpcurl:v1.8.6:fullstorydev_grpcurl/vendor/github.com/fullstorydev/grpcurl \
		golang:appengine:v1.6.5:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:75b288015ac9:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:c89045814202:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:c3d80250170d:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		google:go-genproto:cb27e3aa2013:google_go_genproto/vendor/google.golang.org/genproto \
		googleapis:google-cloud-go:v0.56.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		grpc:grpc-go:v1.44.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		jhump:protoreflect:c1d18a52a21d:jhump_protoreflect/vendor/github.com/jhump/protoreflect \
		pkg:browser:0a3d74bf9ce4:pkg_browser/vendor/github.com/pkg/browser \
		protocolbuffers:protobuf-go:v1.26.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
