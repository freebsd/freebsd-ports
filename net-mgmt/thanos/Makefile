PORTNAME=	thanos
DISTVERSIONPREFIX=	v
DISTVERSION=	0.39.2
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Highly available Prometheus setup with long term storage capabilities
WWW=		https://thanos.io/ \
		https://github.com/thanos-io/thanos/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/thanos-io/thanos
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X github.com/prometheus/common/version.Branch="master" \
		-X github.com/prometheus/common/version.BuildDate=${BUILD_DATE} \
		-X github.com/prometheus/common/version.BuildUser=${USER} \
		-X github.com/prometheus/common/version.Revision="36681af" \
		-X github.com/prometheus/common/version.Version=${DISTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

BUILD_DATE=	$$(date +%d-%B-%Y)

.include <bsd.port.mk>
