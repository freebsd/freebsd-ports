PORTNAME=	headscale
DISTVERSIONPREFIX=	v
DISTVERSION=	0.27.1
PORTREVISION=	1
CATEGORIES=	security net-vpn

MAINTAINER=	m.muenz@gmail.com
COMMENT=	Mesh VPN that makes it easy to connect your devices
WWW=		https://github.com/juanfont/headscale

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv6=	fails to compile: modernc.org/libc
BROKEN_armv7=	fails to compile: modernc.org/libc

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	version 0.27 removed i386 support

RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss

USES=		go:1.25,modules
USE_RC_SUBR=	${PORTNAME}

GO_MODULE=	github.com/juanfont/headscale

GO_TARGET=	./cmd/headscale

PLIST_FILES=	"@sample ${ETCDIR}/config.yaml.sample" \
		"@dir /var/cache/${PORTNAME}" \
		"@dir /var/db/${PORTNAME}" \
		bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/headscale|${ETCDIR}|g' \
		${WRKSRC}/cmd/headscale/cli/dump_config.go \
		${WRKSRC}/cmd/headscale/cli/root.go \
		${WRKSRC}/integration/hsic/hsic.go
	@${REINPLACE_CMD} -e 's|/var/lib/headscale/db.sqlite|/var/db/${PORTNAME}/db.sqlite|g' \
		${WRKSRC}/config-example.yaml

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR} \
		 ${STAGEDIR}/var/cache/${PORTNAME} \
		 ${STAGEDIR}/var/db/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/config-example.yaml ${STAGEDIR}${ETCDIR}/config.yaml.sample

.include <bsd.port.mk>
