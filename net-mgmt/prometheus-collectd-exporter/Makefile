# $FreeBSD$

PORTNAME=	prometheus-collectd-exporter
PORTVERSION=	0.3.1
CATEGORIES=	net-mgmt
DISTNAME=	0.3.1

MAINTAINER=	dsp@php.net
COMMENT=	Collectd exporter for prometheus

LICENSE=	APACHE20

USES=		go gmake
WRKSRC=		${WRKDIR}/collectd_exporter-${PORTVERSION}
USE_GITHUB=	yes
GH_ACCOUNT=	prometheus
GH_PROJECT=	collectd_exporter

PLIST_FILES=	bin/prometheus-collectd-exporter

STRIP=

.include <bsd.port.mk>
