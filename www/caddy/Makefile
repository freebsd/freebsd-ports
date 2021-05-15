# Created by: fabian.freyer@physik.tu-berlin.de

PORTNAME=	caddy
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.0
CATEGORIES=	www
DIST_SUBDIR=	caddy

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Fast, cross-platform HTTP/2 web server with automatic HTTPS

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		go:modules
GO_MODULE=	github.com/caddyserver/caddy/v2
GO_TARGET=	./cmd/caddy

USE_RC_SUBR=	caddy
SUB_FILES=	Caddyfile.sample caddy pkg-message

PLIST_FILES=	bin/${PORTNAME} \
		"@sample ${ETCDIR_REL}/Caddyfile.sample"

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/Caddyfile.sample ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
