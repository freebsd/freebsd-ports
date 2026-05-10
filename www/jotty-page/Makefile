PORTNAME=	jotty-page
DISTVERSION=	1.23.0
CATEGORIES=	www

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	Self-hosted notes, checklists and knowledge-base application
WWW=		https://github.com/fccview/jotty

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	fccview
GH_PROJECT=	jotty

# yarn (classic, v1) from ports is sufficient; Next.js uses webpack on FreeBSD
# instead of Turbopack (which has no FreeBSD native binary).
# USES=nodejs:24,build,run adds node24 to both BUILD_DEPENDS and RUN_DEPENDS.
BUILD_DEPENDS=	yarn${NODEJS_SUFFIX}>0:www/yarn${NODEJS_SUFFIX}

USES=		nodejs:24,build,run

USE_RC_SUBR=	jotty_page

JOTTYPAGE_USER?=	www
JOTTYPAGE_GROUP?=	www

USERS=		${JOTTYPAGE_USER}
GROUPS=		${JOTTYPAGE_GROUP}

# Build-time environment --------------------------------------------------
# NOTE: NODE_ENV must NOT be set to "production" during yarn install because
# yarn 1.x silently skips devDependencies when NODE_ENV=production.  The build
# toolchain (Next.js, Tailwind, @serwist/turbopack, …) lives in devDeps.
# NODE_ENV=production is set explicitly only for the patch and build steps.

# Derive a stable, per-version AES-256 key for NEXT_SERVER_ACTIONS_ENCRYPTION_KEY.
# Without this, Next.js calls crypto.subtle.generateKey() on every build, producing
# a fresh random key that is baked into every server action ID.  Different keys →
# different action IDs → different module content → different chunk content-hashes →
# different filenames in .next/static/chunks, making pkg-plist unstable.
# The key must be base64(32 bytes); SHA-256 of "portname-version" satisfies that.
_JOTTYPAGE_ACTION_KEY!=	printf '%s' '${PORTNAME}-${DISTVERSION}' | \
			/usr/bin/openssl dgst -sha256 -binary | \
			/usr/bin/openssl enc -base64 -A

MAKE_ENV+=	JOTTY_FREEBSD=1 \
		NEXT_TELEMETRY_DISABLED=1 \
		HOME=${WRKDIR} \
		YARN_CACHE_FOLDER=${WRKDIR}/.yarn-cache \
		NEXT_SERVER_ACTIONS_ENCRYPTION_KEY=${_JOTTYPAGE_ACTION_KEY}

SUB_FILES=	jotty_page pkg-message
SUB_LIST+=	JOTTYPAGE_USER=${JOTTYPAGE_USER} \
		JOTTYPAGE_GROUP=${JOTTYPAGE_GROUP} \
		PREFIX=${PREFIX} \
		DATADIR=${DATADIR}

PLIST_SUB+=	JOTTYPAGE_USER=${JOTTYPAGE_USER} \
		JOTTYPAGE_GROUP=${JOTTYPAGE_GROUP}

# This port installs hundreds of Node.js modules.  The pkg-plist currently
# covers only the explicitly managed entries (rc script, env sample,
# data/cache directories, and the data symlink).  After the first successful
# "make stage", run "make makeplist" to generate the complete file list and
# replace pkg-plist in the port tree.

# do-build ----------------------------------------------------------------
# Steps mirror the Docker builder stage:
#   1. Install all dependencies (including devDeps needed for the Next.js
#      build toolchain: TypeScript, Tailwind CSS, PostCSS, …).
#   2. Apply FreeBSD compatibility patches to node_modules.
#   3. Build the Next.js application (produces .next/standalone/).
#   4. Populate the standalone directory with static and public assets.
#   5. Stage scripts, patches, config and docs inside standalone so a single
#      COPYTREE_SHARE in do-install captures everything.
#   6. Apply all patches to the standalone node_modules at build time so the
#      installed tree is ready to run without requiring write access at
#      startup.
do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} yarn install --frozen-lockfile
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} NODE_ENV=production node scripts/apply-patches.js
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} NODE_ENV=production yarn build
	${CP} -rp ${WRKSRC}/.next/static ${WRKSRC}/.next/standalone/.next/
	${CP} -rp ${WRKSRC}/public ${WRKSRC}/.next/standalone/
	${MKDIR} ${WRKSRC}/.next/standalone/scripts \
		${WRKSRC}/.next/standalone/patches \
		${WRKSRC}/.next/standalone/user_patches
	${CP} ${WRKSRC}/scripts/apply-patches.js \
		${WRKSRC}/.next/standalone/scripts/
	(cd ${WRKSRC}/patches && ${COPYTREE_SHARE} . \
		${WRKSRC}/.next/standalone/patches)
	cd ${WRKSRC}/.next/standalone && \
		${SETENV} ${MAKE_ENV} NODE_ENV=production node scripts/apply-patches.js
	(cd ${WRKSRC}/howto && ${COPYTREE_SHARE} . \
		${WRKSRC}/.next/standalone/howto)
	(cd ${WRKSRC}/config && ${COPYTREE_SHARE} . \
		${WRKSRC}/.next/standalone/config)

# do-install --------------------------------------------------------------
# Install the self-contained standalone directory to DATADIR.
# User-writable data lives in /var/db/jotty-page, accessed via a symlink.
do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/.next/standalone && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${MKDIR} ${STAGEDIR}/var/db/jotty-page
	${LN} -sf /var/db/jotty-page ${STAGEDIR}${DATADIR}/data
	${INSTALL_DATA} ${FILESDIR}/jotty-page.env.sample \
		${STAGEDIR}${PREFIX}/etc/jotty-page.env.sample

# Maintainer helper -------------------------------------------------------
# Run this target once after bumping PORTVERSION / GH_TAGNAME to produce a
# fresh node_modules snapshot used to verify reproducibility:
#   make fetch extract
#   make create-nodemodules-listing
create-nodemodules-listing:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} yarn install --frozen-lockfile
	${SETENV} ${MAKE_ENV} node -e \
		"const fs=require('fs'); \
		 const nm='${WRKSRC}/node_modules'; \
		 const pkgs=fs.readdirSync(nm).filter(f=>!f.startsWith('.')); \
		 console.log(pkgs.join('\n'));" \
		> ${WRKDIR}/nodemodules-listing.txt
	@${ECHO_MSG} "Node module listing written to ${WRKDIR}/nodemodules-listing.txt"

.include <bsd.port.mk>
