PORTNAME=	sq
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.1
PORTREVISION=	2
CATEGORIES=	security
PKGNAMEPREFIX=	sequoia-

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	Sequoia-PGP command line tool
WWW=		https://sequoia-pgp.org/

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	capnp:devel/capnproto
LIB_DEPENDS=	libnettle.so:security/nettle

USES=	cargo llvm sqlite ssl

USE_GITLAB=	yes
GL_ACCOUNT=	sequoia-pgp
GL_PROJECT=	${PKGNAMEPREFIX}${PORTNAME}

CARGO_ENV+=	ASSET_OUT_DIR=${CARGO_TARGET_DIR}

OPTIONS_DEFINE=	BASH ELVISH FISH MANPAGES ZSH
OPTIONS_DEFAULT=	BASH ELVISH FISH MANPAGES ZSH
OPTIONS_SUB=	yes

ELVISH_DESC=	Install Elvish module

.include <bsd.port.pre.mk>

.if ${ARCH:Marmv?}
LTO_UNSAFE=	yes
CARGO_ENV+=	CARGO_PROFILE_RELEASE_LTO=false
.endif

post-install-BASH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_DATA} ${CARGO_TARGET_DIR}/shell-completions/${PORTNAME}.bash \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/${PORTNAME}

post-install-ELVISH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/elvish/lib
	${INSTALL_DATA} ${CARGO_TARGET_DIR}/shell-completions/${PORTNAME}.elv \
		${STAGEDIR}${PREFIX}/share/elvish/lib

post-install-FISH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${CARGO_TARGET_DIR}/shell-completions/${PORTNAME}.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions

post-install-MANPAGES-on:
	${FIND} ${CARGO_TARGET_DIR}/man-pages -name "*.1" \
		-exec ${INSTALL_MAN} {} ${STAGEDIR}${PREFIX}/share/man/man1 \;

post-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${CARGO_TARGET_DIR}/shell-completions/_${PORTNAME} \
	${CARGO_TARGET_DIR}/shell-completions/_${PORTNAME}.ps1 \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

.include <bsd.port.post.mk>
