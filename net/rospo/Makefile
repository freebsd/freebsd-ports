PORTNAME=	rospo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.1
CATEGORIES=	net net-vpn sysutils
MASTER_SITES=	https://github.com/ferama/rospo/releases/download/v${DISTVERSION}/ui-artifacts.tar.gz?dummy=/:artifacts
DISTFILES=	${PORTNAME}-ui-artifacts-${DISTVERSION}.tar.gz:artifacts

MAINTAINER=	fuz@fuz.su
COMMENT=	Simple and reliable ssh tunnels with embedded ssh server
WWW=		https://github.com/ferama/rospo

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/ferama/rospo
GO_BUILDFLAGS=	-ldflags="-X github.com/ferama/rospo/cmd.Version=${DISTVERSION} ${STRIP}"

PLIST_FILES=	bin/rospo \
		etc/bash_completion.d/rospo \
		share/fish/vendor_completions.d/rospo.fish \
		share/zsh/site_functions/_rospo
PORTDOCS=	README.md \
		cmd/configs/config_template.yaml \
		img/home.png \
		img/tunnels.png

OPTIONS_DEFINE=	DOCS

post-extract:
	@${MV} ${WRKDIR}/pkg/web/ui/build ${WRKSRC}/pkg/web/ui/build

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

post-install-DOCS-on:
	@${ECHO_MSG} '====> installing documentation files'
	${MKDIR} ${STAGEDIR}${DOCSDIR}/cmd/configs
	${MKDIR} ${STAGEDIR}${DOCSDIR}/img
.for doc in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}/`dirname ${doc}`
.endfor

.include <bsd.port.mk>
