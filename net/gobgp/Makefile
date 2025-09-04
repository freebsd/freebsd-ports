PORTNAME=	gobgp
PORTVERSION=	3.25.0
DISTVERSIONPREFIX=	v
PORTREVISION=	12
CATEGORIES=	net
DIST_SUBDIR=	gobgp

MAINTAINER=	pi@FreeBSD.org
COMMENT=	BGP implementation in Go
WWW=		https://github.com/osrg/gobgp

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_RC_SUBR=	gobgpd
GO_MODULE=	github.com/osrg/gobgp/v3
GO_TARGET=	./cmd/gobgp ./cmd/gobgpd:${PREFIX}/libexec/gobgpd

SUB_FILES=	gobgpd
PLIST_FILES=	bin/gobgp libexec/gobgpd

OPTIONS_DEFINE=	BASH ZSH
OPTIONS_DEFAULT=BASH ZSH

BASH_PLIST_FILES=	etc/bash_completion.d/gobgp-completion.bash \
			etc/bash_completion.d/gobgp-dynamic-completion.bash \
			etc/bash_completion.d/gobgp-static-completion.bash
ZSH_PLIST_FILES=	share/zsh/site-functions/_gobgp

post-install-BASH-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${GO_WRKSRC}/tools/completion/gobgp*-completion.bash ${STAGEDIR}${PREFIX}/etc/bash_completion.d/

post-install-ZSH-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${GO_WRKSRC}/tools/completion/zsh/_gobgp ${STAGEDIR}${PREFIX}/share/zsh/site-functions/

.include <bsd.port.mk>
