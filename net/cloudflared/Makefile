PORTNAME=	cloudflared
DISTVERSION=	2025.8.0
CATEGORIES=	net www

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Cloudflare's Argo Tunnel client
WWW=		https://developers.cloudflare.com/argo-tunnel/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		cpe go:modules
USE_RC_SUBR=	${PORTNAME}
USE_GITHUB=	yes
GH_ACCOUNT=	cloudflare
CPE_VENDOR=	cloudflare

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	${GO_PKGNAME}/cmd/cloudflared
GO_BUILDFLAGS=	-ldflags '-s -w -extldflags "-static" -X main.Version=${PORTVERSION}'

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
