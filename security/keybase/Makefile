# $FreeBSD$

PORTNAME=	keybase
DISTVERSION=	v0.2.0
CATEGORIES=	security
MASTER_SITES=	GH \
		LOCAL/bdrewery/${PORTNAME}/:DEFAULT,deps \
		http://mirror.shatow.net/freebsd/${PORTNAME}/:DEFAULT,deps
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DEP_DIST}:deps

MAINTAINER=	bdrewery@freebsd.org
COMMENT=	Keybase.io client

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	npm>=0:${PORTSDIR}/www/npm
RUN_DEPENDS=	node>=0:${PORTSDIR}/www/node \
		gpg:${PORTSDIR}/security/gnupg

# Must bundle deps.
# 1. They are not in ports and doing so creates a large complex task with little
#    benefit requiring a lot of maintenance. Hopefully someday we will have
#    an npm wrapper similar to BSDPAN.
# 2. npm has absolutely no way to fetch dependencies without installing at the
#    same time so this would not build on poudriere due to network restrictions
#    outside of 'fetch' phase. See https://github.com/npm/npm/issues/2817
# 3. A date is used as dependencies can upgrade even without keybase changing
#    anything due to dependency patterns not binding to specific versions in
#    package.json. I.e., even if the problem of fetching dependencies is
#    solved, we want this package to be reproducible.
DEP_DIST_DATE=	20140327
DEP_DIST_DFMT=	%Y%m%d
DEP_DIST_PRE=	${PORTNAME}-deps-${PORTVERSION}-${GH_COMMIT}-
DEP_DIST_POST=	.txz
DEP_DIST=	${DEP_DIST_PRE}${DEP_DIST_DATE}${DEP_DIST_POST}

USE_GITHUB=	yes
GH_ACCOUNT=	keybase
GH_PROJECT=	node-client
GH_COMMIT=	9509986

KEYBASE_PREFIX=	${PREFIX}/libexec/${PORTNAME}

# Generate dependency distfile. This is only used by maintainer.
makedeps: patch
	cd ${WRKSRC} && \
	  ${RM} -rf node_modules && \
	  dep_fname="${DEP_DIST_PRE}`/bin/date '+${DEP_DIST_DFMT}'`${DEP_DIST_POST}" && \
	  tar -cJf $${dep_fname} node_modules/ && \
	  ${MV} -f $${dep_fname} ${_DISTDIR}/ && \
	  cd ${.CURDIR} && \
	  ${MAKE} makesum

post-extract:
	@${MV} ${WRKDIR}/node_modules ${WRKSRC}/node_modules

add-plist-post: npm-auto-plist

npm-auto-plist:
	@{ \
	  ${ECHO_CMD} "bin/${PORTNAME}"; \
	  ${FIND} ${STAGEDIR}${KEYBASE_PREFIX} -type f -or -type l; \
	  ${FIND} ${STAGEDIR}${KEYBASE_PREFIX} -type d -d | ${SED} -e 's,^,@dirrm ,'; \
	} | ${SED} 's,${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}

do-install:
	@${MKDIR} ${WRKDIR}/tmp ${STAGEDIR}${KEYBASE_PREFIX}/lib
	cd ${STAGEDIR}${KEYBASE_PREFIX}/lib && ${SETENV} HOME=${WRKDIR}/tmp \
	  ${LOCALBASE}/bin/npm install ${WRKSRC}
	${LN} -s ${KEYBASE_PREFIX}/lib/node_modules/${PORTNAME}/bin/main.js \
	  ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

# Quiet stage-qa
post-install:
	@${RM} ${STAGEDIR}${KEYBASE_PREFIX}/lib/node_modules/keybase/node_modules/request/node_modules/node-uuid/benchmark/bench.sh

.include <bsd.port.mk>
