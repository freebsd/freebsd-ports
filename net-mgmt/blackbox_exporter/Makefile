PORTNAME=	blackbox_exporter
DISTVERSIONPREFIX=	v
DISTVERSION=	0.27.0
PORTREVISION=	3
CATEGORIES=	net-mgmt

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Prometheus exporter for endpoints over HTTP(S), DNS, TCP and ICMP
WWW=		https://github.com/prometheus/blackbox_exporter

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules
CPE_VENDOR=	prometheus
USE_RC_SUBR=	blackbox_exporter
GO_MODULE=	github.com/prometheus/blackbox_exporter

SUB_FILES=	pkg-message
SUB_LIST=	DISTVERSIONFULL=${DISTVERSIONFULL}

USERS=		prometheus
GROUPS=		prometheus

PORTEXAMPLES=	${WRKSRC}/*.yml

OPTIONS_DEFINE=	EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*.yml ${STAGEDIR}${EXAMPLESDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/syslog.d \
		${STAGEDIR}${DATADIR}/newsyslog.conf.d
	${INSTALL_DATA} ${PATCHDIR}/blackbox_exporter.syslog \
		${STAGEDIR}${DATADIR}/syslog.d/blackbox_exporter.conf
	${INSTALL_DATA} ${PATCHDIR}/blackbox_exporter.newsyslog \
		${STAGEDIR}${DATADIR}/newsyslog.conf.d/blackbox_exporter.conf

.include <bsd.port.mk>
