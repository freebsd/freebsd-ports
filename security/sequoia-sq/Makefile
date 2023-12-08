PORTNAME=	sq
DISTVERSIONPREFIX=	v
DISTVERSION=	0.31.0
PORTREVISION=	4
CATEGORIES=	security
PKGNAMEPREFIX=	sequoia-

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	Sequoia-PGP command line tool
WWW=		https://sequoia-pgp.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libnettle.so:security/nettle \
		libgmp.so:math/gmp

USES=	cargo llvm sqlite ssl

USE_GITLAB=	yes
GL_ACCOUNT=	sequoia-pgp
GL_PROJECT=	${PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=	BASH FISH MANPAGES ZSH
OPTIONS_DEFAULT=	BASH FISH MANPAGES ZSH
OPTIONS_SUB=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-BASH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_DATA} ${CARGO_TARGET_DIR}/${PORTNAME}.bash \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/${PORTNAME}

post-install-FISH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${CARGO_TARGET_DIR}/${PORTNAME}.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions

post-install-MANPAGES-on:
	${FIND} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/release/build/${PKGNAMEPREFIX}${PORTNAME}-*/out -name "*.1" \
		-exec ${INSTALL_MAN} {} ${STAGEDIR}${MANPREFIX}/man/man1 \;

post-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${CARGO_TARGET_DIR}/_${PORTNAME} \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

.include <bsd.port.mk>
