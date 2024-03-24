PORTNAME=	eksctl
PORTVERSION=	0.171.0
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	CLI for Amazon EKS
WWW=		https://eksctl.io/

LICENSE=	APACHE20

RUN_DEPENDS=	kubectl:sysutils/kubectl

USES=		go:modules

PLIST_FILES=	bin/${PORTNAME}

GO_MODULE=	github.com/eksctl-io/${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-X github.com/weaveworks/eksctl/pkg/version.gitCommit=9858c5482a31 \
		-X github.com/weaveworks/eksctl/pkg/version.buildDate=$$(date +%Y-%m-%dT%H:%M:%SZ)"

.include <bsd.port.mk>
