PORTNAME=	snmp_exporter
DISTVERSIONPREFIX=v
DISTVERSION=	0.29.0
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	ivy@FreeBSD.org
COMMENT=	SNMP Exporter for Prometheus
WWW=		https://github.com/prometheus/snmp_exporter

LICENSE=	APACHE20

LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp

USES=		go:modules
USE_RC_SUBR=	snmp_exporter

GO_MODULE=	github.com/prometheus/snmp_exporter
GO_TARGET=	. \
		./generator:snmp_exporter_generator

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/snmp_exporter/
	${INSTALL_DATA} ${FILESDIR}/generator.yml ${STAGEDIR}${PREFIX}/etc/snmp_exporter/generator.yml.sample

.include <bsd.port.mk>
