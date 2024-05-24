PORTNAME=	eza
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18.15
CATEGORIES=	sysutils

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Modern, maintained replacement for ls
WWW=		https://eza.rocks/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	eza-community

PLIST_FILES=	bin/${PORTNAME} \
		etc/bash_completion.d/${PORTNAME}.bash \
		share/fish/completions/${PORTNAME}.fish \
		share/zsh/site-functions/_${PORTNAME}

OPTIONS_DEFINE=	MANPAGES

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
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/completions/bash/${PORTNAME} ${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}.bash
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/completions/fish/${PORTNAME}.fish ${STAGEDIR}${PREFIX}/share/fish/completions/${PORTNAME}.fish
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completions/zsh/_${PORTNAME} ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-MANPAGES-on:
.for i in ${_MARKDOWN_FILES}
	${INSTALL_MAN} ${WRKSRC}/man/${i} ${STAGEDIR}${PREFIX}/share/man/man${i:C/.*\.//}
.endfor

.include <bsd.port.mk>
