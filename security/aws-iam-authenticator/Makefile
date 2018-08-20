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

PLIST_FILES=	bin/${PORTNAME}

do-build:
	cd ${WRKSRC}/${GH_SUBDIR} && \
		GOPATH=${WRKSRC} go build \
		./cmd/heptio-authenticator-aws

do-install:
	${INSTALL_PROGRAM} \
		${WRKSRC}/heptio-authenticator-aws \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
