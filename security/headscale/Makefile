PORTNAME=	headscale
PORTVERSION=	0.16.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	m.muenz@gmail.com
COMMENT=	Mesh VPN that makes it easy to connect your devices

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	fails to compile: github.com/puzpuzpuz/xsync/issues/38
BROKEN_aarch64=	fails to compile: modernc.org/libc
BROKEN_armv6=	fails to compile: modernc.org/libc
BROKEN_armv7=	fails to compile: modernc.org/libc

RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss

USES=		go:modules
USE_RC_SUBR=	headscale

GO_MODULE=	github.com/juanfont/headscale

GO_TARGET=	./cmd/headscale

PLIST_FILES=	${ETCDIR}/config.yaml \
		"@dir /var/cache/${PORTNAME}" \
		"@dir /var/db/${PORTNAME}" \
		bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/headscale|${PREFIX}/etc/${PORTNAME}|g' \
		${WRKSRC}/cmd/headscale/cli/utils.go
	@${REINPLACE_CMD} -e 's|/var/lib/headscale/db.sqlite|/var/db/${PORTNAME}/db.sqlite|g' \
		${WRKSRC}/config-example.yaml
	@${REINPLACE_CMD} -e 's|/var/lib/headscale/cache|/var/cache/${PORTNAME}|g' \
		${WRKSRC}/config-example.yaml
	@${REINPLACE_CMD} -e 's|/var/lib/headscale/private.key|${PREFIX}/etc/${PORTNAME}/private.key|g' \
		${WRKSRC}/config-example.yaml

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/config-example.yaml ${STAGEDIR}${PREFIX}/etc/${PORTNAME}/config.yaml
	${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}
	${MKDIR} ${STAGEDIR}/var/cache/${PORTNAME}

.include <bsd.port.mk>
