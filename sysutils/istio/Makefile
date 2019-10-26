# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	istio
PORTVERSION=	1.3.3
CATEGORIES=	sysutils

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Open platform to connect, manage, and secure microservices

LICENSE=	APACHE20

RUN_DEPENDS=	kubectl:sysutils/kubectl

USES=		go:modules

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_SUB=	yes

USE_GITHUB=	yes

GO_TARGET=	./istioctl/cmd/istioctl
GO_BUILDFLAGS=	-ldflags="-X istio.io/istio/vendor/istio.io/pkg/version.buildVersion=${PORTVERSION} \
		-X istio.io/istio/pkg/version.buildDockerHub=docker.io/istio"

post-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} install ${STAGEDIR}${DATADIR})

post-install-EXAMPLES-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} samples ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
