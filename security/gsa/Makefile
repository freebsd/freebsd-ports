PORTNAME=	gsa
DISTVERSIONPREFIX=	v
DISTVERSION=	22.7.1
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Greenbone Security Assistant webpage written in React
WWW=		https://github.com/greenbone/gsa

LICENSE=	AGPLv3+

BUILD_DEPENDS=	yarn:www/yarn
RUN_DEPENDS=	${LOCALBASE}/sbin/gsad:security/gsad

USES=		nodejs:build

USE_GITHUB=	yes
GH_ACCOUNT=	greenbone
GH_PROJECT=	gsa

YARN_BIN=	${LOCALBASE}/bin/yarn

# to rebuild the deps archive:
#   1. set DEV_UPDATE_MODE=yes
#   2. make makesum build
#   3. upload the *-cache archive
#   4. set DEV_UPDATE_MODE=no
#   5. make clean makesum

DEV_UPDATE_MODE=	no
DEPS_CACHE_DIR=		${WRKDIR}

.if (${DEV_UPDATE_MODE} == "yes")
post-build:
	@cd ${DEPS_CACHE_DIR} && ${TAR} czf ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-cache-${DISTVERSION}${EXTRACT_SUFX} yarn-offline-cache
	@${ECHO} "(!!!) Please upload the cache archive: ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-cache-${DISTVERSION}${EXTRACT_SUFX}"
.else
MASTER_SITES+=	LOCAL/acm/gsa/:yarn_cache
DISTFILES+=	${PORTNAME}-cache-${DISTVERSION}${EXTRACT_SUFX}:yarn_cache
YARN_ARGS=	--offline
.endif

post-patch:
	${ECHO_CMD} 'yarn-offline-mirror "${WRKDIR}/yarn-offline-cache"' >> \
		${WRKSRC}/.yarnrc

do-build:
	@cd ${WRKSRC} && \
		${YARN_BIN} ${YARN_ARGS}
	@cd ${WRKSRC} && \
		${YARN_BIN} ${YARN_ARGS} build

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/gvm/gsad/web

	(cd ${WRKSRC}/build && ${COPYTREE_SHARE} . \
		${STAGEDIR}/${PREFIX}/share/gvm/gsad/web)

post-install:
	@${ECHO_CMD} "share/gvm/gsad/web/index.html" >> ${TMPPLIST}
	@${ECHO_CMD} "share/gvm/gsad/web/robots.txt" >> ${TMPPLIST}
	@cd ${WRKSRC}/build && \
		${FIND} -s img locales static -not -type d \
			-exec ${ECHO_CMD} "share/gvm/gsad/web/{}" \; >> ${TMPPLIST}

.include <bsd.port.mk>
