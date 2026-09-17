PORTNAME=	oama
DISTVERSION=	0.21.0
CATEGORIES=	mail
PKGNAMEPREFIX=

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	OAuth credential Manager
WWW=		https://github.com/pdobsan/oama

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsecret-1.so:security/libsecret
RUN_DEPENDS=	gpgme-config:security/gpgme

USES=		cabal gnome
USE_GITHUB=	yes
GH_ACCOUNT=	pdobsan
USE_GNOME=	introspection

CABAL_PROJECT=	append

PLIST_FILES=	share/bash-completion/completions/oama \
		share/fish/vendor_completions.d/oama.fish \
		share/zsh/site-functions/_oama

post-extract:
	(cd ${WRKSRC}/completions && \
	${REINPLACE_CMD} \
		-e 's,/usr/bin,${PREFIX}/bin,g' \
		oama.bash oama.fish oama.zsh)

post-install:
	(cd ${WRKSRC}/completions && \
	${INSTALL_DATA} oama.bash ${STAGEDIR}${PREFIX}/share/bash-completion/completions/oama && \
	${INSTALL_DATA} oama.fish ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/oama.fish && \
	${INSTALL_DATA} oama.zsh ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_oama)

.include <bsd.port.mk>
