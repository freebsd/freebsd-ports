PORTNAME=	qo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.7
PORTREVISION=	3
CATEGORIES=	textproc

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	TUI to query JSON/CSV/TSV with SQL
WWW=		https://github.com/kiki-ki/go-qo

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	module modernc.org/sqlite only supported on aarch64 and amd64

USES=		go:1.25+,modules
GO_MODULE=	github.com/kiki-ki/go-qo
GO_TARGET=	./cmd/qo

PLIST_FILES=	bin/qo

.include <bsd.port.mk>
