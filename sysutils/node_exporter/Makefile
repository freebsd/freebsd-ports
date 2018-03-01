# Created by: Jev Björsell <ports@ecadlabs.com>
# $FreeBSD$

PORTNAME=	node_exporter
PORTVERSION=	0.15.2
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

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/node_exporter ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
