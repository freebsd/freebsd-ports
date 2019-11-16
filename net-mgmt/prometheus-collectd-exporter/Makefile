# $FreeBSD$

PORTNAME=	prometheus-collectd-exporter
PORTVERSION=	0.4.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	dsp@php.net
COMMENT=	Collectd exporter for Prometheus

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go gmake
USE_GITHUB=	yes
GH_ACCOUNT=	prometheus
GH_PROJECT=	collectd_exporter

PLIST_FILES=	bin/prometheus-collectd-exporter

USE_RC_SUBR=	collectd_exporter

.include <bsd.port.mk>
