# $FreeBSD$

PORTNAME=	snmp_exporter
PORTVERSION=	0.14.0
DISTVERSIONPREFIX=v
CATEGORIES=	sysutils

MAINTAINER=	fabian.freyer@physik.tu-berlin.de
COMMENT=	SNMP Exporter for Prometheus

LICENSE=	APACHE20

LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp

USES=		go:modules
USE_GITHUB=	yes
USE_RC_SUBR=	snmp_exporter

GH_ACCOUNT=	prometheus

GO_TARGET=	. \
		./generator:snmp_exporter_generator

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${GO_WRKSRC}/generator/main.go

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/snmp_exporter/
	${INSTALL_DATA} ${FILESDIR}/generator.yml ${STAGEDIR}${PREFIX}/etc/snmp_exporter/generator.yml

.include <bsd.port.mk>
