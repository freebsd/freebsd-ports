PORTNAME=	thanos
DISTVERSIONPREFIX=	v
DISTVERSION=	0.36.0
CATEGORIES=	net-mgmt

MAINTAINER=	ler@FreeBSD.org
COMMENT=	Highly available Prometheus setup with long term storage capabilities
WWW=		https://thanos.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/thanos-io/thanos
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X github.com/prometheus/common/version.Version=${DISTVERSION} \
		-X github.com/prometheus/common/version.Revision="cfff551" \
		-X github.com/prometheus/common/version.Branch="master" \
		-X github.com/prometheus/common/version.BuildUser=${USER} \
		-X github.com/prometheus/common/version.BuildDate=${BUILD_DATE}"

PLIST_FILES=	bin/${PORTNAME}

BUILD_DATE=	$$(date +%d-%B-%Y)

.include <bsd.port.mk>
