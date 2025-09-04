PORTNAME=	terraform-provider-vultr
PORTVERSION=	0.1.10
DISTVERSIONPREFIX=	v
PORTREVISION=	30
CATEGORIES=	sysutils

MAINTAINER=	zachary.crownover@gmail.com
COMMENT=	Terraform provider for Vultr
WWW=		https://github.com/squat/terraform-provider-vultr

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	terraform:sysutils/terraform

USES=		go
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
USE_GITHUB=	yes
GH_ACCOUNT=	squat

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
