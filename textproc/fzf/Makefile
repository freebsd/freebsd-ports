# Created by: Sascha Holzleiter <sascha@root-login.org>
# $FreeBSD$

PORTNAME=	fzf
PORTVERSION=	0.17.3
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	sascha@root-login.org
COMMENT=	Blazing fast command-line fuzzy finder

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler go

USE_GITHUB=	yes
GH_ACCOUNT=	junegunn
GH_SUBDIR:=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

GH_TUPLE=	lucasb-eyer:go-colorful:c900de9:colorful/src/github.com/lucasb-eyer/go-colorful \
		mattn:go-runewidth:14207d2:runewidth/src/github.com/mattn/go-runewidth \
		mattn:go-shellwords:02e3cf0:shellwords/src/github.com/mattn/go-shellwords \
		mattn:go-isatty:66b8e73:isatty/src/github.com/mattn/go-isatty \
		gdamore:encoding:b23993c:encoding/src/github.com/gdamore/encoding \
		gdamore:tcell:44772c1:tcell/src/github.com/gdamore/tcell \
		golang:sys:b90f89a:sys/src/golang.org/x/sys \
		golang:text:4ee4af5:text/src/golang.org/x/text \
		golang:crypto:e1a4589:crypto/src/golang.org/x/crypto

SUB_FILES=	pkg-message
PLIST_FILES=	bin/fzf man/man1/fzf.1.gz
PORTEXAMPLES=	shell/completion.bash shell/completion.zsh \
		shell/key-bindings.bash shell/key-bindings.fish \
		shell/key-bindings.zsh

OPTIONS_DEFINE=		EXAMPLES TMUX
OPTIONS_DEFAULT=	TMUX

TMUX_DESC=	Install fzf-tmux (depends on BASH)

TMUX_RUN_DEPENDS=	bash:shells/bash
TMUX_PLIST_FILES=	bin/fzf-tmux man/man1/fzf-tmux.1.gz

GOENV=		GOPATH=${WRKSRC} CGO_CFLAGS="${CGO_CFLAGS}" \
		CGO_LDFLAGS="${CGO_LDFLAGS}" GOBIN=""

do-build:
	cd ${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME} && \
	${SETENV} ${MAKE_ENV} ${GOENV} ${GO_CMD} build -a \
		-ldflags "-X main.revision=0b33dc6 -w" -o bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && \
	    ${COPYTREE_SHARE} shell ${STAGEDIR}${EXAMPLESDIR})

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
