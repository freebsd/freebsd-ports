PORTNAME=	fzf
DISTVERSIONPREFIX=	v
DISTVERSION=	0.65.0
CATEGORIES=	textproc
MASTER_SITES=	https://raw.githubusercontent.com/${GH_ACCOUNT}/${GH_PROJECT}/${DISTVERSIONFULL}/:gomod
DISTFILES=	go.mod:gomod

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Blazing fast command-line fuzzy finder
WWW=		https://github.com/junegunn/fzf/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	junegunn
GH_PROJECT=	fzf

GO_MODULE=	github.com/junegunn/fzf
GO_BUILDFLAGS=	-ldflags="-X main.version=${DISTVERSION} -X main.revision=${COMMIT_ID} -s -w"

COMMIT_ID=	04c4269

PLIST_FILES=	bin/fzf share/man/man1/fzf.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/man1/fzf.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
