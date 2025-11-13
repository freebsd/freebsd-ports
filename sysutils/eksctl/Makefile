PORTNAME=	eksctl
PORTVERSION=	0.217.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	CLI for Amazon EKS
WWW=		https://eksctl.io/

LICENSE=	APACHE20

RUN_DEPENDS=	kubectl:sysutils/kubectl

USES=		go:1.25,modules

PLIST_FILES=	bin/${PORTNAME}

GO_MODULE=	github.com/eksctl-io/${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-X github.com/weaveworks/eksctl/pkg/version.gitCommit=d8988e840ac6 \
		-X github.com/weaveworks/eksctl/pkg/version.buildDate=$$(date +%Y-%m-%dT%H:%M:%SZ)"

.include <bsd.port.mk>
