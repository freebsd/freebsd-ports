PORTNAME=	gsa
DISTVERSIONPREFIX=	v
DISTVERSION=	22.4.0
CATEGORIES=	security
MASTER_SITES=	LOCAL/acm/gsa/:yarn_cache
DISTFILES=	${PORTNAME}-cache-${DISTVERSION}${EXTRACT_SUFX}:yarn_cache

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Greenbone Security Assistant webpage written in React

LICENSE=	AGPLv3+

BUILD_DEPENDS=	yarn:www/yarn
RUN_DEPENDS=	${LOCALBASE}/sbin/gsad:security/gsad

USES=		nodejs:build

USE_GITHUB=	yes
GH_ACCOUNT=	greenbone
GH_PROJECT=	gsa

YARN_BIN=	${LOCALBASE}/bin/yarn
YARN_ARGS=	--offline

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
