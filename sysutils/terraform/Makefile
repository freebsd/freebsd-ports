PORTNAME=	terraform
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.4
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	nulldutra@proton.me
COMMENT=	Provides a common configuration to launch infrastructure
WWW=		https://terraform.io/

LICENSE_NAME=	Business Source License 1.1
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror pkg-sell auto-accept

USES=		cpe go:1.21,modules
CPE_VENDOR=	hashicorp
GO_MODULE=	github.com/hashicorp/terraform

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
