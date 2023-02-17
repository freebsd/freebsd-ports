PORTNAME=	terraform
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.9
CATEGORIES=	sysutils

MAINTAINER=	0xdutra@gmail.com
COMMENT=	Provides a common configuration to launch infrastructure
WWW=		https://terraform.io/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules
CPE_VENDOR=	hashicorp
USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp
GO_MODULE=	github.com/hashicorp/terraform

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
