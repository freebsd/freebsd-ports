PORTNAME=	ping_exporter
DISTVERSION=	1.1.0
PORTREVISION=	12
CATEGORIES=	net-mgmt

MAINTAINER=	jp+ports@supplntr.io
COMMENT=	Prometheus exporter for ICMP echo requests
WWW=		https://github.com/czerwonk/ping_exporter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_RC_SUBR=	ping_exporter

GO_MODULE=	github.com/czerwonk/ping_exporter@v0.0.0-20230519045214-d3a6779128c3

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
