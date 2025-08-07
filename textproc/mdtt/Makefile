PORTNAME=	mdtt
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Terminal-based markdown table editor with vim-style keybindings
WWW=		https://github.com/szktkfm/mdtt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/szktkfm/mdtt
GO_TARGET=	./cmd/mdtt

PLIST_FILES=	bin/mdtt

.include <bsd.port.mk>
