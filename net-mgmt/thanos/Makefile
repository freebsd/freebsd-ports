PORTNAME=	thanos
DISTVERSIONPREFIX=	v
DISTVERSION=	0.38.0
PORTREVISION=	3
CATEGORIES=	net-mgmt

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Highly available Prometheus setup with long term storage capabilities
WWW=		https://thanos.io/ \
		https://github.com/thanos-io/thanos/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24,modules

GO_MODULE=	github.com/thanos-io/thanos
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X github.com/prometheus/common/version.Revision="18291a7" \
		-X github.com/prometheus/common/version.Branch="master" \
		-X github.com/prometheus/common/version.BuildDate=${BUILD_DATE} \
		-X github.com/prometheus/common/version.BuildUser=${USER} \
		-X github.com/prometheus/common/version.Revision="0439da0" \
		-X github.com/prometheus/common/version.Version=${DISTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

BUILD_DATE=	$$(date +%d-%B-%Y)

.include <bsd.port.mk>
