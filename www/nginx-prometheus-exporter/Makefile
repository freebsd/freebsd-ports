# Created by: Jev Björsell <ports@ecadlabs.com>
# $FreeBSD$

PORTNAME=	nginx-prometheus-exporter
PORTVERSION=	0.8.0
DISTVERSIONPREFIX=v
CATEGORIES=	www

MAINTAINER=	arcade@b1t.name
COMMENT=	Prometheus exporter for NGINX and NGINX Plus stats

LICENSE=	APACHE20

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	nginxinc

PLIST_FILES=	bin/${PORTNAME}

USE_RC_SUBR=	${PORTNAME}

LD_FLAG_X_PREFIX=	-X main
LD_FLAG_STRING=		-s \
		${LD_FLAG_X_PREFIX}.version=${PORTVERSION}
GO_BUILDFLAGS=	-v -ldflags "${LD_FLAG_STRING}"

.include <bsd.port.mk>
