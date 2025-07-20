PORTNAME=	snmp_exporter
DISTVERSIONPREFIX=v
DISTVERSION=	0.29.0
PORTREVISION=	4
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
	${INSTALL_DATA} ${WRKSRC}/snmp.yml ${STAGEDIR}${PREFIX}/etc/snmp_exporter/snmp.yml.sample
	${INSTALL_DATA} ${WRKSRC}/generator/generator.yml ${STAGEDIR}${PREFIX}/etc/snmp_exporter/generator.yml.sample

.include <bsd.port.mk>
