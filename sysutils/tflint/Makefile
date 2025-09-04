PORTNAME=	tflint
DISTVERSIONPREFIX=	v
DISTVERSION=	0.58.0
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	Terraform Linter
WWW=		https://github.com/terraform-linters/tflint

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24,modules

GO_MODULE=	github.com/terraform-linters/tflint

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
