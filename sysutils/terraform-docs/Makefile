PORTNAME=	terraform-docs
DISTVERSIONPREFIX=	v
DISTVERSION=	0.20.0
PORTREVISION=	5
CATEGORIES=	sysutils textproc

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	Generate documentation from Terraform modules
WWW=		https://github.com/terraform-docs/terraform-docs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24,modules
GO_MODULE=	github.com/terraform-docs/terraform-docs

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
