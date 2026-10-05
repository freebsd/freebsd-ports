PORTNAME=	evcc
DISTVERSION=	0.316.2
CATEGORIES=	www
MASTER_SITES=	LOCAL/mfechner/${PORTNAME}/:npmcache
DISTFILES=	${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX}:npmcache

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Extensible EV Charge Controller
WWW=		https://evcc.io/ \
		https://github.com/evcc-io/evcc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	Npm cache only for amd64 generated (rolldown freebsd-x64 binding)

# evcc 0.316.x ships a vite-plus based build, but plain vite 8 is used instead
# (see patch-package.json / patch-vite.config.ts).  vite 8 publishes official
# FreeBSD x64 native bindings (rolldown/lightningcss) as npm optional
# packages, so they are pulled in by the npm cache and no devel/vite-plus
# port is required.
BUILD_DEPENDS=	npm-node24>0:www/npm-node24

USES=		gmake go:1.27+,modules,no_targets nodejs:24,build tar:zstd

# Find here: https://github.com/evcc-io/evcc/releases
_SHA=		7db12597018f97076633cdd8262d434a89893fd2

USE_GITHUB=	yes
GH_ACCOUNT=	evcc-io
USE_RC_SUBR=	${PORTNAME}
GO_MOD_DIST=	github
GO_MODULE=	github.com/evcc-io/evccmain

MAKE_ENV=	npm_config_offline=true TAG_NAME=${DISTVERSION} SHA=${_SHA}

# parallel build failed in my tests, so disable it here
MAKE_JOBS_UNSAFE=yes
# Build the Go binary only; the UI (dist/) is built in pre-build with plain
# vite.  0.316.x upstream "default"/"ui" targets require the vite-plus "vp"
# CLI, so we bypass them.
ALL_TARGET=	build

USERS=		evcc
GROUPS=		evcc

PLIST_FILES=	bin/${PORTNAME}

pre-build:
	# install node deps offline from the .npm cache distfile (extracted to
	# ${WRKDIR}/.npm; the framework sets HOME=${WRKDIR} so it is npm's default
	# cache).  The lockfile was generated with "npm install --force" (see
	# make-npm-cache) so a plain "npm ci" resolves without peer warnings.
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm ci
	# build the UI (dist/) with plain vite; "npm run build" -> "vite build"
	# (vite 8 ships official FreeBSD x64 native bindings via npm)
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm run build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/evcc ${STAGEDIR}${PREFIX}/bin

# to update the port
# update version and _SHA
# comment DISTFILES
# make makesum
# make clean extract do-patch
# cd work/evcc-*
# (for maintainer) helper target to generate the .npm cache tarball
make-npm-cache: patch
	@cd ${WRKDIR} && ${RM} -r .npm
	# --force resolves the (unpinned) storybook/react peer deps into the
	# lockfile so the offline "npm ci" in pre-build works without peer warnings
	@cd ${WRKSRC} && ${SETENV} HOME=${WRKDIR} npm install --force
	@cd ${WRKDIR} \
		&& ${TAR} -c --zstd -f ${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX} .npm \
		&& ${ECHO} "Please upload the file: scp ${WRKDIR}/${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX} mfechner@freefall.freebsd.org:public_distfiles/${PORTNAME}/"
# cd ../..
# make makepatch
# make make-npm-cache
# cp work/evcc-npm-cache* ../../distfiles/go/www_evcc/evcc-io-evcc-0.316.2_GH0/
# uncomment DISTFILES
# make makesum

.include <bsd.port.mk>
