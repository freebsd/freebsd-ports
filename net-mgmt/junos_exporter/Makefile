PORTNAME=	junos_exporter
DISTVERSIONPREFIX=	v
DISTVERSION=	0.15.4
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	moggie@elasticmind.net
COMMENT=	Prometheus exporter for Juniper device metrics
WWW=		https://github.com/czerwonk/junos_exporter/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.26+,modules
USE_RC_SUBR=	junos_exporter
GO_MODULE=	github.com/czerwonk/junos_exporter

SUB_FILES=	pkg-message
SUB_LIST=	USERS="${USERS}" GROUPS="${GROUPS}"

USERS=		prometheus
GROUPS=		prometheus

PLIST_FILES=	bin/junos_exporter

.include <bsd.port.mk>
