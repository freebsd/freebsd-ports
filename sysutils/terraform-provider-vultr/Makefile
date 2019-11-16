# $FreeBSD$

PORTNAME=	terraform-provider-vultr
PORTVERSION=	0.1.10
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Terraform provider for Vultr

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	terraform:sysutils/terraform

USES=		go
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
USE_GITHUB=	yes
GH_ACCOUNT=	squat

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
