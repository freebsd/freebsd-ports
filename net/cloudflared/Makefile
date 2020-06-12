# $FreeBSD$

PORTNAME=	cloudflared
DISTVERSION=	2020.6.1
CATEGORIES=	net www

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Cloudflare's Argo Tunnel client

LICENSE=	cloudflare
LICENSE_NAME=	cloudflare
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	no-dist-sell no-pkg-sell

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		cpe go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	cloudflare

CPE_VENDOR=	cloudflare

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	${GO_PKGNAME}/cmd/cloudflared
GO_BUILDFLAGS+=	-ldflags '-s -w -X main.Version=${PORTVERSION}'

PLIST_FILES=	bin/${PORTNAME}
RESTRICTED=	Not sure if we are allowed to redistribute it.

.include <bsd.port.mk>
