PORTNAME=	f2
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.1
PORTREVISION=	9
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Command-line tool for batch renaming files and directories
WWW=		https://github.com/ayoisaiah/f2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		go:modules

GO_MODULE=	github.com/ayoisaiah/f2
GO_TARGET=	./cmd/f2

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
