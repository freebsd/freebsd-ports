PORTNAME=	terragrunt
DISTVERSIONPREFIX=	v
DISTVERSION=	0.81.1
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	Terragrunt is a thin wrapper for Terraform
WWW=		https://terragrunt.gruntwork.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	terraform:sysutils/terraform

USES=		go:1.24,modules

GO_MODULE=	github.com/gruntwork-io/terragrunt

GO_BUILDFLAGS=	-ldflags="-X main.VERSION=v${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
