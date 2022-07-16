PORTNAME=	fallout
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.3
CATEGORIES=	ports-mgmt

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Download and search pkg-fallout logs

LICENSE=	BSD0CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/dmgk/fallout
GO_BUILDFLAGS=	-ldflags="-s -w -X main.version=${DISTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
