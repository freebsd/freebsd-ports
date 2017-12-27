# $FreeBSD$

PORTNAME=	nnn
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6
CATEGORIES=	misc shells

MAINTAINER=	dg@syrec.org
COMMENT=	Missing terminal file browser for X

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash \
		xdg-open:devel/xdg-utils

USES=		gmake localbase ncurses readline shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	jarun
SHEBANG_FILES=	nlay

MAKE_ARGS=	PREFIX=${PREFIX} MANPREFIX=${PREFIX}/man
CFLAGS+=	-D_WITH_DPRINTF # enable dprintf prototype

OPTIONS_DEFINE=	ATOOL BASH DOCS EXAMPLES FISH MEDIAINFO ZSH
OPTIONS_DEFAULT=	ATOOL MEDIAINFO
ATOOL_DESC=	List and extract archives
MEDIAINFO_DESC=	Show media information

ATOOL_RUN_DEPENDS=	atool:archivers/atool
MEDIAINFO_RUN_DEPENDS=	mediainfo:multimedia/mediainfo

BASH_PLIST_FILES=	etc/bash_completion.d/nnn-completion.bash
FISH_PLIST_FILES=	share/fish/completions/nnn.fish
ZSH_PLIST_FILES=	share/zsh/site-functions/_nnn

PLIST_FILES=	bin/nnn \
		bin/nlay \
		man/man1/nnn.1.gz

PORTDOCS=	README.md
PORTEXAMPLES=	*

post-install-BASH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/scripts/auto-completion/bash/nnn-completion.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/scripts && ${COPYTREE_SHARE} "copier quitcd" ${STAGEDIR}${EXAMPLESDIR}

post-install-FISH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/scripts/auto-completion/fish/nnn.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions

post-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/scripts/auto-completion/zsh/_nnn \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

.include <bsd.port.mk>
