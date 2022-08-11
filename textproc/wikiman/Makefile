PORTNAME=	wikiman
DISTVERSION=	2.12.2
CATEGORIES=	textproc

MAINTAINER=	filip@parag.rs
COMMENT=	Offline interactive documentation search

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	findutils>4:misc/findutils \
		fzf>0.2:textproc/fzf \
		gawk>5:lang/gawk \
		ripgrep>12:textproc/ripgrep \
		w3m>0.5:www/w3m

USE_GITHUB=	yes
GH_ACCOUNT=	filiparag

NO_ARCH=	yes

OPTIONS_DEFINE=		BASH CONFIG DOCS FISH WDGTS ZSH
OPTIONS_DEFAULT=	BASH CONFIG DOCS FISH WDGTS ZSH
OPTIONS_SUB=		yes
CONFIG_DESC=		Global configuration file
WDGTS_DESC=		Shell keybind widgets
BASH_PLIST_FILES=	etc/bash_completion.d/wikiman-completion.bash
FISH_PLIST_FILES=	share/fish/completions/wikiman.fish
ZSH_PLIST_FILES=	share/zsh/site-functions/_wikiman

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/wikiman.sh ${STAGEDIR}${PREFIX}/bin/wikiman

	@${MKDIR} ${STAGEDIR}${DATADIR}/sources
	(cd ${WRKSRC}/sources && ${COPYTREE_BIN} . ${STAGEDIR}${DATADIR}/sources)

	${INSTALL_MAN} ${WRKSRC}/wikiman.1.man ${STAGEDIR}${MANPREFIX}/share/man/man1/wikiman.1

do-install-BASH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/completions/completions.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/wikiman-completion.bash

do-install-CONFIG-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/wikiman.conf ${STAGEDIR}${PREFIX}/etc/wikiman.conf.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

do-install-FISH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/completions/completions.fish ${STAGEDIR}${PREFIX}/share/fish/completions/wikiman.fish

do-install-WDGTS-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/widgets
	(cd ${WRKSRC}/widgets && ${COPYTREE_BIN} . ${STAGEDIR}${DATADIR}/widgets)

do-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completions/completions.zsh ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_wikiman

.include <bsd.port.mk>
