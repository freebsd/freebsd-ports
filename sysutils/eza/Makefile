PORTNAME=	eza
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18.18
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Modern, maintained replacement for ls
WWW=		https://eza.rocks/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	eza-community

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	MANPAGES
OPTIONS_GROUP=	COMPLETIONS
OPTIONS_GROUP_COMPLETIONS=	BASH FISH ZSH

BASH_PLIST_FILES=	etc/bash_completion.d/${PORTNAME}.bash
FISH_PLIST_FILES=	share/fish/completions/${PORTNAME}.fish
ZSH_PLIST_FILES=	share/zsh/site-functions/_${PORTNAME}

MANPAGES_BUILD_DEPENDS=	pandoc:textproc/hs-pandoc

_MARKDOWN_FILES=	eza.1 eza_colors-explanation.5 eza_colors.5
.for i in ${_MARKDOWN_FILES}
MANPAGES_PLIST_FILES+=	share/man/man${i:C/.*\.//}/${i}.gz
.endfor

post-build-MANPAGES-on:
.for i in ${_MARKDOWN_FILES}
	cd ${WRKSRC}/man && \
		pandoc ${i}.md -s -t man > ${i}
.endfor

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-BASH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/completions/bash/${PORTNAME} ${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}.bash

post-install-FISH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/completions/fish/${PORTNAME}.fish ${STAGEDIR}${PREFIX}/share/fish/completions/${PORTNAME}.fish

post-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completions/zsh/_${PORTNAME} ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

post-install-MANPAGES-on:
.for i in ${_MARKDOWN_FILES}
	${INSTALL_MAN} ${WRKSRC}/man/${i} ${STAGEDIR}${PREFIX}/share/man/man${i:C/.*\.//}
.endfor

.include <bsd.port.mk>
