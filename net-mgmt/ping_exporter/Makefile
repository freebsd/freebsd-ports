PORTNAME=	ping_exporter
DISTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	ivy@FreeBSD.org
COMMENT=	Prometheus exporter for ICMP echo requests
WWW=		https://github.com/czerwonk/ping_exporter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	czerwonk

USE_RC_SUBR=	ping_exporter

GO_MOD_DIST=	github
GO_MODULE=	github.com/czerwonk/ping_exporter
GO_TARGET=	.:ping_exporter

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
