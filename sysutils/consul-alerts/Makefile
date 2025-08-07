PORTNAME=	consul-alerts
PORTVERSION=	0.6.0
DISTVERSIONPREFIX=	v
PORTREVISION=	28
CATEGORIES=	sysutils

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Simple daemon to send notifications based on Consul health checks
WWW=		https://github.com/AcalephStorage/consul-alerts

LICENSE=	GPLv2+

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	AcalephStorage
GH_SUBDIR=	src/github.com/AcalephStorage/consul-alerts
GH_TUPLE=	aws:aws-sdk-go:v1.8.30:aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		imdario:mergo:0.2.2:mergo/vendor/github.com/imdario/mergo \
		mitchellh:hashstructure:9204ce5:hashstructure/vendor/github.com/mitchellh/hashstructure

GO_BUILDFLAGS=	-ldflags "-X main.GitDescribe=${DISTVERSIONFULL}"

PLIST_FILES=	${PREFIX}/bin/${PORTNAME}

USE_RC_SUBR=	${PORTNAME}

.include <bsd.port.mk>
