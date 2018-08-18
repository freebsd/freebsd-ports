# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	eksctl
PORTVERSION=	0.1.0
CATEGORIES=	sysutils

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	CLI for Amazon EKS

LICENSE=	APACHE20

RUN_DEPENDS=	kubectl:sysutils/kubectl \
		aws-iam-authenticator:security/aws-iam-authenticator

PORTSCOUT=	limit:^[0-9\.]*$$

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	weaveworks

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	${LN} -s ${WRKSRC}/vendor ${WRKSRC}/src
	${MKDIR} ${WRKSRC}/src/github.com/weaveworks/eksctl
	${LN} -s ${WRKSRC}/pkg ${WRKSRC}/src/github.com/weaveworks/eksctl/pkg

do-build:
	cd ${WRKSRC}/cmd/${PORTNAME} && \
		GOPATH=${WRKSRC} go build \
		-ldflags="-X main.gitCommit=${PORTVERSION} \
		-X main.builtAt=$$(date +'%s')"

do-install:
	${INSTALL_PROGRAM} \
		${WRKSRC}/cmd/${PORTNAME}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
