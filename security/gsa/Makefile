PORTNAME=	gsa
DISTVERSIONPREFIX=	v
DISTVERSION=	24.6.1
CATEGORIES=	security

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Greenbone Security Assistant webpage written in React
WWW=		https://github.com/greenbone/gsa

LICENSE=	AGPLv3+

DEPRECATED=	Depends on expired www/npm-node18
EXPIRATION_DATE=2025-09-01

ONLY_FOR_ARCHS=	aarch64 amd64

BUILD_DEPENDS=	npm-node18>0:www/npm-node18
RUN_DEPENDS=	${LOCALBASE}/sbin/gsad:security/gsad

USES=		nodejs:build

USE_GITHUB=	yes
GH_ACCOUNT=	greenbone
GH_PROJECT=	gsa

NPM_BIN=	${LOCALBASE}/bin/npm

# to rebuild the deps archive:
#   1. set DEV_UPDATE_MODE=yes
#   2. make makesum build
#   3. upload the *-cache archive
#   4. set DEV_UPDATE_MODE=no
#   5. make clean makesum

DEV_UPDATE_MODE=	no
DEPS_CACHE_DIR=		${WRKSRC}

.if (${DEV_UPDATE_MODE} == "yes")
NPM_ARGS=	install
post-patch:
	@${RM} ${WKRSRC}/package-lock.json

post-build:
	@cd ${DEPS_CACHE_DIR} && ${TAR} czf ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-cache-${ARCH}-${DISTVERSION}${EXTRACT_SUFX} node_modules
	@${ECHO} "(!!!) Please upload the cache archive: ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-cache-${ARCH}-${DISTVERSION}${EXTRACT_SUFX}"
.else
MASTER_SITES+=	LOCAL/acm/gsa/:npm_cache
DISTFILES+=	${PORTNAME}-cache-${ARCH}-${DISTVERSION}${EXTRACT_SUFX}:npm_cache
NPM_ARGS=	run build

post-extract:
	@${MV} ${WRKDIR}/node_modules ${WRKSRC}
.endif

do-build:
	@cd ${WRKSRC} && \
		${NPM_BIN} ${NPM_ARGS}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/gvm/gsad/web

	(cd ${WRKSRC}/build && ${COPYTREE_SHARE} . \
		${STAGEDIR}/${PREFIX}/share/gvm/gsad/web)

post-install:
	@${ECHO_CMD} "share/gvm/gsad/web/index.html" >> ${TMPPLIST}
	@${ECHO_CMD} "share/gvm/gsad/web/robots.txt" >> ${TMPPLIST}
	@cd ${WRKSRC}/build && \
		${FIND} -s img locales assets -not -type d \
			-exec ${ECHO_CMD} "share/gvm/gsad/web/{}" \; >> ${TMPPLIST}

.include <bsd.port.mk>
