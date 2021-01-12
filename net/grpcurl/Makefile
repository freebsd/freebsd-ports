# $FreeBSD$

PORTNAME=	grpcurl
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.0
CATEGORIES=	net

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Command-line tool that lets you interact with gRPC servers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	fullstorydev
GH_SUBDIR=	src/github.com/fullstorydev/grpcurl
GH_TUPLE=	\
		cncf:udpa:269d4d468f6f:cncf_udpa_go/vendor/github.com/cncf/udpa \
		envoyproxy:go-control-plane:v0.9.4:envoyproxy_go_control_plane/vendor/github.com/envoyproxy/go-control-plane \
		envoyproxy:protoc-gen-validate:v0.1.0:envoyproxy_protoc_gen_validate/vendor/github.com/envoyproxy/protoc-gen-validate \
		golang:appengine:v1.6.5:golang_appengine/vendor/google.golang.org/appengine \
		golang:net:d3edc9973b7e:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.5:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:c3d80250170d:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		google:go-cmp:v0.4.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:1ee6d9798940:google_go_genproto/vendor/google.golang.org/genproto \
		googleapis:google-cloud-go:v0.56.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		grpc:grpc-go:v1.30.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		jhump:protoreflect:v1.6.1:jhump_protoreflect/vendor/github.com/jhump/protoreflect

GO_BUILDFLAGS=	-ldflags "-X main.version=${DISTVERSIONPREFIX}${PORTVERSION} -s -w"
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/grpcurl

.include <bsd.port.mk>
