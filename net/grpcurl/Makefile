# $FreeBSD$

PORTNAME=	grpcurl
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.0
CATEGORIES=	net

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	Command-line tool that lets you interact with gRPC servers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	fullstorydev
GH_SUBDIR=	src/github.com/fullstorydev/grpcurl
GH_TUPLE=	\
		golang:net:d8887717615a:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.3.1:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:d0b11bdaac8a:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.0:golang_text/vendor/golang.org/x/text \
		google:go-genproto:c66870c02cf8:google_go_genproto/vendor/google.golang.org/genproto \
		grpc:grpc-go:v1.21.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		jhump:protoreflect:v1.5.0:jhump_protoreflect/vendor/github.com/jhump/protoreflect

GO_BUILDFLAGS=	-ldflags "-X main.version=${DISTVERSIONPREFIX}${PORTVERSION} -s -w"
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/grpcurl

.include <bsd.port.mk>
