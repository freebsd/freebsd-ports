PORTNAME=	ping_exporter
DISTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	https://raw.githubusercontent.com/czerwonk/ping_exporter/${DISTVERSIONFULL}/:gomod
DISTFILES=	go.mod:gomod

MAINTAINER=	jp+ports@supplntr.io
COMMENT=	Prometheus exporter for ICMP echo requests

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	czerwonk

USE_RC_SUBR=	ping_exporter

GO_MODULE=	github.com/czerwonk/ping_exporter

SUB_FILES=	pkg-message

post-install:
	${INSTALL_DATA} ${PATCHDIR}/ping_exporter.yml.sample \
		${STAGEDIR}${PREFIX}/etc/ping_exporter.yml.sample
	${MKDIR} ${STAGEDIR}${DATADIR}/syslog.d \
		${STAGEDIR}${DATADIR}/newsyslog.conf.d
	${INSTALL_DATA} ${PATCHDIR}/ping_exporter.syslog \
		${STAGEDIR}${DATADIR}/syslog.d/ping_exporter.conf
	${INSTALL_DATA} ${PATCHDIR}/ping_exporter.newsyslog \
		${STAGEDIR}${DATADIR}/newsyslog.conf.d/ping_exporter.conf

.include <bsd.port.mk>
