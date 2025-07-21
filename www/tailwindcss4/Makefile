PORTNAME=	tailwindcss4
DISTVERSION=	4.1.10
CATEGORIES=	www devel
MASTER_SITES=	LOCAL/dch/${PORTNAME}/:npm
DISTFILES=	${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX}:npm

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Utility-first CSS framework with npm dependencies
WWW=		https://tailwindcss.com/

LICENSE=	MIT

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	npm-node24>0:www/npm-node24
USES=		nodejs:24,build,run python:build tar:txz

CONFLICTS_INSTALL=	tailwindcss*

_DAISYUI_VER=	5.0.43
_FORMS_VER=	0.5.10
_POSTCSS_VER=	8.5.5
_TWCLI_VER=	${DISTVERSION}
_TAILWIND_VER=	${DISTVERSION}
_WATCHER_VER=	2.5.1

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
	${ECHO_CMD} python=${PYTHON_CMD} >> ${WRKDIR}/.npmrc
	(cd ${WRKDIR} && \
		${SETENV} HOME=${WRKDIR} npm_config_cache=${_NPM_CACHE} \
		npm_config_devdir=${_NPM_CACHE} npm_config_nodedir=${PREFIX} \
		npm_config_node_gyp_include_dir=${PREFIX}/include/node \
		npm install --global --no-audit --no-fund --no-prune --cache \
		${_NPM_CACHE} --prefer-offline --verbose --no-progress \
		--build-from-source --prefix=${STAGEDIR}${PREFIX} @parcel/watcher@${_WATCHER_VER} \
		@tailwindcss/cli@${TWCLI_VER} @tailwindcss/forms@${FORMS_VER} \
		autoprefixer@${_PREFIX_VER} postcss@${_POSTCSS_VER} \
		tailwindcss@${_TAILWIND_VER} daisyui@${_DAISYUI_VER})
# strip .node files they are shared libraries
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/node_modules/@parcel/watcher/node_modules/@parcel/watcher-freebsd-*/watcher.node
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/node_modules/@parcel/watcher/build/Release/watcher.node
# create symlinks for the CLI tools
.for script in nanoid:../lib/node_modules/nanoid/bin/nanoid.cjs \
	tailwind:../lib/node_modules/@tailwindcss/cli/dist/index.mjs \
	tailwindcss:../lib/node_modules/@tailwindcss/cli/dist/index.mjs
	${LN} -sf ${script:C/.*://} ${STAGEDIR}${PREFIX}/bin/${script:C/:.*//}
.endfor
# remove files already present in node, npm, or yarn packages
.for m in corepack npm
	${RM} -rf ${STAGEDIR}${PREFIX}/lib/node_modules/${m}
.endfor
# remove build detritus
.for file in Release/.deps Release/obj.target Makefile binding.Makefile \
	config.gypi watcher.target.mk
	${RM} -rf ${STAGEDIR}${PREFIX}/lib/node_modules/@parcel/watcher/build/${file}
.endfor

_tarball: do-install
	${TAR} -caf ${DISTDIR}/${_NPM_ARCHIVE} -C ${_NPM_CACHE} _cacache
	${CHMOD} 644 ${DISTDIR}/${_NPM_ARCHIVE}
	@${ECHO_MSG} Ready to upload tarball to freefall distfiles directory:
	@${ECHO_MSG} ${DISTDIR}/${_NPM_ARCHIVE}
	@${ECHO_MSG} scp ${DISTDIR}/${_NPM_ARCHIVE} dch@freefall.freebsd.org:public_distfiles/${PORTNAME}/

.include <bsd.port.mk>
