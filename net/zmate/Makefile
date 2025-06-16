PORTNAME=	zmate
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.1
CATEGORIES=	net

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Instant terminal sharing using Zellij
WWW=		https://github.com/ziinaio/zmate

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	zellij:sysutils/zellij

USES=		go:1.24,modules

GO_MODULE=	github.com/ziinaio/zmate

PLIST_FILES=	bin/zmate

.include <bsd.port.mk>
