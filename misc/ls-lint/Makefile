PORTNAME=	ls-lint
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.1
PORTREVISION=	1
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Directory and filename linter
WWW=		https://ls-lint.org/ \
		https://github.com/loeffel-io/ls-lint

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24,modules

GO_MODULE=	github.com/loeffel-io/ls-lint/v2
GO_TARGET=	./cmd/ls_lint

PLIST_FILES=	bin/ls_lint

.include <bsd.port.mk>
