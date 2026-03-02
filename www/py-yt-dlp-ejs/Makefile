PORTNAME=	yt-dlp-ejs
DISTVERSION=	0.5.0
CATEGORIES=	www
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-node-modules-${DISTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	JavaScript challenge solver for yt-dlp
WWW=		https://github.com/yt-dlp/yt-dlp-ejs

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

FETCH_DEPENDS=	npm:www/npm
BUILD_DEPENDS=	deno:www/deno \
		npm:www/npm \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	deno:www/deno

USES=		python
USE_PYTHON=	pep517 autoplist pytest

SHEBANG_GLOB=	*.py

NO_ARCH=	yes

DD=		${DISTDIR}/${DIST_SUBDIR}

IGNORE=		invalid code in do-fetch

# do-fetch:
# 	@if ! [ -f ${DD}/${DISTNAME}${EXTRACT_SUFX} ] || \
# 	    ! [ -f ${DD}/${PORTNAME}-node-modules-${DISTVERSION}${EXTRACT_SUFX} ]; then \
# 		${MKDIR} ${DD} && ${MKDIR} ${WRKDIR} && \
# 		${ECHO_MSG} "====> Fetching ${DISTNAME}${EXTRACT_SUFX}" && \
# 		cd ${DD} && ${FETCH_CMD} https://files.pythonhosted.org/packages/source/y/yt-dlp-ejs/${DISTNAME}${EXTRACT_SUFX} && \
# 		${ECHO_MSG} "====> Fetching and packaging node_modules using package-lock.json" && \
# 		${TAR} -xf ${DD}/${DISTNAME}${EXTRACT_SUFX} -C ${WRKDIR} && \
# 		if [ -f ${FILESDIR}/package-lock.json ]; then \
# 			${ECHO_MSG} "====> Using existing package-lock.json"; \
# 			${CP} ${FILESDIR}/package-lock.json ${WRKDIR}/${DISTNAME}/; \
# 		else \
# 			${ECHO_MSG} "====> Generating package-lock.json (it will be saved to ${FILESDIR})"; \
# 		fi && \
# 		cd ${WRKDIR}/${DISTNAME} && \
# 			${SETENV} HOME=${WRKDIR} npm ci && \
# 		if ! [ -f ${FILESDIR}/package-lock.json ]; then \
# 			${ECHO_MSG} "====> Saving generated package-lock.json to ${FILESDIR}"; \
# 			${CP} ${WRKDIR}/${DISTNAME}/package-lock.json ${FILESDIR}/; \
# 		fi && \
# 		${FIND} node_modules -name '.package-lock.json' -delete && \
# 		${FIND} node_modules -type d -name '@*' -empty -delete && \
# 		${FIND} node_modules -exec ${TOUCH} -h -d 1970-01-01T00:00:00Z {} \; && \
# 		${FIND} node_modules -print0 | ${SORT} -z | \
# 			${TAR} czf ${DD}/${PORTNAME}-node-modules-${DISTVERSION}${EXTRACT_SUFX} \
# 				--format=bsdtar --no-read-sparse --gid 0 --uid 0 \
# 				--options gzip:!timestamp --no-recursion --null -T - && \
# 		${RM} -rf ${WRKDIR}; \
# 	fi

post-extract:
	# Extract pre-downloaded node_modules
	@${TAR} -xf ${DD}/${PORTNAME}-node-modules-${DISTVERSION}${EXTRACT_SUFX} -C ${WRKSRC}

do-build:
	# Build JavaScript bundles
	@${ECHO_MSG} "====> Building JavaScript bundles with rollup..."
	@cd ${WRKSRC} && \
		${SETENV} HOME=${WRKDIR} npm run bundle
	# Verify bundles were created
	@if ! [ -f ${WRKSRC}/dist/yt.solver.core.min.js ] || \
	    ! [ -f ${WRKSRC}/dist/yt.solver.lib.min.js ]; then \
		${ECHO_MSG} "ERROR: JavaScript bundles were not created properly"; \
		exit 1; \
	fi
	# Build Python wheel
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${PYTHON_CMD} -m build --no-isolation --wheel --outdir ${WRKSRC}/dist

pre-test:
	# Copy built JavaScript files to test location
	@${MKDIR} ${WRKSRC}/yt_dlp_ejs/yt/solver
	@${CP} ${WRKSRC}/dist/yt.solver.core.min.js ${WRKSRC}/yt_dlp_ejs/yt/solver/core.min.js
	@${CP} ${WRKSRC}/dist/yt.solver.lib.min.js ${WRKSRC}/yt_dlp_ejs/yt/solver/lib.min.js

# tests as of 0.5.0:
# Results (0.15s):
#          3 passed

.include <bsd.port.mk>
