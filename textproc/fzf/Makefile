PORTNAME=	fzf
DISTVERSIONPREFIX=	v
DISTVERSION=	0.73.1
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Blazing fast command-line fuzzy finder
WWW=		https://github.com/junegunn/fzf/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/junegunn/fzf
GO_BUILDFLAGS=	-ldflags="-X main.version=${DISTVERSION} -X main.revision=${COMMIT_ID} -s -w"

COMMIT_ID=	ce4bef7

PLIST_FILES=	bin/fzf share/man/man1/fzf.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/man1/fzf.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
