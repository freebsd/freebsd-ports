PORTNAME=	terragrunt
DISTVERSIONPREFIX=	v
DISTVERSION=	0.54.12
CATEGORIES=	sysutils

MAINTAINER=	nulldutra@proton.me
COMMENT=	Terragrunt is a thin wrapper for Terraform
WWW=		https://terragrunt.gruntwork.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	terraform:sysutils/terraform

USES=		go:modules

GO_MODULE=	github.com/gruntwork-io/terragrunt

GO_BUILDFLAGS=	-ldflags="-X main.VERSION=v${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
