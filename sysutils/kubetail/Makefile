PORTNAME=	kubetail
DISTVERSION=	1.6.22
CATEGORIES=	sysutils

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	Bash script to tail Kubernetes logs
WWW=		https://github.com/johanhaleby/kubetail

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash \
		kubectl:sysutils/kubectl

USE_GITHUB=	yes
GH_ACCOUNT=	johanhaleby

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=		BASH FISH ZSH
OPTIONS_DEFAULT=	BASH FISH ZSH

BASH_PLIST_FILES=	share/bash-completion/completions/${PORTNAME}
FISH_PLIST_FILES=	share/fish/vendor_functions.d/${PORTNAME}.fish
ZSH_PLIST_FILES=	share/zsh/site-functions/_${PORTNAME}

post-install-BASH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_DATA} ${WRKSRC}/completion/${PORTNAME}.bash \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/${PORTNAME}

post-install-FISH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/vendor_functions.d
	${INSTALL_DATA} ${WRKSRC}/completion/${PORTNAME}.fish \
		${STAGEDIR}${PREFIX}/share/fish/vendor_functions.d/${PORTNAME}.fish

post-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completion/${PORTNAME}.zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
