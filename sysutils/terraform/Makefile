PORTNAME=	terraform
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
CATEGORIES=	sysutils

MAINTAINER=	nulldutra@proton.me
COMMENT=	Provides a common configuration to launch infrastructure
WWW=		https://terraform.io/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules
CPE_VENDOR=	hashicorp
GO_MODULE=	github.com/hashicorp/terraform

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
