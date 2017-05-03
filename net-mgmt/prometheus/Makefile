# Created by: Jev Björsell <ports@ecadlabs.com>
# $FreeBSD$

PORTNAME=	prometheus
PORTVERSION=	1.6.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net-mgmt

MAINTAINER=	ports@ecadlabs.com
COMMENT=	Systems monitoring and alerting toolkit

LICENSE=	APACHE20

USES=		go gmake
USE_GITHUB=	yes

GO_PKGNAME=	github.com/${PORTNAME}/${PORTNAME}

USE_RC_SUBR=	prometheus

USERS=		prometheus
GROUPS=		prometheus

LD_FLAG_STRING= ${GO_PKGNAME}/vendor/github.com/prometheus/common/version.
do-build:
	(cd ${GO_WRKSRC}/cmd/prometheus ; ${SETENV} ${GO_ENV} go install -ldflags \
	    "-s -X ${LD_FLAG_STRING}.Version=${PORTVERSION}") 

	(cd ${GO_WRKSRC}/cmd/promtool ; ${SETENV} ${GO_ENV} go install -ldflags \
	    "-s -X ${LD_FLAG_STRING}.Version=${PORTVERSION}")

do-install:
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/prometheus ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/promtool ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/documentation/examples/prometheus.yml ${STAGEDIR}${LOCALBASE}/etc/prometheus.yml.sample

	${MKDIR} ${STAGEDIR}${DESTDIR}/var/db/prometheus

.include <bsd.port.mk>
