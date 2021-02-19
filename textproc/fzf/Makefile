# Created by: Sascha Holzleiter <sascha@root-login.org>
# $FreeBSD$

PORTNAME=	fzf
PORTVERSION=	0.25.1
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Blazing fast command-line fuzzy finder

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

# go get -d github.com/junegunn/fzf@$(make -V PORTVERSION)
GO_MODULE=	github.com/junegunn/fzf@v0.0.0-20210203133252-6654239c9466
GO_BUILDFLAGS=	-ldflags="-X main.revision=${COMMIT_ID} -s -w"

COMMIT_ID=	6654239

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
