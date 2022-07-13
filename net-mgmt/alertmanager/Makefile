# Created by: Michal Hanula <michal@hanu.la>

PORTNAME=	alertmanager
PORTVERSION=	0.23.0
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	net-mgmt

MAINTAINER=	michal@hanu.la
COMMENT=	Alert routing for Prometheus

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
