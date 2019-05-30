# Created by: Sascha Holzleiter <sascha@root-login.org>
# $FreeBSD$

PORTNAME=	fzf
PORTVERSION=	0.18.0
CATEGORIES=	textproc

MAINTAINER=	sascha@root-login.org
COMMENT=	Blazing fast command-line fuzzy finder

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler go

USE_GITHUB=	yes
GH_ACCOUNT=	junegunn
GH_SUBDIR:=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

GH_TUPLE=	\
		gdamore:encoding:b23993cbb635:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:0a0db94084df:gdamore_tcell/vendor/github.com/gdamore/tcell \
		golang:crypto:c2843e01d9a2:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:d0b11bdaac8a:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.0:golang_text/vendor/golang.org/x/text \
		golang:tools:d850aa06e894:golang_tools/vendor/golang.org/x/tools \
		gopherjs:gopherjs:d547d1d9531e:gopherjs_gopherjs/vendor/github.com/gopherjs/gopherjs \
		jtolds:gls:v4.2.1:jtolds_gls/vendor/github.com/jtolds/gls \
		lucasb-eyer:go-colorful:c900de9dbbc7:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-isatty:66b8e73f3f5c:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:14207d285c6c:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-shellwords:v1.0.3:mattn_go_shellwords/vendor/github.com/mattn/go-shellwords \
		smartystreets:assertions:b2de0cb4f26d:smartystreets_assertions/vendor/github.com/smartystreets/assertions \
		smartystreets:goconvey:044398e4856c:smartystreets_goconvey/vendor/github.com/smartystreets/goconvey

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
