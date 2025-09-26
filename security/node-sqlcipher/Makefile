PORTNAME=	node-sqlcipher
DISTVERSION=	2.4.4
CATEGORIES=	security
MASTER_SITES=	https://github.com/signalapp/node-sqlcipher/archive/refs/tags/v${DISTVERSION}/:sqlcipher \
		https://registry.npmjs.org/@esbuild/freebsd-arm64/-/:esbuildarm64 \
		https://registry.npmjs.org/@esbuild/freebsd-x64/-/:esbuildx64 \
		LOCAL/mikael/signal-desktop/:npm
DISTFILES=	freebsd-arm64-${ESBUILD_VERS}.tgz:esbuildarm64 \
		freebsd-x64-${ESBUILD_VERS}.tgz:esbuildx64 \
		node-sqlcipher-${DISTVERSION}.tar.gz:sqlcipher \
		node-sqlcipher-${DISTVERSION}-npm-cache.tar.gz:npm

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Fast N-API-based Node.js addon wrapping sqlcipher and FTS5 segmenting APIs
WWW=		https://github.com/signalapp/node-sqlcipher

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64

BUILD_DEPENDS=	${LOCALBASE}/lib/libsignal_sqlcipher_extension.a:devel/signal-sqlcipher-extension \
		npm:www/npm${NODEJS_SUFFIX}

USES=		nodejs:22,build

PLIST_FILES=	lib/node_sqlcipher.node

ESBUILD_VERS=	0.25.9
ESBUILD_ARCH=	${ARCH:S/aarch64/arm64/:S/amd64/x64/}

MAKE_ENV+=	ESBUILD_BINARY_PATH=${WRKDIR}/esbuild-freebsd-64/package/bin/esbuild

post-extract:
	${MKDIR} ${WRKDIR}/esbuild-freebsd-64
	${TAR} xf ${DISTDIR}/freebsd-${ESBUILD_ARCH}-${ESBUILD_VERS}.tgz -C ${WRKDIR}/esbuild-freebsd-64

post-patch:
	${REINPLACE_CMD} "s#PREFIX#${PREFIX}#g" \
		${WRKSRC}/deps/sqlcipher/sqlcipher.gyp \
		${WRKSRC}/binding.gyp

do-build:
	${ECHO_CMD} offline=true > ${WRKSRC}/.npmrc
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} npm install --nodedir=${PREFIX}

do-install:
	${INSTALL_DATA} ${WRKSRC}/build/Release/obj.target/node_sqlcipher.node ${STAGEDIR}${PREFIX}/lib/

create-caches-tarball:
	# do some cleanup first
	${RM} -r ${WRKDIR}/.npm/_logs ${WRKDIR}/.npm/_update-notifier-last-checked

	cd ${WRKDIR} && \
		${TAR} czf node-sqlcipher-${DISTVERSION}-npm-cache.tar.gz .npm

.include <bsd.port.mk>
