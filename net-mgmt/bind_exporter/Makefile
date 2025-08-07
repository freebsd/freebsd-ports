PORTNAME=	bind_exporter
DISTVERSIONPREFIX=v
DISTVERSION=	0.8.0
PORTREVISION=	5
CATEGORIES=	net-mgmt dns

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Prometheus exporter for BIND server statistics
WWW=		https://github.com/prometheus-community/bind_exporter

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.23,modules
USE_RC_SUBR=	bind_exporter

GO_MODULE=	github.com/prometheus-community/bind_exporter
GO_BUILDFLAGS=	-v -ldflags "${LD_FLAG_STRING}"

BUILD_USER?=	${USER}
LD_FLAG_STRING=	${STRIP} \
		${LD_FLAG_X_PREFIX}.Version=${PORTVERSION} \
		${LD_FLAG_X_PREFIX}.Revision=${PORTREVISION} \
		${LD_FLAG_X_PREFIX}.Branch=release-${PORTVERSION:R} \
		${LD_FLAG_X_PREFIX}.BuildUser=${BUILD_USER}
LD_FLAG_X_PREFIX=	-X github.com/prometheus/common/version

.include <bsd.port.mk>
