PORTNAME=	prometheus
PORTVERSION=	1.8.2
DISTVERSIONPREFIX=	v
PORTREVISION=	32
CATEGORIES=	net-mgmt
PKGNAMESUFFIX=	1

MAINTAINER=	ports@ecadlabs.com
COMMENT=	Systems monitoring and alerting toolkit
WWW=		https://prometheus.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go

CONFLICTS_INSTALL=	prometheus prometheus3

USE_GITHUB=	yes
GH_TUPLE=	golang:sys:v0.6.0:golang_sys/vendor/golang.org/x/sys_v0.6.0

GO_PKGNAME=	github.com/${PORTNAME}/${PORTNAME}

USE_RC_SUBR=	prometheus

USERS=		prometheus
GROUPS=		prometheus

BUILD_USER?=	${USER}
LD_FLAG_X_PREFIX=	-X ${GO_PKGNAME}/vendor/github.com/prometheus/common/version
GO_BUILDFLAGS=	-ldflags "\
		${STRIP} \
		${LD_FLAG_X_PREFIX}.Version=${PORTVERSION} \
		${LD_FLAG_X_PREFIX}.Revision=${PORTREVISION} \
		${LD_FLAG_X_PREFIX}.Branch=release-${PORTVERSION:R} \
		${LD_FLAG_X_PREFIX}.BuildUser=${BUILD_USER}"
GO_TARGET=	./cmd/prometheus \
		./cmd/promtool

post-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${MV} ${WRKSRC}/vendor/golang.org/x/sys_v0.6.0 ${WRKSRC}/vendor/golang.org/x/sys

post-install:
	${INSTALL_DATA} ${WRKSRC}/documentation/examples/prometheus.yml ${STAGEDIR}${LOCALBASE}/etc/prometheus.yml.sample
	${MKDIR} ${STAGEDIR}${DESTDIR}/var/db/prometheus

.include <bsd.port.mk>
