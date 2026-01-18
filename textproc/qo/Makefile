PORTNAME=	qo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
CATEGORIES=	textproc

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	TUI to query JSON/CSV/TSV with SQL
WWW=		https://github.com/kiki-ki/go-qo

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	vendor/modernc.org/libc/libc_freebsd.go:1638:17: invalid operation: Uint64(Uint64FromInt32(-1)) / uint64(255) * size_t(c) (mismatched types uint64 and size_t)

USES=		go:1.25+,modules
GO_MODULE=	github.com/kiki-ki/go-qo
GO_TARGET=	./cmd/qo

PLIST_FILES=	bin/qo

.include <bsd.port.mk>
