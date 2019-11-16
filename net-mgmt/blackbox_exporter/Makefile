# Created by: Boris Samorodov <bsam@FreeBSDD.org>
# $FreeBSD$

PORTNAME=	blackbox_exporter
PORTVERSION=	0.15.0
DISTVERSIONPREFIX=v
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Prometheus exporter for endpoints over HTTP(S), DNS, TCP and ICMP

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	prometheus
USE_RC_SUBR=	blackbox_exporter

USERS=		prometheus
GROUPS=		prometheus

PORTEXAMPLES=	${WRKSRC}/*.yml

OPTIONS_DEFINE=	EXAMPLES

SUB_FILES=	pkg-message
SUB_LIST=	GH_TAGNAME=${GH_TAGNAME}
PLIST_FILES=	bin/blackbox_exporter \
		${EXAMPLESDIR}/blackbox.yml \
		${EXAMPLESDIR}/example.yml

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*.yml ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
