PORTNAME=	phpfpm_exporter
PORTVERSION=	0.4.1
DISTVERSIONPREFIX=v
PORTREVISION=	3
CATEGORIES=	net-mgmt

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Export php-fpm metrics in Prometheus format

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	bakins
GH_PROJECT=	php-fpm-exporter

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGET=	./cmd/${GH_PROJECT}:${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}
USE_RC_SUBR=	phpfpm_exporter
USERS=		prometheus
GROUPS=		prometheus

.include <bsd.port.mk>
