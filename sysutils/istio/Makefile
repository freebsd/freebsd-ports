# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	istio
PORTVERSION=	1.0.6
CATEGORIES=	sysutils

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Open platform to connect, manage, and secure microservices

LICENSE=	APACHE20

RUN_DEPENDS=	kubectl:sysutils/kubectl

USES=		go

USE_GITHUB=	yes

GO_PKGNAME=	istio.io/istio
GO_TARGET=	${GO_PKGNAME}/istioctl/cmd/istioctl
GO_BUILDFLAGS=	-ldflags="-X istio.io/istio/pkg/version.buildVersion=${PORTVERSION} \
		-X istio.io/istio/pkg/version.buildDockerHub=docker.io/istio"

post-install:
.for data in consul gcp kubernetes
	(cd ${WRKSRC}/install \
		&& ${COPYTREE_SHARE} ${data} ${STAGEDIR}${DATADIR})
.endfor

.include <bsd.port.mk>
