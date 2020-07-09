# Created by: Boris Samorodov <bsam@FreeBSDD.org>
# $FreeBSD$

PORTNAME=	blackbox_exporter
PORTVERSION=	0.17.0
PORTREVISION=	1
DISTVERSIONPREFIX=v
CATEGORIES=	net-mgmt

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Prometheus exporter for endpoints over HTTP(S), DNS, TCP and ICMP

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	prometheus
GH_TUPLE=	golang:net:83d349e8ac1a:golang_net/vendor/golang.org/x/net_83d349e8ac1a
USE_RC_SUBR=	blackbox_exporter

USERS=		prometheus
GROUPS=		prometheus

PORTEXAMPLES=	${WRKSRC}/*.yml

OPTIONS_DEFINE=	EXAMPLES

SUB_FILES=	pkg-message
SUB_LIST=	GH_TAGNAME=${GH_TAGNAME}

post-extract:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/net
	${MV} ${WRKSRC}/vendor/golang.org/x/net_83d349e8ac1a ${WRKSRC}/vendor/golang.org/x/net

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*.yml ${STAGEDIR}${EXAMPLESDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/syslog.d \
		${STAGEDIR}${DATADIR}/newsyslog.conf.d
	${INSTALL_DATA} ${PATCHDIR}/blackbox_exporter.syslog \
		${STAGEDIR}${DATADIR}/syslog.d/blackbox_exporter.conf
	${INSTALL_DATA} ${PATCHDIR}/blackbox_exporter.newsyslog \
		${STAGEDIR}${DATADIR}/newsyslog.conf.d/blackbox_exporter.conf

.include <bsd.port.mk>
