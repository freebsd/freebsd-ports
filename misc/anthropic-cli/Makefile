PORTNAME=	anthropic-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	2.14.0
CATEGORIES=	misc

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Command line tool for the Claude API
WWW=		https://github.com/anthropics/anthropic-cli

# Apache-2.0 since 2.0.0; contributions merged before the relicensing remain
# under MIT, and upstream ships both texts.
LICENSE=	APACHE20 MIT
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		go:modules

GO_MODULE=	github.com/anthropics/anthropic-cli/v2
GO_TARGET=	./cmd/ant

# Both install bin/ant and share/man/man1/ant.1.gz
CONFLICTS_INSTALL=	apache-ant

PLIST_FILES=	bin/ant

OPTIONS_DEFINE=		COMPLETIONS MANPAGES
OPTIONS_DEFAULT=	COMPLETIONS MANPAGES

COMPLETIONS_DESC=		Build and install bash, fish and zsh shell completions
COMPLETIONS_PLIST_FILES=	share/bash-completion/completions/ant \
				share/fish/vendor_completions.d/ant.fish \
				share/zsh/site-functions/_ant

MANPAGES_PLIST_FILES=	share/man/man1/ant.1.gz

# The completion scripts and the manual page are not in the source tree;
# upstream generates them from the built binary (scripts/build-docs).
post-build-COMPLETIONS-on:
.for _shell in bash fish zsh
	${SETENV} HOME=${WRKDIR} ${GO_WRKDIR_BIN}/ant @completion ${_shell} \
		>${WRKDIR}/ant.${_shell}
.endfor

post-build-MANPAGES-on:
	${SETENV} HOME=${WRKDIR} ${GO_WRKDIR_BIN}/ant @manpages \
		--output ${WRKDIR}/man --text --gzip=false

post-install-COMPLETIONS-on:
	@${MKDIR} ${COMPLETIONS_PLIST_FILES:H:S|^|${STAGEDIR}${PREFIX}/|}
.for _shell in bash fish zsh
	${INSTALL_DATA} ${WRKDIR}/ant.${_shell} \
		${STAGEDIR}${PREFIX}/${COMPLETIONS_PLIST_FILES:M*${_shell}*}
.endfor

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKDIR}/man/man1/ant.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
