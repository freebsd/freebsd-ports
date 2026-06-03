PORTNAME=	bumblebee
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	kiwi@FreeBSD.org
COMMENT=	Read-only supply-chain exposure scanner for developer endpoints
WWW=		https://github.com/perplexityai/bumblebee

LICENSE=	APACHE20

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	perplexityai

GO_MODULE=	github.com/perplexityai/bumblebee
GO_TARGET=	./cmd/bumblebee
GO_BUILDFLAGS=	-ldflags "-X main.Version=${DISTVERSIONPREFIX}${DISTVERSION}"

.include <bsd.port.mk>
