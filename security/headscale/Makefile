PORTNAME=	headscale
PORTVERSION=	0.26.1
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	security net-vpn

MAINTAINER=	m.muenz@gmail.com
COMMENT=	Mesh VPN that makes it easy to connect your devices
WWW=		https://github.com/juanfont/headscale

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv6=	fails to compile: modernc.org/libc
BROKEN_armv7=	fails to compile: modernc.org/libc

RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss

USES=		go:modules
USE_RC_SUBR=	headscale

GO_MODULE=	github.com/juanfont/headscale

GO_TARGET=	./cmd/headscale

PLIST_FILES=	"@sample ${ETCDIR}/config.yaml.sample" \
		"@dir /var/cache/${PORTNAME}" \
		"@dir /var/db/${PORTNAME}" \
		bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/headscale|${PREFIX}/etc/${PORTNAME}|g' \
		${WRKSRC}/cmd/headscale/cli/dump_config.go \
		${WRKSRC}/cmd/headscale/cli/root.go \
		${WRKSRC}/integration/hsic/hsic.go
	@${REINPLACE_CMD} -e 's|/var/lib/headscale/db.sqlite|/var/db/${PORTNAME}/db.sqlite|g' \
		${WRKSRC}/config-example.yaml

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/config-example.yaml ${STAGEDIR}${PREFIX}/etc/${PORTNAME}/config.yaml.sample
	${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}
	${MKDIR} ${STAGEDIR}/var/cache/${PORTNAME}

.include <bsd.port.mk>
