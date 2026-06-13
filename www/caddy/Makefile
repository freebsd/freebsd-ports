PORTNAME=	caddy
DISTVERSIONPREFIX=	v
DISTVERSION=	2.11.4
CATEGORIES=	www
DIST_SUBDIR=	caddy

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Fast, highly configurable HTTP/1-2-3 web server with automatic TLS
WWW=		https://caddyserver.com

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:1.25+,modules
CPE_VENDOR=	caddyserver
USE_RC_SUBR=	caddy

GO_MODULE=	github.com/caddyserver/caddy/v2
GO_TARGET=	./cmd/caddy
GO_BUILDFLAGS+=	-ldflags='-X github.com/caddyserver/caddy/v2.CustomVersion=${DISTVERSIONFULL}'

CONFLICTS_INSTALL=	caddy-custom
SUB_FILES=	Caddyfile.sample caddy pkg-message

USERS=		www
GROUPS=		www

PLIST_FILES=	bin/${PORTNAME} \
		"@sample ${ETCDIR_REL}/Caddyfile.sample"

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/Caddyfile.sample ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
