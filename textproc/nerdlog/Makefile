PORTNAME=	nerdlog
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.0
PORTREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Fast, multi-host TUI log viewer with timeline histogram
WWW=		https://dmitryfrank.com/projects/nerdlog/article

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	gawk:lang/gawk

USES=		go:modules

GO_MODULE=	github.com/dimonomid/nerdlog
GO_TARGET=	./cmd/nerdlog

PLIST_FILES=	bin/nerdlog

.include <bsd.port.mk>
