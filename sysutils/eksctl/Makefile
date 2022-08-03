PORTNAME=	eksctl
PORTVERSION=	0.94.0
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/danilo

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	CLI for Amazon EKS

LICENSE=	APACHE20

RUN_DEPENDS=	kubectl:sysutils/kubectl \
		aws-iam-authenticator:security/aws-iam-authenticator

USES=		go:modules tar:xz

PORTSCOUT=	limit:^[0-9\.]*$$

PLIST_FILES=	bin/${PORTNAME}

GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-X github.com/weaveworks/eksctl/pkg/version.gitCommit=${PORTVERSION} \
		-X github.com/weaveworks/eksctl/pkg/version.builtAt=$$(date +'%s')"

.include <bsd.port.mk>
