# Created by: Palle Girgensohn <girgen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	packetbeat
PORTVERSION=	1.2.3
DISTVERSIONPREFIX=v
CATEGORIES=	sysutils

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Elasticsearch real-time network packet analytics

LICENSE=	APACHE20

#BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	elastic
GH_PROJECT=	beats

USES=		gmake go
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGETS=	${PORTNAME}

USE_RC_SUBR=	${PORTNAME}

do-build:
	cd ${GO_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GMAKE} -C ${GO_TARGETS}

do-install:
	${INSTALL_PROGRAM} ${GO_WRKSRC}/${GO_TARGETS}/${GO_TARGETS} \
		${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${GO_WRKSRC}/${GO_TARGETS}/etc/${GO_TARGETS}.yml \
		${STAGEDIR}${PREFIX}/etc/${GO_TARGETS}.yml.sample

.include <bsd.port.mk>
