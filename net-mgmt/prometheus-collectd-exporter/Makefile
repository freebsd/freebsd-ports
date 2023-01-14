PORTNAME=	prometheus-collectd-exporter
PORTVERSION=	0.5.0
DISTVERSIONPREFIX=	v
PORTREVISION=	8
CATEGORIES=	net-mgmt

MAINTAINER=	dsp@php.net
COMMENT=	Collectd exporter for Prometheus
WWW=		https://github.com/prometheus/collectd_exporter

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go gmake
USE_GITHUB=	yes
GH_ACCOUNT=	prometheus
GH_PROJECT=	collectd_exporter

PLIST_FILES=	bin/prometheus-collectd-exporter

USE_RC_SUBR=	collectd_exporter

.include <bsd.port.mk>
