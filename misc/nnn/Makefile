# $FreeBSD$

PORTNAME=	nnn
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3
CATEGORIES=	misc shells

MAINTAINER=	dg@syrec.org
COMMENT=	Missing terminal file browser for X

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake localbase ncurses readline
USE_GITHUB=	yes
GH_ACCOUNT=	jarun

MAKE_ARGS=	PREFIX=${PREFIX} MANPREFIX=${PREFIX}/man LDLIBS_CURSES=-lncursesw
CFLAGS+=	-D_WITH_DPRINTF # enable dprintf prototype

OPTIONS_DEFINE=	ATOOL DOCS EXAMPLES MEDIAINFO XDG
OPTIONS_DEFAULT=	ATOOL MEDIAINFO XDG
ATOOL_DESC=	List and extract archives
XDG_DESC=	Open files with xdg-open
MEDIAINFO_DESC=	Show media information

ATOOL_RUN_DEPENDS=	atool:archivers/atool
MEDIAINFO_RUN_DEPENDS=	mediainfo:multimedia/mediainfo
XDG_RUN_DEPENDS=	xdg-open:devel/xdg-utils

PLIST_FILES=	bin/nnn \
		man/man1/nnn.1.gz \
		etc/bash_completion.d/nnn-completion.bash \
		share/fish/completions/nnn.fish \
		share/zsh/site-functions/_nnn

PORTDOCS=	README.md
PORTEXAMPLES=	*

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/nnn
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/scripts/auto-completion/bash/nnn-completion.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/scripts/auto-completion/fish/nnn.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/scripts/auto-completion/zsh/_nnn \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/scripts && ${COPYTREE_SHARE} "quitcd natool nlay" \
		${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} user-scripts ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
