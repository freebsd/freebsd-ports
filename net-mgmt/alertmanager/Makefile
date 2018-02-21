# Created by: Michal Hanula <michal@hanu.la>
# $FreeBSD$

PORTNAME=	alertmanager
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.0
CATEGORIES=	net-mgmt

MAINTAINER=	michal@hanu.la
COMMENT=	Alert routing for prometheus

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go gmake
USE_GITHUB=	yes
GH_ACCOUNT=	prometheus
USE_RC_SUBR=	alertmanager

GO_PKGNAME=	github.com/prometheus/${PORTNAME}

USERS=		alertmanager
GROUPS=		alertmanager

do-build:
	@cd ${GO_WRKSRC}/cmd/alertmanager && ${SETENV} ${GO_ENV} go install
	@cd ${GO_WRKSRC}/cmd/amtool && ${SETENV} ${GO_ENV} go install

do-install:
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/alertmanager ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/amtool ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/alertmanager
	${INSTALL_DATA} ${WRKSRC}/doc/examples/simple.yml ${STAGEDIR}${PREFIX}/etc/alertmanager/alertmanager.yml.sample

.include <bsd.port.mk>
