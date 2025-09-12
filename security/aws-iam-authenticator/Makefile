PORTNAME=	aws-iam-authenticator
PORTVERSION=	0.7.7
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Use AWS IAM credentials to authenticate to a Kubernetes cluster
WWW=		https://github.com/kubernetes-sigs/aws-iam-authenticator

LICENSE=	APACHE20

USES=		go:1.25,modules

GO_MODULE=	github.com/kubernetes-sigs/${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-X sigs.k8s.io/aws-iam-authenticator/pkg.Version=${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
