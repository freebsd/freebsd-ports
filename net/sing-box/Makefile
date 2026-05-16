PORTNAME=	sing-box
DISTVERSIONPREFIX=	v
DISTVERSION=	1.13.12
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Universal proxy platform
WWW=		https://sing-box.sagernet.org \
		https://github.com/SagerNet/sing-box

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24+,modules

GO_MODULE=	github.com/sagernet/sing-box
GO_TARGET=	./cmd/sing-box

PLIST_FILES=	bin/${PORTNAME} \
		"@sample etc/sing-box.json.sample"

USE_RC_SUBR=	${PORTNAME}

OPTIONS_DEFINE=		QUIC GRPC DHCP WIREGUARD UTLS ACME CLASH_API V2RAY_API GVISOR EMBEDDED_TOR CCM OCM 
OPTIONS_DEFAULT=	QUIC UTLS

QUIC_DESC=		Build with QUIC support
GRPC_DESC=		Build with standard gRPC support
DHCP_DESC=		Build with DHCP support
WIREGUARD_DESC=		Build with WireGuard support
UTLS_DESC=		Build with uTLS support for TLS outbound
ACME_DESC=		Build with ACME TLS issuer support
CLASH_API_DESC=		Build with Clash API support
V2RAY_API_DESC=		Build with V2Ray API support
GVISOR_DESC=		Build with gVisor support
EMBEDDED_TOR_DESC=	Build with embedded Tor support
CCM_DESC=		Build with Claude Code Multiplexer service support
OCM_DESC=		Build with OpenAI Codex Multiplexer service support

QUIC_VARS=		GO_TAGS+=with_quic
GRPC_VARS=		GO_TAGS+=with_grpc
DHCP_VARS=		GO_TAGS+=with_dhcp
WIREGUARD_VARS=		GO_TAGS+=with_wireguard
UTLS_VARS=		GO_TAGS+=with_utls
ACME_VARS=		GO_TAGS+=with_acme
CLASH_API_VARS=		GO_TAGS+=with_clash_api
V2RAY_API_VARS=		GO_TAGS+=with_v2ray_api
GVISOR_VARS=		GO_TAGS+=with_gvisor
EMBEDDED_TOR_VARS=	GO_TAGS+=with_embedded_tor CGO_ENABLED=1
CCM_VARS=		GO_TAGS+=with_ccm
OCM_VARS=		GO_TAGS+=with_ocm

.include <bsd.port.pre.mk>
.if !empty (GO_TAGS)
GO_BUILDFLAGS+=	-tags "${GO_TAGS}"
.endif

post-install:
	# install default config file
	${INSTALL_DATA} ${FILESDIR}/sing-box.json ${STAGEDIR}${PREFIX}/etc/sing-box.json.sample

.include <bsd.port.post.mk>
