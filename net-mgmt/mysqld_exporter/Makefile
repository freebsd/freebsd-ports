# Created by: Alexey Bobkov <mr.deadlystorm@gmail.com>
# $FreeBSD$

PORTNAME=	mysqld_exporter
PORTVERSION=	0.11.0
DISTVERSIONPREFIX=v
CATEGORIES=	net-mgmt

MAINTAINER=	mr.deadlystorm@gmail.com
COMMENT=	Prometheus exporter for MySQL server metrics

LICENSE=	APACHE20

USES=		go
USE_GITHUB=	yes

GH_ACCOUNT=	prometheus

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/mysqld_exporter

USE_RC_SUBR=	mysqld_exporter

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/mysqld_exporter ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
