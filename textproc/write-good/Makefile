PORTNAME=	write-good
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.8
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/0mp/:npm
DISTFILES=	${_NPM_DISTFILES}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Naive linter for English prose
WWW=		https://github.com/btford/write-good

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	npm:www/npm

USES=		nodejs:run
USE_GITHUB=	yes
GH_ACCOUNT=	btford

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS
PORTDOCS=	README.md

.if !defined(MAINTAINER_MODE)
_NPM_DISTFILES=		${_NPM_DISTFILE_cache}:npm \
			${_NPM_DISTFILE_modules}:npm
.endif
_NPM_DISTFILE_cache=	${PORTNAME}-${DISTVERSION}.cache${EXTRACT_SUFX}
_NPM_DISTFILE_modules=	${PORTNAME}-${DISTVERSION}.modules${EXTRACT_SUFX}

_UNNECESSARY_FILES=	test .dockerignore \
			.eslintrc .gitignore .npmignore .pre-commit-hooks.yaml \
			.travis.yml Dockerfile LICENSE README.md
_LIBEXEC_REL=		libexec/${PORTNAME}
_LIBEXEC=		${STAGEDIR}${PREFIX}/${_LIBEXEC_REL}

do-install:
	@${MKDIR} ${_LIBEXEC}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${_LIBEXEC})

	${RLN} ${_LIBEXEC}/bin/${PORTNAME}.js ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${RLN} ${_LIBEXEC}/bin/${PORTNAME}.js ${STAGEDIR}${PREFIX}/bin/writegood
	${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/writegood

	(cd ${_LIBEXEC} && ${RM} -r ${_UNNECESSARY_FILES})

post-install:
# Build plist automatically to avoid listing all the node_modules files.
	(cd ${STAGEDIR}${PREFIX} && \
		${FIND} ${_LIBEXEC_REL}/node_modules -not -type d >> ${TMPPLIST})

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

# - Requires npm (e.g., from www/npm).
# - Remember to set MAINTAINER_MODE,
#   e.g., "make -DMAINTAINER_MODE _npm-regenerate".
_npm-regenerate:
	${MAKE} clean patch
	(cd ${WRKSRC} && ${SETENV} ${_NPM_ENV} npm install --ignore-scripts)
	${FIND} ${WRKDIR}/.npm ${WRKSRC}/node_modules -exec ${TOUCH} -h -d 1970-01-01T00:00:00Z {} \;
	(cd ${WRKDIR} && \
		${FIND} .npm/_cacache -print0 | LC_ALL=C ${SORT} -z | \
		${TAR} czf ${WRKDIR}/${_NPM_DISTFILE_cache} --format=ustar --uid 0 --gid 0 --options gzip:!timestamp --no-recursion --null -T -)
	(cd ${WRKDIR} && \
		${FIND} ${WRKSRC:T}/node_modules -print0 | LC_ALL=C ${SORT} -z | \
		${TAR} czf ${WRKDIR}/${_NPM_DISTFILE_modules} --format=ustar --uid 0 --gid 0 --options gzip:!timestamp --no-recursion --null -T -)
	scp ${WRKDIR}/${_NPM_DISTFILE_cache} ${WRKDIR}/${_NPM_DISTFILE_modules} 0mp@freefall.freebsd.org:public_distfiles/
	cp ${WRKDIR}/${_NPM_DISTFILE_cache} ${WRKDIR}/${_NPM_DISTFILE_modules} ${DISTDIR}/

.include <bsd.port.mk>
