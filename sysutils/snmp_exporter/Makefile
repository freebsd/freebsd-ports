# $FreeBSD$

PORTNAME=	snmp_exporter
PORTVERSION=	0.9.0
DISTVERSIONPREFIX=v
CATEGORIES=	sysutils

MAINTAINER=	fabian.freyer@physik.tu-berlin.de
COMMENT=	SNMP Exporter for Prometheus

LICENSE=	APACHE20

LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp

USES=		go
USE_GITHUB=	yes
USE_RC_SUBR=	snmp_exporter

GH_ACCOUNT=	prometheus

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	github.com/${GH_ACCOUNT}/${PORTNAME}

do-build:
	(cd ${GO_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} install -v ${GO_TARGET})
	(cd ${GO_WRKSRC}/generator; ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} install -v ${GO_TARGET}/generator)

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${GO_WRKSRC}/generator/main.go

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/snmp_exporter/
	${INSTALL_DATA} ${FILESDIR}/generator.yml ${STAGEDIR}${PREFIX}/etc/snmp_exporter/generator.yml
	${INSTALL_PROGRAM} ${WRKDIR}/bin/snmp_exporter ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/bin/generator ${STAGEDIR}${PREFIX}/bin/snmp_exporter_generator

.include <bsd.port.mk>
