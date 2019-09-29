# Created by: Jev Björsell <ports@ecadlabs.com>
# $FreeBSD$

PORTNAME=	prometheus
PORTVERSION=	1.8.2
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	net-mgmt
PKGNAMESUFFIX=	1

MAINTAINER=	ports@ecadlabs.com
COMMENT=	Systems monitoring and alerting toolkit

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes

GO_PKGNAME=	github.com/${PORTNAME}/${PORTNAME}

USE_RC_SUBR=	prometheus

USERS=		prometheus
GROUPS=		prometheus

BUILD_USER?=	${USER}
LD_FLAG_X_PREFIX=	-X ${GO_PKGNAME}/vendor/github.com/prometheus/common/version
GO_BUILDFLAGS=	-ldflags "\
		-s \
		${LD_FLAG_X_PREFIX}.Version=${PORTVERSION} \
		${LD_FLAG_X_PREFIX}.Revision=${PORTREVISION} \
		${LD_FLAG_X_PREFIX}.Branch=release-${PORTVERSION:R} \
		${LD_FLAG_X_PREFIX}.BuildUser=${BUILD_USER}"
GO_TARGET=	./cmd/prometheus \
		./cmd/promtool

post-install:
	${INSTALL_DATA} ${WRKSRC}/documentation/examples/prometheus.yml ${STAGEDIR}${LOCALBASE}/etc/prometheus.yml.sample
	${MKDIR} ${STAGEDIR}${DESTDIR}/var/db/prometheus

.include <bsd.port.mk>
