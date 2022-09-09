PORTNAME=	portgrep
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
PORTREVISION=	4
CATEGORIES=	ports-mgmt

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Parallel port search utility
WWW=		https://github.com/dmgk/portgrep

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/dmgk/portgrep
GO_BUILDFLAGS=	-ldflags="-s -w -X main.version=${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
