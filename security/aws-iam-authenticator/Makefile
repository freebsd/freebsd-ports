# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aws-iam-authenticator
PORTVERSION=	0.3.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Use AWS IAM credentials to authenticate to a Kubernetes cluster

LICENSE=	APACHE20

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	kubernetes-sigs
GH_SUBDIR=	src/github.com/heptio/authenticator

GO_PKGNAME=	github.com/heptio/authenticator
GO_TARGET=	${GO_PKGNAME}/cmd/heptio-authenticator-aws

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} \
		${GO_WRKDIR_BIN}/heptio-authenticator-aws \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
