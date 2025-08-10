PORTNAME=	sequoia-chameleon-gnupg
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.1
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	Reimplementation of gpg using Sequoia
WWW=		https://gitlab.com/sequoia-pgp/sequoia-chameleon-gnupg

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libnettle.so:security/nettle
RUN_DEPENDS=	gpg-agent:security/gnupg
TEST_DEPENDS=	sq:security/sequoia-sq \
		gpg2:security/gnupg

USES=	cargo llvm sqlite ssl

USE_GITLAB=	yes
GL_ACCOUNT=	sequoia-pgp

CARGO_ENV+=	ASSET_OUT_DIR=${CARGO_TARGET_DIR}
TEST_ENV=	REAL_GPG_BIN=${LOCALBASE}/bin/gpg2 \
		REAL_GPGV_BIN=${LOCALBASE}/bin/gpgv2

OPTIONS_DEFINE=	BASH ELVISH FISH MANPAGES ZSH
OPTIONS_DEFAULT=	BASH ELVISH FISH MANPAGES ZSH
OPTIONS_SUB=	yes

ELVISH_DESC=	Install Elvish module

post-install-BASH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_DATA} ${CARGO_TARGET_DIR}/shell-completions/gpg-sq.bash \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/gpg-sq
	${INSTALL_DATA} ${CARGO_TARGET_DIR}/shell-completions/gpgv-sq.bash \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/gpgv-sq

post-install-ELVISH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/elvish/lib
	${INSTALL_DATA} ${CARGO_TARGET_DIR}/shell-completions/gpg-sq.elv \
	${CARGO_TARGET_DIR}/shell-completions/gpgv-sq.elv \
		${STAGEDIR}${PREFIX}/share/elvish/lib

post-install-FISH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${CARGO_TARGET_DIR}/shell-completions/gpg-sq.fish \
	${CARGO_TARGET_DIR}/shell-completions/gpgv-sq.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions

post-install-MANPAGES-on:
	${FIND} ${CARGO_TARGET_DIR}/man-pages -name "*.1" \
		-exec ${INSTALL_MAN} {} ${STAGEDIR}${PREFIX}/share/man/man1 \;

post-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${CARGO_TARGET_DIR}/shell-completions/_gpg-sq \
	${CARGO_TARGET_DIR}/shell-completions/_gpg-sq.ps1 \
	${CARGO_TARGET_DIR}/shell-completions/_gpgv-sq \
	${CARGO_TARGET_DIR}/shell-completions/_gpgv-sq.ps1 \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

.include <bsd.port.pre.mk>

.if ${ARCH:Marmv?}
LTO_UNSAFE=	yes
CARGO_ENV+=	CARGO_PROFILE_RELEASE_LTO=false
.endif

.include <bsd.port.post.mk>
