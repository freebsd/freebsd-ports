PORTNAME=	tflint
DISTVERSIONPREFIX=	v
DISTVERSION=	0.51.1
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	Terraform Linter
WWW=		https://github.com/terraform-linters/tflint

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.21,modules

GO_MODULE=	github.com/terraform-linters/tflint

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
