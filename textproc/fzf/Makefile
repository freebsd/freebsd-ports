# Created by: Sascha Holzleiter <sascha@root-login.org>
# $FreeBSD$

PORTNAME=	fzf
PORTVERSION=	0.13.4
CATEGORIES=	textproc

MAINTAINER=	sascha@root-login.org
COMMENT=	Blazing fast command-line fuzzy finder

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go-runewidth>0:devel/go-runewidth \
		go-shellwords>0:devel/go-shellwords

USES=		compiler go

USE_GITHUB=	yes
GH_ACCOUNT=	junegunn

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

GO_TARGET=	${GO_PKGNAME}/src/fzf

PLIST_FILES=	bin/fzf man/man1/fzf.1.gz

OPTIONS_DEFINE=	TMUX
TMUX_DESC=	Install fzf-tmux (depends on BASH)

OPTIONS_DEFAULT=	TMUX

TMUX_RUN_DEPENDS=	bash:shells/bash
TMUX_PLIST_FILES=	bin/fzf-tmux man/man1/fzf-tmux.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/man1/fzf.1 ${STAGEDIR}${MANPREFIX}/man/man1

post-install-TMUX-on:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME}-tmux ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/fzf-tmux.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.pre.mk>

# If cc is clang, change it to clang to help Go identify the compiler,
# else we get -pthread warnings
.if ${COMPILER_TYPE} == "clang" && ${CC} == "cc"
CC=clang
.endif

.include <bsd.port.post.mk>
