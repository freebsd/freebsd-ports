# Created by: Sascha Holzleiter <sascha@root-login.org>
# $FreeBSD$

PORTNAME=	fzf
PORTVERSION=	0.19.0
CATEGORIES=	textproc

MAINTAINER=	sascha@root-login.org
COMMENT=	Blazing fast command-line fuzzy finder

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	junegunn
GH_TUPLE=	\
		gdamore:encoding:b23993cbb635:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:0a0db94084df:gdamore_tcell/vendor/github.com/gdamore/tcell \
		golang:crypto:558b6879de74:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:a5b02f93d862:golang_sys/vendor/golang.org/x/sys \
		golang:text:4ee4af566555:golang_text/vendor/golang.org/x/text \
		lucasb-eyer:go-colorful:c900de9dbbc7:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-isatty:66b8e73f3f5c:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:14207d285c6c:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-shellwords:v1.0.3:mattn_go_shellwords/vendor/github.com/mattn/go-shellwords

GO_BUILDFLAGS=	-ldflags="-X main.revision=9a41fd5 -w"

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

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/man1/fzf.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && \
	    ${COPYTREE_SHARE} shell ${STAGEDIR}${EXAMPLESDIR})

post-install-TMUX-on:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME}-tmux ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/fzf-tmux.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
