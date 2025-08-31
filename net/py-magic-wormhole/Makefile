PORTNAME=	magic-wormhole
DISTVERSION=	0.16.0
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Get things from one computer to another, safely
WWW=		https://github.com/warner/magic-wormhole

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=19.2.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}autobahn>=0.14.1:www/py-autobahn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Automat>=0.3.0:devel/py-Automat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hkdf>=0.0.3:security/py-hkdf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}humanize>=0:devel/py-humanize@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}iterable-io>=1.0.0:devel/py-iterable-io@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynacl>=0.3.0:security/py-pynacl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spake2>=0.8:security/py-spake2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.13.0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=17.5.0:devel/py-twisted@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}txtorcon>=18.0.2:security/py-txtorcon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zipstream-ng>=1.7.1:archivers/py-zipstream-ng@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist cryptography distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	BASH FISH ZSH
OPTIONS_DEFAULT=	BASH FISH ZSH

BASH_PLIST_FILES=	share/bash-completion/completions/wormhole
FISH_PLIST_FILES=	share/fish/completions/wormhole.fish
ZSH_PLIST_FILES=        share/zsh/site-functions/_wormhole

post-install-BASH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions/
	${INSTALL_SCRIPT} ${WRKSRC}/wormhole_complete.bash \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/wormhole

post-install-FISH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions/
	${INSTALL_DATA} ${WRKSRC}/wormhole_complete.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions/wormhole.fish

post-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/wormhole_complete.zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_wormhole

.include <bsd.port.mk>
