PORTNAME=	mysqld_exporter
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.2
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	mr.deadlystorm@gmail.com
COMMENT=	Prometheus exporter for MySQL server metrics
WWW=		https://github.com/prometheus/mysqld_exporter

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.23,modules
GO_MODULE=	github.com/prometheus/mysqld_exporter

PLIST_FILES=	bin/mysqld_exporter
USE_RC_SUBR=	mysqld_exporter
SUB_FILES=	pkg-message

.include <bsd.port.mk>
