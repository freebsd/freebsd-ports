PORTNAME=	nnn
DISTVERSIONPREFIX=	v
DISTVERSION=	5.2
CATEGORIES=	misc shells
MASTER_SITES=	https://github.com/jarun/${PORTNAME}/releases/download/${DISTVERSIONFULL}/

MAINTAINER=	thindil@laeran.pl.eu.org
COMMENT=	Missing terminal file browser for X
WWW=		https://github.com/jarun/nnn

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	gsed:textproc/gsed

USES=		compiler:c11 gmake localbase ncurses readline

MAKE_ARGS=	CFLAGS_OPTIMIZATION= \
		LDLIBS_CURSES=-lncursesw \
		MANPREFIX=${PREFIX}/share/man \
		PKG_CONFIG=/usr/bin/true
INSTALL_TARGET=	strip install

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

PLIST_FILES=	bin/nnn \
		etc/bash_completion.d/nnn-completion.bash \
		share/fish/completions/nnn.fish \
		share/man/man1/nnn.1.gz \
		share/zsh/site-functions/_nnn

PORTDOCS=	README.md
PORTEXAMPLES=	*

OPTIONS_DEFINE=		ATOOL DOCS EXAMPLES MEDIAINFO XDG
OPTIONS_DEFAULT=	ATOOL MEDIAINFO XDG

ATOOL_DESC=	List and extract archives
MEDIAINFO_DESC=	Show media information
XDG_DESC=	Open files with xdg-open

ATOOL_RUN_DEPENDS=	atool:archivers/atool
MEDIAINFO_RUN_DEPENDS=	mediainfo:multimedia/mediainfo
XDG_RUN_DEPENDS=	xdg-open:devel/xdg-utils

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d \
		  ${STAGEDIR}${PREFIX}/share/fish/completions \
		  ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/misc/auto-completion/bash/nnn-completion.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/misc/auto-completion/fish/nnn.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/misc/auto-completion/zsh/_nnn \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	cd ${WRKSRC}/misc && ${COPYTREE_SHARE} "natool quitcd" \
		${STAGEDIR}${EXAMPLESDIR}/scripts
	cd ${WRKSRC} && ${COPYTREE_SHARE} plugins ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
