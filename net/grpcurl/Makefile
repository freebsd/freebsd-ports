# $FreeBSD$

PORTNAME=	grpcurl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
CATEGORIES=	net

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	Command-line tool that lets you interact with gRPC servers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	fullstorydev
GH_SUBDIR=	src/github.com/fullstorydev/grpcurl
GH_TAGNAME=	ca5693f
GH_TUPLE=	golang:protobuf:c65a041:jsonpb/vendor/github.com/golang/protobuf \
		jhump:protoreflect:5cc2142:protoreflect/vendor/github.com/jhump/protoreflect \
		golang:net:5f9ae10:net/vendor/golang.org/x/net \
		grpc:grpc-go:4172bfc:grpcgo/vendor/google.golang.org/grpc \
		golang:text:7922cc4:text/vendor/golang.org/x/text \
		google:go-genproto:7fd901a:gogenproto/vendor/google.golang.org/genproto

GO_BUILDFLAGS=	-ldflags "-X main.version=${DISTVERSIONPREFIX}${PORTVERSION} -s -w"
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/grpcurl

.include <bsd.port.mk>
