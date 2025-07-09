PORTNAME=	xcaddy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.4
PORTREVISION=	2
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

post-patch:
	${REINPLACE_CMD} 's,return "go",return "${GO_CMD}",g' \
		${WRKSRC}/internal/utils/environment.go

.include <bsd.port.mk>
