# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	istio
PORTVERSION=	1.0.0
CATEGORIES=	sysutils

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Open platform to connect, manage, and secure microservices

LICENSE=	APACHE20

RUN_DEPENDS=	kubectl:sysutils/kubectl

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	istio

post-patch:
	${LN} -s ${WRKSRC}/vendor ${WRKSRC}/src
	${MKDIR} ${WRKSRC}/src/istio.io/istio/istioctl
	${LN} -s ${WRKSRC}/istioctl/cmd ${WRKSRC}/src/istio.io/istio/istioctl/cmd
	${LN} -s ${WRKSRC}/istioctl/pkg ${WRKSRC}/src/istio.io/istio/istioctl/pkg
	${LN} -s ${WRKSRC}/mixer ${WRKSRC}/src/istio.io/istio/mixer
	${LN} -s ${WRKSRC}/pilot ${WRKSRC}/src/istio.io/istio/pilot
	${LN} -s ${WRKSRC}/pkg ${WRKSRC}/src/istio.io/istio/pkg

do-build:
	cd ${WRKSRC} && \
		GOPATH=${WRKSRC} go build -o ${WRKSRC}/bin/istioctl \
		-ldflags="-X istio.io/istio/pkg/version.buildVersion=${PORTVERSION} \
		-X istio.io/istio/pkg/version.buildGitRevision=unknown \
		-X istio.io/istio/pkg/version.buildDockerHub=docker.io/istio" \
		./istioctl/cmd/istioctl/

do-install:
	${INSTALL_PROGRAM} \
		${WRKSRC}/bin/istioctl \
		${STAGEDIR}${PREFIX}/bin/istioctl
.for data in consul gcp kubernetes
	(cd ${WRKSRC}/install \
		&& ${COPYTREE_SHARE} ${data} ${STAGEDIR}${DATADIR})
.endfor

.include <bsd.port.mk>
