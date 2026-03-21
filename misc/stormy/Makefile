PORTNAME=	stormy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.3
PORTREVISION=	10
CATEGORIES=	misc

MAINTAINER=	nxjoseph@FreeBSD.org
COMMENT=	Minimal, customizable, and neofetch-like weather CLI
WWW=		https://terminaltrove.com/stormy/ \
		https://github.com/ashish0kumar/stormy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/ashish0kumar/stormy
GO_BUILDFLAGS=	-ldflags="-s -w -X main.version=${DISTVERSIONFULL}"

PLIST_FILES=	bin/stormy

.include <bsd.port.mk>
