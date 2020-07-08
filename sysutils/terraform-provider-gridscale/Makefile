# $FreeBSD$

PORTNAME=	terraform-provider-gridscale
PORTVERSION=	1.6.2
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Terraform provider for gridscale

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	terraform:sysutils/terraform

USES=		go:modules
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
USE_GITHUB=	yes
GH_ACCOUNT=	terraform-providers

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
