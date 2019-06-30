# Created by: Jev Björsell <ports@ecadlabs.com>
# $FreeBSD$

PORTNAME=	nginx-prometheus-exporter
PORTVERSION=	0.4.1
DISTVERSIONPREFIX=v
CATEGORIES=	www

MAINTAINER=	arcade@b1t.name
COMMENT=	Prometheus exporter for NGINX and NGINX Plus stats

LICENSE=	APACHE20

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	nginxinc

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

USE_RC_SUBR=	${PORTNAME}

LD_FLAG_X_PREFIX=	-X main
LD_FLAG_STRING=		-s \
		${LD_FLAG_X_PREFIX}.version=${PORTVERSION}
GO_BUILDFLAGS=	-v -ldflags "${LD_FLAG_STRING}"

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
