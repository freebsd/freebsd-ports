PORTNAME=	immich
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.2
PORTREVISION=	6
CATEGORIES=	www
MASTER_SITES=	https://github.com/joneum/FreeBSD-Immich/releases/download/v${DISTVERSION}/:buildkit
DISTFILES=	immich-freebsd-buildkit-${DISTVERSION}${EXTRACT_SUFX}:buildkit

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	High performance self-hosted photo and video management solution
WWW=		https://immich.app/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	native Node.js modules are only tested on \
			64-bit platforms

BUILD_DEPENDS=	${LOCALBASE}/bin/npm:www/npm-node22
LIB_DEPENDS=	libheif.so:graphics/libheif \
		libraw.so:graphics/libraw \
		libvips.so:graphics/vips
RUN_DEPENDS=	${LOCALBASE}/bin/gzip:archivers/gzip \
		exiftool:graphics/p5-Image-ExifTool \
		${LOCALBASE}/bin/jellyfin-ffmpeg8:multimedia/jellyfin-ffmpeg

USES=		cpe gettext-runtime gmake gnome nodejs:22,build,run pgsql:14+ \
		pkgconfig python:build
CPE_VENDOR=	futo
WANT_PGSQL=	client

USE_GNOME=	glib20

USE_GITHUB=	yes
GH_ACCOUNT=	immich-app

USE_RC_SUBR=	immich_server

# The buildkit distfile carries the pnpm store, the pnpm tarball, the
# geodata and the core plugin, so that the build needs no network. It is
# made by unpacking the release tarball and running, with the pnpm version
# from packageManager in package.json:
#   pnpm install --frozen-lockfile --ignore-scripts --store-dir <kit>/pnpm-store
#   cd <kit> && npm pack pnpm@<version>
# plus the geodata files from geonames.org and natural-earth-vector, and
# the immich-plugin-core payload from the upstream container image.
BUILDKIT=	${WRKDIR}/immich-freebsd-buildkit-${DISTVERSION}
PNPM=		${WRKDIR}/pnpm-prefix/bin/pnpm
PNPM_VERSION=	11.22.0

MAKE_ENV=	CI=1 \
		COREPACK_ENABLE_STRICT=0 \
		NODE_OPTIONS=--max-old-space-size=4096 \
		npm_config_build_from_source=true \
		npm_config_nodedir=${LOCALBASE} \
		npm_config_python=${PYTHON_CMD} \
		PYTHON=${PYTHON_CMD} \
		SHARP_FORCE_GLOBAL_LIBVIPS=1

SUB_FILES=	immich-admin pkg-message
SUB_LIST=	NODE=${LOCALBASE}/bin/node

USERS=		immich
GROUPS=		immich

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/lib/postgresql/[^/]*/bin/|${LOCALBASE}/bin/|' \
		${WRKSRC}/server/src/services/database-backup.service.ts

pre-build:
	cd ${WRKDIR} && ${SETENV} PATH=${PATH} \
		npm install -g --prefix ${WRKDIR}/pnpm-prefix \
		${BUILDKIT}/pnpm-${PNPM_VERSION}.tgz

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PNPM} install --offline --frozen-lockfile \
		--store-dir ${BUILDKIT}/pnpm-store
	cd $$(${ECHO_CMD} ${WRKSRC}/node_modules/.pnpm/sharp@*/node_modules/sharp) && \
		${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/node install/build.js
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PNPM} --filter @immich/plugin-sdk --filter @immich/sdk \
		--filter immich build
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PNPM} --filter immich-web build
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PNPM} --store-dir ${BUILDKIT}/pnpm-store --filter immich \
		--prod --no-optional deploy ${WRKDIR}/server-pruned
	cd $$(${ECHO_CMD} ${WRKDIR}/server-pruned/node_modules/.pnpm/sharp@*/node_modules/sharp) && \
		${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/node install/build.js

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/immich-admin ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${FILESDIR}/immich.env.sample ${STAGEDIR}${PREFIX}/etc/
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${FILESDIR}/newsyslog-immich.conf \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/immich.conf
	${MKDIR} ${STAGEDIR}${WWWDIR}/server \
		${STAGEDIR}${WWWDIR}/build-data/www \
		${STAGEDIR}${WWWDIR}/build-data/geodata \
		${STAGEDIR}${WWWDIR}/build-data/plugins/immich-plugin-core
	cd ${WRKDIR}/server-pruned && ${PAX} -rw . ${STAGEDIR}${WWWDIR}/server
	cd ${WRKSRC}/web/build && ${PAX} -rw . ${STAGEDIR}${WWWDIR}/build-data/www
	cd ${BUILDKIT}/geodata && ${PAX} -rw . ${STAGEDIR}${WWWDIR}/build-data/geodata
	cd ${BUILDKIT}/plugins/immich-plugin-core && ${PAX} -rw . \
		${STAGEDIR}${WWWDIR}/build-data/plugins/immich-plugin-core
	${MKDIR} ${STAGEDIR}/var/db/immich ${STAGEDIR}/var/log/immich

post-install:
	@${FIND} ${STAGEDIR}${WWWDIR}/server/node_modules -type f \
		\( -name "*.sh" -o -name "*.py" -o -name build_tag_lookup \
		-o -name validate \) -exec ${CHMOD} a-x {} +
	@${FIND} ${STAGEDIR}${WWWDIR}/server -type d \
		\( -name .tmp -o -name .deps -o -name nothing \) \
		-exec ${RM} -r {} + 2>/dev/null || ${TRUE}
	@${FIND} ${STAGEDIR}${WWWDIR}/server -type f \
		\( -name "*.map" -o -name "*.d.ts" \) -delete
	@${FIND} ${STAGEDIR}${WWWDIR}/server -type d \
		\( -name test -o -name tests -o -name __tests__ \
		-o -name coverage \) -exec ${RM} -r {} + 2>/dev/null || ${TRUE}
	@${FIND} ${STAGEDIR}${WWWDIR}/server -type d -empty -delete
	@${PRINTF} '#!/bin/sh\nexec ${PREFIX}/bin/immich-admin "$$@"\n' \
		> ${STAGEDIR}${WWWDIR}/server/bin/immich-admin

.include <bsd.port.mk>
