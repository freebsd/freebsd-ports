PORTNAME=	caddy
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.2
PORTREVISION=	1
CATEGORIES=	www
DIST_SUBDIR=	caddy

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Fast, cross-platform HTTP/2 web server with automatic HTTPS

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules
CPE_VENDOR=	caddyserver

USE_RC_SUBR=	caddy
SUB_FILES=	Caddyfile.sample caddy pkg-message

PLIST_FILES=	bin/${PORTNAME} \
		"@sample ${ETCDIR_REL}/Caddyfile.sample"

GO_TARGET=	./cmd/caddy
# If go.mod is sufficient:
GO_MODULE=	github.com/caddyserver/caddy/v2
# If modules must be specified manually:
# .include "${.CURDIR}/modules.mk"

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/Caddyfile.sample ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
