# $FreeBSD$

PORTNAME=	ping_exporter
DISTVERSION=	0.44
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	jp+ports@supplntr.io
COMMENT=	Prometheus exporter for ICMP echo requests

LICENSE=	APACHE20

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	czerwonk

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	github.com/${GH_ACCOUNT}/${PORTNAME}

USE_RC_SUBR=	ping_exporter

post-install:
	${INSTALL_DATA} ${PATCHDIR}/ping_exporter.yml.sample \
		${STAGEDIR}${PREFIX}/etc/ping_exporter.yml.sample

.include <bsd.port.mk>
