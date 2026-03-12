PORTNAME=	grafanactl
PORTVERSION=	0.1.9
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Command-line tool designed to simplify interaction with Grafana resources
WWW=		https://grafana.github.io/grafanactl/ \
		https://github.com/grafana/grafanactl

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_BUILDFLAGS=	-ldflags="-s -w -X main.commit=9b9f82a -X main.date=$$(date -u +%Y-%m-%d) -X main.version=${PORTVERSION}"
GO_MODULE=	github.com/grafana/grafanactl
GO_TARGET=	./cmd/grafanactl

PLIST_FILES=	bin/grafanactl

USE_GITHUB=	yes
GH_ACCOUNT=	grafana

.include <bsd.port.mk>
