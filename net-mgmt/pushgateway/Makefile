PORTNAME=	pushgateway
DISTVERSIONPREFIX=	v
DISTVERSION=	1.11.1
PORTREVISION=	4
CATEGORIES=	net-mgmt

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	Prometheus push acceptor for ephemeral and batch jobs
WWW=		https://github.com/prometheus/pushgateway

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake go:1.24,modules
GO_MODULE=	github.com/prometheus/pushgateway

USE_RC_SUBR=	pushgateway

USERS=		prometheus
GROUPS=		prometheus

PLIST_FILES=	bin/pushgateway

do-test:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GMAKE} test)

.include <bsd.port.mk>
