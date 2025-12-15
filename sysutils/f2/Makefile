PORTNAME=	f2
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.2
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Command-line tool for batch renaming files and directories
WWW=		https://f2.freshman.tech/ \
		https://github.com/ayoisaiah/f2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		go:1.25+,modules

GO_MODULE=	github.com/ayoisaiah/f2/v2
GO_TARGET=	./cmd/f2

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
