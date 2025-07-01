PORTNAME=	tailwindcss3
DISTVERSION=	3.4.17
CATEGORIES=	www devel
MASTER_SITES=	LOCAL/dch/${PORTNAME}/:npm
DISTFILES=	${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX}:npm

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Utility-first CSS framework with npm dependencies
WWW=		https://tailwindcss.com/

LICENSE=	MIT

BUILD_DEPENDS=	npm:www/npm
USES=		nodejs:run tar:txz

CONFLICTS_INSTALL=	tailwindcss*

_DAISYUI_VER=	4.12.24
_FORMS_VER=	0.5.10
_POSTCSS_VER=	8.4.49
_PREFIX_VER=	10.4.20
_TAILWIND_VER=	${DISTVERSION}

_NPM_CACHE=	${WRKDIR}/cache
_NPM_ARCHIVE=	${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX}

do-extract:
	@${MKDIR} ${WRKDIR}/cache
	${TAR} -xf ${DISTDIR}/${_NPM_ARCHIVE} -C ${_NPM_CACHE}

do-build:
# because nodejs is fiddly we can't build & then install
.if !defined(MAINTAINER_MODE)
	${ECHO_CMD} offline=true > ${WRKDIR}/.npmrc
.endif

do-install:
	(cd ${WRKDIR} && \
		${SETENV} HOME=${WRKDIR} npm install --global --no-audit \
		--no-fund --no-prune --cache ${_NPM_CACHE} --prefer-offline \
		--prefix=${STAGEDIR}${PREFIX} autoprefixer@${_PREFIX_VER} \
		tailwindcss@${_TAILWIND_VER} postcss@${_POSTCSS_VER} \
		@tailwindcss/forms@${_FORMS_VER} daisyui@${_DAISYUI_VER})
# remove files already present in node, npm, or yarn packages
.for m in corepack npm
	${RM} -rf ${STAGEDIR}${PREFIX}/lib/node_modules/${m}
.endfor

_tarball: do-install
	${TAR} -caf ${DISTDIR}/${_NPM_ARCHIVE} -C ${_NPM_CACHE} _cacache
	${CHMOD} 644 ${DISTDIR}/${_NPM_ARCHIVE}
	@${ECHO_MSG} Ready to upload tarball to freefall distfiles directory:
	@${ECHO_MSG} ${DISTDIR}/${_NPM_ARCHIVE}
	@${ECHO_MSG} scp ${DISTDIR}/${_NPM_ARCHIVE} dch@freefall.freebsd.org:public_distfiles/${PORTNAME}/

.include <bsd.port.mk>
