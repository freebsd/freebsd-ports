PORTNAME=	xcaddy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.4
CATEGORIES=	www
DIST_SUBDIR=	xcaddy

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Command line tool to make custom builds of the Caddy Web Server
WWW=		https://github.com/caddyserver/xcaddy

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules,run

GO_MODULE=	github.com/caddyserver/xcaddy
GO_TARGET=	./cmd/xcaddy

SUB_FILES=	pkg-message

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
