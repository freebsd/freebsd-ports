PORTNAME=	ciigo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18.1
CATEGORIES=	textproc

MAINTAINER=	hoanga@gmail.com
COMMENT=	CLI tool that can convert and generate HTML from asciidoc and Markdown
WWW=		https://sr.ht/~shulhan/ciigo

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		go:modules
GO_MODULE=	git.sr.ht/~shulhan/ciigo
GO_TARGET=	./cmd/ciigo
GO_BUILDFLAGS=	-ldflags "-s -w -X git.sr.ht/~shulhan/ciigo.Version=${DISTVERSIONFULL}"

PLIST_FILES=	bin/ciigo

.include <bsd.port.mk>
