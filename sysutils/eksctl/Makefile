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
GH_SUBDIR=	src/github.com/weaveworks/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

do-build:
	cd ${WRKSRC}/${GH_SUBDIR} && \
		GOPATH=${WRKSRC} go build \
		-ldflags="-X main.gitCommit=${PORTVERSION} \
		-X main.builtAt=$$(date +'%s')" \
		./cmd/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} \
		${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
