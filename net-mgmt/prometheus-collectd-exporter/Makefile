PORTNAME=	prometheus-collectd-exporter
PORTVERSION=	0.5.0
DISTVERSIONPREFIX=	v
PORTREVISION=	30
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
GH_TUPLE=	golang:sys:v0.6.0:sys

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

PLIST_FILES=	bin/prometheus-collectd-exporter

USE_RC_SUBR=	collectd_exporter

.include <bsd.port.mk>
