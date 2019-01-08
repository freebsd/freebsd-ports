# Created by: Jev Björsell <ports@ecadlabs.com>
# $FreeBSD$

PORTNAME=	node_exporter
PORTVERSION=	0.17.0
DISTVERSIONPREFIX=v
CATEGORIES=	sysutils

MAINTAINER=	ports@ecadlabs.com
COMMENT=	Prometheus exporter for machine metrics

LICENSE=	APACHE20

USES=		go
USE_GITHUB=	yes

GH_ACCOUNT=	prometheus

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/node_exporter

USE_RC_SUBR=	node_exporter

BUILD_USER?=	${USER}
LD_FLAG_X_PREFIX=	-X ${GO_PKGNAME}/vendor/${GO_PKGNAME:H}/common/version
LD_FLAG_STRING=	-s \
		${LD_FLAG_X_PREFIX}.Version=${PORTVERSION} \
		${LD_FLAG_X_PREFIX}.Revision=${PORTREVISION} \
		${LD_FLAG_X_PREFIX}.Branch=release-${PORTVERSION:R} \
		${LD_FLAG_X_PREFIX}.BuildUser=${BUILD_USER}
GO_BUILDFLAGS=	-v -ldflags "${LD_FLAG_STRING}"

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/node_exporter ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
