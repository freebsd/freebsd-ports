PORTNAME=	fallout
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.4
PORTREVISION=	25
CATEGORIES=	ports-mgmt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Download and search pkg-fallout logs
WWW=		https://github.com/dmgk/fallout

LICENSE=	BSD0CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/dmgk/fallout
GO_BUILDFLAGS=	-ldflags="-s -w -X main.version=${DISTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
