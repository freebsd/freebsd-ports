# Created by: Gabriel M. Dutra <0xdutra@gmail.com>

PORTNAME=	terragrunt
DISTVERSIONPREFIX=	v
DISTVERSION=	0.38.1
CATEGORIES=	sysutils

MAINTAINER=	0xdutra@gmail.com
COMMENT=	Terragrunt is a thin wrapper for Terraform

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	terraform:sysutils/terraform

USES=		go:modules

GO_MODULE=	github.com/gruntwork-io/terragrunt

GO_BUILDFLAGS=	-ldflags="-X main.VERSION=v${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
