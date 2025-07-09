PORTNAME=	phpfpm_exporter
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.1
PORTREVISION=	17
CATEGORIES=	net-mgmt

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Export php-fpm metrics in Prometheus format
WWW=		https://github.com/bakins/php-fpm-exporter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/bakins/php-fpm-exporter
GO_TARGET=	cmd/php-fpm-exporter/main.go:${PREFIX}/bin/${PORTNAME}

USE_RC_SUBR=	phpfpm_exporter
USERS=		prometheus
GROUPS=		prometheus

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
