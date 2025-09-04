PORTNAME=	prometheus-bird-exporter
DISTVERSION=	1.4.3
PORTREVISION=	3
CATEGORIES=	net-mgmt

MAINTAINER=	ivy@FreeBSD.org
COMMENT=	Prometheus state exporter for BIRD routing daemon
WWW=		https://github.com/czerwonk/bird_exporter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	czerwonk
GH_PROJECT=	bird_exporter

USE_RC_SUBR=	bird_exporter

GO_MODULE=	github.com/czerwonk/bird_exporter
GO_MOD_DIST=	https://raw.githubusercontent.com/czerwonk/bird_exporter/refs/tags/${DISTVERSION}/
GO_TARGET=	.:bird_exporter

PLIST_FILES=	${PREFIX}/bin/bird_exporter

.include <bsd.port.mk>
