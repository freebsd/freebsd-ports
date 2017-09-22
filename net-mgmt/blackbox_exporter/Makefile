# Created by: Boris Samorodov <bsam@FreeBSDD.org>
# $FreeBSD$

PORTNAME=	blackbox_exporter
PORTVERSION=	0.9.1
DISTVERSIONPREFIX=v
CATEGORIES=	net-mgmt

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Prometheus exporter for endpoints over HTTP(S), DNS, TCP and ICMP

LICENSE=	APACHE20

USES=		go
USE_GITHUB=	yes

GH_ACCOUNT=	prometheus

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	github.com/${GH_ACCOUNT}/${PORTNAME}

USE_RC_SUBR=	${PORTNAME}

PORTEXAMPLES=	${WRKSRC}/*.yml

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*.yml ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
