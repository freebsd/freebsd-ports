# $FreeBSD$

PORTNAME=	grpcurl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
CATEGORIES=	net

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	Command-line tool that lets you interact with gRPC servers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	fullstorydev
GH_SUBDIR=	src/github.com/fullstorydev/grpcurl
GH_TAGNAME=	ca5693f
GH_TUPLE=	golang:protobuf:c65a041:jsonpb/src/github.com/golang/protobuf \
		jhump:protoreflect:5cc2142:protoreflect/src/github.com/jhump/protoreflect \
		golang:net:5f9ae10:net/src/golang.org/x/net \
		grpc:grpc-go:4172bfc:grpcgo/src/google.golang.org/grpc \
		golang:text:7922cc4:text/src/golang.org/x/text \
		google:go-genproto:7fd901a:gogenproto/src/google.golang.org/genproto

PLIST_FILES=	bin/grpcurl

do-build:
	cd ${WRKSRC}/cmd/${PORTNAME} && ${SETENV} ${MAKE_ENV} CGO_ENABLED=0 GOPATH=${WRKSRC} \
	${LOCALBASE}/bin/go build -ldflags "-X main.version=${DISTVERSIONPREFIX}${PORTVERSION} -s -w" \
		-o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/fullstorydev/grpcurl/cmd/${PORTNAME}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
