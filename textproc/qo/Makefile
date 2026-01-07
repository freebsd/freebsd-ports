PORTNAME=	qo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.7
CATEGORIES=	textproc

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	TUI to query JSON/CSV/TSV with SQL
WWW=		https://github.com/kiki-ki/go-qo

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.25+,modules
GO_MODULE=	github.com/kiki-ki/go-qo
GO_TARGET=	./cmd/qo

PLIST_FILES=	bin/qo

.include <bsd.port.mk>
