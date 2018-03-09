# Created by: Boris Samorodov <bsam@FreeBSDD.org>
# $FreeBSD$

PORTNAME=	blackbox_exporter
PORTVERSION=	0.12.0
DISTVERSIONPREFIX=v
CATEGORIES=	net-mgmt

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Prometheus exporter for endpoints over HTTP(S), DNS, TCP and ICMP

LICENSE=		APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	prometheus
USE_RC_SUBR=    blackbox_exporter
SUB_FILES=      pkg-message
SUB_LIST=       GH_TAGNAME=${GH_TAGNAME}

USERS=		prometheus
GROUPS=		prometheus

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	github.com/${GH_ACCOUNT}/${PORTNAME}

USE_RC_SUBR=	${PORTNAME}

PORTEXAMPLES=	${WRKSRC}/*.yml

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*.yml ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
