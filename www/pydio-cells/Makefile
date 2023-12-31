PORTNAME=	cells
DISTVERSIONPREFIX=	v
DISTVERSION=	4.3.2
CATEGORIES=	www
PKGNAMEPREFIX=	pydio-

MAINTAINER=	skozlov@FreeBSD.org
COMMENT=	Nextgen file sharing platform for organizations
WWW=		https://github.com/pydio/cells

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	Not supported on i386

USES=		cpe go:1.21,modules gmake
CPE_VENDOR=	pydio
USE_RC_SUBR=	${PORTNAME}

GO_MODULE=	github.com/pydio/cells/v4
GO_BUILDFLAGS=	-ldflags "-X github.com/pydio/cells/v4/common.version=${DISTVERSION}\
		-X github.com/pydio/cells/v4/common.BuildStamp=1970-01-01T00:00:00"

USERS=		pydio
GROUPS=		pydio
PLIST_FILES=	bin/cells

OPTIONS_DEFINE=		BASH ZSH
OPTIONS_DEFAULT=	BASH ZSH

BASH_PLIST_FILES=	etc/bash_completion.d/${PORTNAME}
ZSH_PLIST_FILES=	share/zsh/site-functions/_${PORTNAME}

post-fetch:
	# `sourcegraph/appdash-data` doesn't fetch from the proxy, so replace it with the direct GitHub link
	# remove when no longer required for a successful `fetch`
	#
	${ECHO} "replace sourcegraph.com/sourcegraph/appdash-data => github.com/sourcegraph/appdash-data v0.0.0-20151005221446-73f23eafcf67" \
	>> ${DISTDIR}/${DIST_SUBDIR}/${GO_MODFILE}

post-build-BASH-on:
	${SETENV} CELLS_WORKING_DIR=${WRKDIR}/wrkdir \
		${GO_WRKDIR_BIN}/${PORTNAME} tools completion bash \
		> ${WRKDIR}/bash_completions
	@${REINPLACE_CMD} -e 's|${GO_WRKDIR_BIN}/||g' ${WRKDIR}/bash_completions

post-build-ZSH-on:
	${SETENV} CELLS_WORKING_DIR=${WRKDIR}/wrkdir \
		${GO_WRKDIR_BIN}/${PORTNAME} tools completion zsh \
		> ${WRKDIR}/zsh_completions
	@${REINPLACE_CMD} -e 's|${GO_WRKDIR_BIN}/||g' ${WRKDIR}/zsh_completions

post-install-BASH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKDIR}/bash_completions \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}

post-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKDIR}/zsh_completions \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

.include <bsd.port.mk>
