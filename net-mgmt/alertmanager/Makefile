PORTNAME=	alertmanager
PORTVERSION=	0.33.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net-mgmt
MASTER_SITES=	https://raw.githubusercontent.com/${GH_ACCOUNT}/${GH_PROJECT}/${DISTVERSIONFULL}/:gomod \
		https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/${DISTVERSIONFULL}/:ui
DISTFILES=	go.mod:gomod \
		${PORTNAME}-web-ui-${DISTVERSION}.tar.gz:ui

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	Alert routing for Prometheus
WWW=		https://prometheus.io/docs/alerting/alertmanager/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules
GO_MODULE=	github.com/prometheus/alertmanager

USE_GITHUB=	yes
GH_ACCOUNT=	prometheus
USE_RC_SUBR=	alertmanager

GO_TARGET=	./cmd/alertmanager ./cmd/amtool

USERS=		alertmanager
GROUPS=		alertmanager

GO_BUILDFLAGS=	-v -ldflags "${LD_FLAG_STRING}"

_BUILD_USER?=	${USER}
_BUILD_DATE=	$$(date +%Y-%m-%d)
LD_FLAG_STRING=	-s \
		${LD_FLAG_X_PREFIX}.Version=${PORTVERSION} \
		${LD_FLAG_X_PREFIX}.Revision=${PORTREVISION} \
		${LD_FLAG_X_PREFIX}.Branch=release-${PORTVERSION:R} \
		${LD_FLAG_X_PREFIX}.BuildUser=${_BUILD_USER} \
		${LD_FLAG_X_PREFIX}.BuildDate=${_BUILD_DATE}
LD_FLAG_X_PREFIX=	-X github.com/prometheus/common/version

post-patch:
	@${RM} -rf ${WRKSRC}/web/ui/static
	@${CP} -a ${WRKDIR}/dist ${WRKSRC}/ui/app/dist

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/alertmanager
	${INSTALL_DATA} \
		${WRKSRC}/doc/examples/simple.yml \
		${STAGEDIR}${PREFIX}/etc/alertmanager/alertmanager.yml.sample

.include <bsd.port.mk>
