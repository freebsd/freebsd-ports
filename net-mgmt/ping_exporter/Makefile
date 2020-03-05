# $FreeBSD$

PORTNAME=	ping_exporter
DISTVERSION=	0.44
PORTREVISION=	2
CATEGORIES=	net-mgmt

MAINTAINER=	jp+ports@supplntr.io
COMMENT=	Prometheus exporter for ICMP echo requests

LICENSE=	APACHE20

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	czerwonk
GH_TUPLE=	golang:net:83d349e8ac1a:golang_net/vendor/golang.org/x/net_83d349e8ac1a \
		golang:sys:fead79001313:golang_sys/vendor/golang.org/x/sys_fead79001313

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	github.com/${GH_ACCOUNT}/${PORTNAME}

USE_RC_SUBR=	ping_exporter

pre-build:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/net ${WRKSRC}/vendor/golang.org/x/sys
	${MV} ${WRKSRC}/vendor/golang.org/x/net_83d349e8ac1a ${WRKSRC}/vendor/golang.org/x/net
	${MV} ${WRKSRC}/vendor/golang.org/x/sys_fead79001313 ${WRKSRC}/vendor/golang.org/x/sys

post-install:
	${INSTALL_DATA} ${PATCHDIR}/ping_exporter.yml.sample \
		${STAGEDIR}${PREFIX}/etc/ping_exporter.yml.sample

.include <bsd.port.mk>
