PORTNAME=	crowdsec
PORTVERSION=	1.0.13
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Crowdsec lightweight and collaborative security engine

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/crowdsecurity/crowdsec

GO_BUILDFLAGS=	-ldflags "-s -w \
		-X github.com/crowdsecurity/crowdsec/pkg/cwversion.Version=v${PORTVERSION}\
		-X github.com/crowdsecurity/crowdsec/pkg/cwversion.System=freebsd"

GO_TARGET=	./cmd/crowdsec \
		./cmd/crowdsec-cli

USE_RC_SUBR=	crowdsec

PLIST_FILES=	bin/crowdsec \
		bin/crowdsec-cli

.include <bsd.port.mk>
