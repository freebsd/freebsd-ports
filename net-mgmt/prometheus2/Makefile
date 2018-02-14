# $FreeBSD$

PORTNAME=	prometheus
PORTVERSION=	2.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net-mgmt

MAINTAINER=	dor.bsd@xm0.uk
COMMENT=	Systems monitoring and alerting toolkit

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go gmake
USE_GITHUB=	yes
GH_ACCOUNT=	prometheus
GH_PROJECT=	prometheus

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}

USE_RC_SUBR=	prometheus

USERS=		prometheus
GROUPS=		prometheus

BUILD_USER?=	${USER}
LD_FLAG_X_PREFIX=	-X ${GO_PKGNAME}/vendor/${GO_PKGNAME:H}/common/version
LD_FLAG_STRING=	-s \
				${LD_FLAG_X_PREFIX}.Version=${PORTVERSION} \
				${LD_FLAG_X_PREFIX}.Revision=${PORTREVISION} \
				${LD_FLAG_X_PREFIX}.Branch=release-${PORTVERSION:R} \
				${LD_FLAG_X_PREFIX}.BuildUser=${BUILD_USER}

PROMETHEUS_BINARIES=	prometheus promtool

do-build:
.for bin in ${PROMETHEUS_BINARIES}
	( cd ${GO_WRKSRC}/cmd/${bin} ; \
		${SETENV} ${GO_ENV} go install -ldflags "${LD_FLAG_STRING}" )
.endfor

do-install:
.for bin in ${PROMETHEUS_BINARIES}
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/${bin} ${STAGEDIR}${PREFIX}/bin
.endfor

	${INSTALL_DATA} \
		${WRKSRC}/documentation/examples/prometheus.yml \
		${STAGEDIR}${LOCALBASE}/etc/prometheus.yml.sample

	${MKDIR} ${STAGEDIR}${DESTDIR}/var/db/prometheus

.include <bsd.port.mk>
