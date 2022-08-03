PORTNAME=	thanos
DISTVERSIONPREFIX=	v
DISTVERSION=	0.26.0
PORTREVISION=	3
CATEGORIES=	net-mgmt

MAINTAINER=	ler@FreeBSD.org
COMMENT=	Highly available Prometheus setup with long term storage capabilities

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

# fails to build on armv7/i386: pkg/store/cache/cache.go:166:22: constant 9223372036854775807 overflows int
ONLY_FOR_ARCHS=	aarch64 amd64

USES=		go:modules

BUILD_DATE=	$$(date +%d-%B-%Y)

GO_MODULE=	github.com/thanos-io/thanos
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
                -s -w \
		-X github.com/prometheus/common/version.Version=${DISTVERSION} \
		-X github.com/prometheus/common/version.Revision="31cacc4" \
		-X github.com/prometheus/common/version.Branch="master" \
		-X github.com/prometheus/common/version.BuildUser=${USER} \
		-X github.com/prometheus/common/version.BuildDate=${BUILD_DATE}"

USE_GITHUB=	yes
GH_ACCOUNT=	thanos-io

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
