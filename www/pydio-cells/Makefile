PORTNAME=	cells
DISTVERSIONPREFIX=	v
DISTVERSION=	4.4.14
PORTREVISION=	3
CATEGORIES=	www
PKGNAMEPREFIX=	pydio-

MAINTAINER=	skozlov@FreeBSD.org
COMMENT=	Nextgen file sharing platform for organizations
WWW=		https://github.com/pydio/cells

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	Not supported on i386

USES=		cpe go:modules gmake
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
