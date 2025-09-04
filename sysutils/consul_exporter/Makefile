PORTNAME=	consul_exporter
PORTVERSION=	0.3.0
DISTVERSIONPREFIX=	v
PORTREVISION=	29
CATEGORIES=	sysutils

MAINTAINER=	t.tom@succont.de
COMMENT=	Exporter for Consul metrics
WWW=		https://github.com/prometheus/consul_exporter

LICENSE=	APACHE20

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	prometheus
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/consul_exporter

GO_BUILDFLAGS=	-ldflags "\
		-X github.com/prometheus/consul_exporter/version.Version=${PORTVERSION}  \
		-X github.com/prometheus/consul_exporter/version.VersionPrerelease=  \
		-X github.com/prometheus/consul_exporter/version.GitDescribe=v${PORTVERSION}"

USE_RC_SUBR=	consul_exporter

PLIST_FILES=	bin/consul_exporter

.include <bsd.port.mk>
