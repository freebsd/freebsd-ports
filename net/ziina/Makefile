PORTNAME=	ziina
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.3
CATEGORIES=	net

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Instant terminal sharing using Zellij
WWW=		https://github.com/ziinaio/ziina

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	zellij:sysutils/zellij

USES=		go:1.24,modules

GO_MODULE=	github.com/ziinaio/ziina

PLIST_FILES=	bin/ziina

.include <bsd.port.mk>
