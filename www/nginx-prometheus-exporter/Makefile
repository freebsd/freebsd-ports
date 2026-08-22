PORTNAME=	nginx-prometheus-exporter
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.3
CATEGORIES=	www

MAINTAINER=	arcade@b1t.name
COMMENT=	Prometheus exporter for NGINX and NGINX Plus stats
WWW=		https://github.com/nginxinc/nginx-prometheus-exporter

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_RC_SUBR=	${PORTNAME}
GO_MODULE=	github.com/nginxinc/${PORTNAME}
GO_BUILDFLAGS=	-v -ldflags "${GO_LD_FLAGS:S|^|-X github.com/prometheus/common/version.|}"
DATETIMENOW=	%FT%T%z
GO_LD_FLAGS=	Version=${DISTVERSION} \
		BuildDate=${DATETIMENOW:gmtime} \
		Revision=79d3115

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
