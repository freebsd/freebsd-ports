# Created by: Sascha Holzleiter <sascha@root-login.org>
# $FreeBSD$

PORTNAME=	fzf
PORTVERSION=	0.15.8
CATEGORIES=	textproc

MAINTAINER=	sascha@root-login.org
COMMENT=	Blazing fast command-line fuzzy finder

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler go ncurses

USE_GITHUB=	yes
GH_ACCOUNT=	junegunn
GH_SUBDIR:=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

GH_TUPLE=	junegunn:go-runewidth:63c378b:runwidth/src/github.com/junegunn/go-runewidth \
    		junegunn:go-shellwords:35d512a:shellwords/src/github.com/junegunn/go-shellwords \
		junegunn:go-isatty:66b8e73:isatty/src/github.com/junegunn/go-isatty
MAKE_ENV+=	CGO_CPPFLAGS="-I${NCURSESINC} -I${NCURSESBASE}/include" \
		CGO_LDFLAGS="-L${NCURSESLIB}"

PLIST_FILES=	bin/fzf man/man1/fzf.1.gz

STRIP=		# do not strip go binaries

OPTIONS_DEFINE=	TMUX
TMUX_DESC=	Install fzf-tmux (depends on BASH)

OPTIONS_DEFAULT=	TMUX

TMUX_RUN_DEPENDS=	bash:shells/bash
TMUX_PLIST_FILES=	bin/fzf-tmux man/man1/fzf-tmux.1.gz

do-build:
	(cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/src/fzf && \
		${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} \
		go build -o bin/${PORTNAME})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/src/${PORTNAME}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

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
