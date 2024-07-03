PORTNAME=	infracost
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.37
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	Cloud cost estimates for Terraform
WWW=		https://github.com/infracost/infracos

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	terraform:sysutils/terraform \
		terragrunt:sysutils/terragrunt

USES=		go:1.22,modules

GO_MODULE=	github.com/${PORTNAME}/${PORTNAME}

GO_BUILDFLAGS=	-ldflags="-X github.com/infracost/infracost/internal/version.Version=v${PORTVERSION}"
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
