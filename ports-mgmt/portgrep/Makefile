PORTNAME=	portgrep
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	ports-mgmt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Parallel port search utility
WWW=		https://github.com/alexdupre/portgrep

LICENSE=	BSD0CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/alexdupre/portgrep
GO_BUILDFLAGS=	-ldflags="-s -w -X main.version=${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
