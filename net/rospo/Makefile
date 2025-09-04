PORTNAME=	rospo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.15.0
PORTREVISION=	3
CATEGORIES=	net net-vpn sysutils

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Simple and reliable ssh tunnels with embedded ssh server
WWW=		https://github.com/ferama/rospo

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24,modules
GO_MODULE=	github.com/ferama/rospo
GO_BUILDFLAGS=	-ldflags="-X github.com/ferama/rospo/cmd.Version=${PKGVERSION} ${STRIP}"

OPTIONS_DEFINE=	DOCS

post-install:
	@${ECHO_MSG} '====> installing shell completion files'
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${GO_WRKDIR_BIN}/rospo completion bash \
	    >${STAGEDIR}${PREFIX}/etc/bash_completion.d/rospo
	${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d
	${GO_WRKDIR_BIN}/rospo completion fish \
	    >${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/rospo.fish
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site_functions
	${GO_WRKDIR_BIN}/rospo completion zsh \
	    >${STAGEDIR}${PREFIX}/share/zsh/site_functions/_rospo
	@${ECHO_MSG} '====> installing documentation files'
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/
	${INSTALL_MAN} ${WRKSRC}/cmd/configs/config_template.yaml ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
