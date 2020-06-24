# $FreeBSD$

PORTNAME=	grpcui
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
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
		cncf:udpa:269d4d468f6f:cncf_udpa_go/vendor/github.com/cncf/udpa \
		envoyproxy:go-control-plane:v0.9.4:envoyproxy_go_control_plane/vendor/github.com/envoyproxy/go-control-plane \
		envoyproxy:protoc-gen-validate:v0.1.0:envoyproxy_protoc_gen_validate/vendor/github.com/envoyproxy/protoc-gen-validate \
		fullstorydev:grpcurl:v1.6.0:fullstorydev_grpcurl/vendor/github.com/fullstorydev/grpcurl \
		golang:appengine:v1.6.5:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:87dc89f01550:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:0de0cce0169b:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.5:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:33540a1f6037:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		google:go-cmp:v0.3.1:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:24fa4b261c55:google_go_genproto/vendor/google.golang.org/genproto \
		googleapis:google-cloud-go:v0.44.3:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		grpc:grpc-go:v1.29.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		jhump:protoreflect:v1.6.1:jhump_protoreflect/vendor/github.com/jhump/protoreflect \
		pkg:browser:0a3d74bf9ce4:pkg_browser/vendor/github.com/pkg/browser

GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
