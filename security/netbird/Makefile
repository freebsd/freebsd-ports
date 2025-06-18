PORTNAME=	netbird
DISTVERSIONPREFIX=	v
DISTVERSION=	0.47.2
CATEGORIES=	security net net-vpn

MAINTAINER=	hakan.external@netbird.io
COMMENT=	Peer-to-peer VPN that seamlessly connects your devices
WWW=		https://netbird.io/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	"no 32-bit builds supported"

RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss

USES=		go:modules
USE_RC_SUBR=	netbird

GO_MODULE=	github.com/netbirdio/netbird
GO_TARGET=	./client:netbird
GO_BUILDFLAGS=	-tags freebsd -o ${PORTNAME} -ldflags \
		"-s -w -X github.com/netbirdio/netbird/version.version=${DISTVERSION}"

WRKSRC=		${WRKDIR}/netbird-${DISTVERSION}

PLIST_FILES=	bin/netbird

.include <bsd.port.mk>
