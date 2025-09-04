PORTNAME=	terraform-provider-gridscale
PORTVERSION=	1.6.2
DISTVERSIONPREFIX=	v
PORTREVISION=	30
CATEGORIES=	sysutils

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Terraform provider for gridscale
WWW=		https://github.com/terraform-providers/terraform-provider-gridscale

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	terraform:sysutils/terraform

USES=		go:modules
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
USE_GITHUB=	yes
GH_ACCOUNT=	terraform-providers
GH_TUPLE=	golang:sys:v0.6.0:sys

PLIST_FILES=	bin/${PORTNAME}

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

.include <bsd.port.mk>
