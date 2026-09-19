PORTNAME=	pack
DISTVERSIONPREFIX=	v
DISTVERSION=	0.40.9
CATEGORIES=	sysutils

MAINTAINER=	gogolok@gmail.com
COMMENT=	CLI for building OCI images using Cloud Native Buildpacks
WWW=		https://github.com/buildpacks/pack

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64

USES=		go:modules
GO_MODULE=	github.com/buildpacks/pack
GO_BUILDFLAGS=	-ldflags="-X 'github.com/buildpacks/pack/pkg/client.Version=${DISTVERSIONFULL}'"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
