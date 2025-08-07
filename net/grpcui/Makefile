PORTNAME=	grpcui
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
PORTREVISION=	11
CATEGORIES=	net www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Interactive web UI for gRPC, along the lines of postman
WWW=		https://github.com/fullstorydev/grpcui

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/fullstorydev/grpcui
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
