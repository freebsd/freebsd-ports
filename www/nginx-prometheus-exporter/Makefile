PORTNAME=	nginx-prometheus-exporter
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.0
PORTREVISION=	3
CATEGORIES=	www

MAINTAINER=	arcade@b1t.name
COMMENT=	Prometheus exporter for NGINX and NGINX Plus stats
WWW=		https://github.com/nginxinc/nginx-prometheus-exporter

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_RC_SUBR=	${PORTNAME}
GO_MODULE=	github.com/nginxinc/nginx-prometheus-exporter
GO_BUILDFLAGS=	-v -ldflags "${LD_FLAG_STRING}"

LD_FLAG_X_PREFIX=	-X main
LD_FLAG_STRING=		${STRIP} ${LD_FLAG_X_PREFIX}.version=${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
