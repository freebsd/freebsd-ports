PORTNAME=	alertmanager
PORTVERSION=	0.26.0
DISTVERSIONPREFIX=	v
PORTREVISION=	13
CATEGORIES=	net-mgmt

MAINTAINER=	michal@hanu.la
COMMENT=	Alert routing for Prometheus
WWW=		https://prometheus.io/docs/alerting/alertmanager/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/prometheus/alertmanager

USE_RC_SUBR=	alertmanager

GO_TARGET=	./cmd/alertmanager ./cmd/amtool

USERS=		alertmanager
GROUPS=		alertmanager

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/alertmanager
	${INSTALL_DATA} \
		${WRKSRC}/doc/examples/simple.yml \
		${STAGEDIR}${PREFIX}/etc/alertmanager/alertmanager.yml.sample

.include <bsd.port.mk>
