# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

# if a github project, use:
#
#GITHUB_CREATOR=	someuser

# otherwise, use:
#
#GIT_URL=	https://example.com/path/to/${GIT_PROJECT_NAME}.git

#GIT_PROJECT_NAME defaults to ${PORTNAME}

# if there are submodules to checkout, define:
#GIT_SUBMODULES=	yes


GIT_PROJECT_NAME?=	${PORTNAME}
GIT_VERSION?=	${PORTVERSION}
WRKSRC?=		${WRKDIR}/${GIT_PROJECT_NAME}

.if defined(GITHUB_CREATOR)
GIT_URL=	https://github.com/${GITHUB_CREATOR}/${GIT_PROJECT_NAME}.git
.endif

.if !defined(GITHUB_CREATOR) && !defined(GIT_URL)
.error You must define GITHUB_CREATOR or GIT_URL to use bsd.git-clone.mk
.endif

FETCH_DEPENDS+=	git:${PORTSDIR}/devel/git

# will not clobber do-{fetch,extract}
do-fetch: git-fetch
do-extract: git-extract

git-fetch:
	@if [ ! -e ${WRKSRC}/.git/index ]; then \
		${MKDIR} ${WRKDIR}; \
		cd ${WRKDIR} && git clone ${GIT_URL}; \
		cd ${WRKSRC} && git checkout ${GIT_VERSION}; \
		if [ -n "${GIT_SUBMODULES}" ]; then \
			cd ${WRKSRC} && git submodule init; \
			cd ${WRKSRC} && git submodule update; \
		fi \
	fi

git-extract:
#normally do-extract starts with an rm -rf ${WRKSRC}
	@${DO_NADA}
