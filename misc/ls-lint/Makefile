PORTNAME=	ls-lint
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.3
PORTREVISION=	5
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Directory and filename linter
WWW=		https://ls-lint.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.22,modules

GO_MODULE=	github.com/loeffel-io/ls-lint/v2
GO_TARGET=	./cmd/ls_lint

PLIST_FILES=	bin/ls_lint

.include <bsd.port.mk>
