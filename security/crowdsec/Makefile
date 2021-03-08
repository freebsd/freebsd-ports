# $FreeBSD$

PORTNAME=	crowdsec
PORTVERSION=	1.0.7
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Crowdsec lightweight and collaborative security engine

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/crowdsecurity/crowdsec

GO_BUILDFLAGS=	-ldflags "-s -w \
		-X github.com/crowdsecurity/crowdsec/pkg/cwversion.Version=${PORTVERSION}"

GO_TARGET=	./cmd/crowdsec \
		./cmd/crowdsec-cli

PLIST_FILES=	bin/crowdsec \
		bin/crowdsec-cli

.include <bsd.port.mk>
