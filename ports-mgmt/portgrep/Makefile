PORTNAME=	portgrep
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
PORTREVISION=	3
CATEGORIES=	ports-mgmt

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Parallel port search utility

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/dmgk/portgrep
GO_BUILDFLAGS=	-ldflags="-s -w -X main.version=${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
