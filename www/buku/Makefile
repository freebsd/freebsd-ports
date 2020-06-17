# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	buku
PORTVERSION=	4.4
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Powerful command-line bookmark manager

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.4.1:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=1.2.3:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5lib>=1.0.1:www/py-html5lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.23:net/py-urllib3@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils noflavors

NO_ARCH=	yes

PLIST_FILES=	share/man/man1/buku.1.gz

OPTIONS_DEFINE=	BASH FISH ZSH
OPTIONS_DEFAULT=BASH FISH ZSH
BASH_DESC=	Install bash completion
FISH_DESC=	Install fish completion
ZSH_DESC=	Install zsh completion

BASH_PLIST_FILES=	etc/bash_completion.d/buku-completion.bash
FISH_PLIST_FILES=	share/fish/completions/buku.fish
ZSH_PLIST_FILES=	share/zsh/site-functions/_buku

post-extract:
	@${RM} -fr ${WRKSRC}/bukuserver

post-install:
	${INSTALL_MAN} ${WRKSRC}/buku.1 ${STAGEDIR}${PREFIX}/share/man/man1

post-install-BASH-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/auto-completion/bash/buku-completion.bash ${STAGEDIR}${PREFIX}/etc/bash_completion.d/buku-completion.bash

post-install-FISH-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/auto-completion/fish/buku.fish ${STAGEDIR}${PREFIX}/share/fish/completions/buku.fish

post-install-ZSH-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/auto-completion/zsh/_buku ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_buku

.include <bsd.port.mk>
