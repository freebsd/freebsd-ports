# $FreeBSD$

PORTNAME=	consul-alerts
PORTVERSION=	0.5.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Simple daemon to send notifications based on Consul health checks

LICENSE=	GPLv2+

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USES=		compiler go

USE_GITHUB=	yes
GH_ACCOUNT=	AcalephStorage
GH_SUBDIR=	src/github.com/AcalephStorage/consul-alerts
GH_TUPLE=	aws:aws-sdk-go:v1.8.30:aws_sdk_go/src/github.com/aws/aws-sdk-go \
		imdario:mergo:0.2.2:mergo/src/github.com/imdario/mergo \
		mitchellh:hashstructure:9204ce5:hashstructure/src/github.com/mitchellh/hashstructure

PLIST_FILES=	${PREFIX}/bin/${PORTNAME}

USE_RC_SUBR=	${PORTNAME}

do-build:
	cd ${GO_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -v -x \
			-ldflags "-X main.GitDescribe=${DISTVERSIONFULL}" -o bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${GO_WRKSRC}/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
BUILD_ENV=	CC=clang
.endif

.include <bsd.port.post.mk>
