PORTNAME=	cloudflared
DISTVERSION=	2026.10.7
CATEGORIES=	net www

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Cloudflare's Argo Tunnel client
WWW=		https://developers.cloudflare.com/argo-tunnel/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		cpe go:1.27+,modules
CPE_VENDOR=	cloudflare
USE_GITHUB=	yes
GH_ACCOUNT=	cloudflare
USE_RC_SUBR=	${PORTNAME}

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	${GO_PKGNAME}/cmd/cloudflared
GO_BUILDFLAGS=	-ldflags '-s -w -extldflags "-static" -X main.Version=${PORTVERSION}'

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${MKDIR} ${WRKSRC}/vendor && ${CP} ${FILESDIR}/modules.txt ${WRKSRC}/vendor

.include "Makefile.gomod"
.include <bsd.port.mk>
