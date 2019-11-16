# Created by: Michal Hanula <michal@hanu.la>
# $FreeBSD$

PORTNAME=	alertmanager
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18.0
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	michal@hanu.la
COMMENT=	Alert routing for prometheus

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	prometheus
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
