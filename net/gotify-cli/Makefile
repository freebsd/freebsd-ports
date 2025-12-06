PORTNAME=	gotify
PORTVERSION=	2.3.2
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	net
PKGNAMESUFFIX=	-cli
DISTNAME=	cli

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	CLI to send message to gotify server
WWW=		https://github.com/gotify/cli

LICENSE=	MIT

USES=		go:modules
GO_MODULE=	github.com/gotify/cli/v2

_BUILD_DATE=	$$(date -u "+%Y-%m-%d-%H%M UTC")
#GO_TARGET=     ./
GO_BUILDFLAGS=	-buildmode=pie -modcacherw \
		-ldflags=" \
		-X 'main.Version=${PORTVERSION}' \
		-X 'main.Commit=${GL_TAGNAME:C/^(........).*/\1/}' \
		-X 'main.BuildDate=${_BUILD_DATE}'"

PLIST_FILES=	bin/gotify

.include <bsd.port.mk>
