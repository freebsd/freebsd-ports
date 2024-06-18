PORTNAME=	libsignal
DISTVERSIONPREFIX=	v
DISTVERSION=	0.46.2
PORTREVISION=	1
CATEGORIES=	net-im
PKGNAMESUFFIX=	-node
DISTFILES=	libsignal-node-${DISTVERSION}-yarn-cache.tar.gz

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Platform-agnostic APIs used by the official Signal clients and servers
WWW=		https://github.com/signalapp/libsignal

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64

FETCH_DEPENDS=	yarn-node${NODEJS_VERSION}>0:www/yarn-node${NODEJS_VERSION}
EXTRACT_DEPENDS=yarn-node${NODEJS_VERSION}>0:www/yarn-node${NODEJS_VERSION}
BUILD_DEPENDS=	llvm-config${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT} \
		protoc:devel/protobuf \
		yarn:www/yarn-node${NODEJS_VERSION}

USES=		cargo gmake python:build
USE_GITHUB=	yes
GH_ACCOUNT=	signalapp
# to get the GH_TUPLE
# git clone git@github.com:signalapp/boring.git
# cd boring
# git checkout correct_tag (grep boring Makefile.crates)
# git submodule update --init --recursive
# the hash for boringssl and fips should be printed on screen
GH_TUPLE=	google:boringssl:44b3df6f03d85c901767250329c571db405122d5:boringssl \
		google:boringssl:853ca1ea1168dff08011e5d42d94609cc0ca2e27:boringssl_fips

# RUSTFLAGS=-Clink-dead-code is required to have a functional libsignal-node binary:
# linkme is broken with https://github.com/dtolnay/linkme/commit/64e7c63c106848481bea8f66c4885b52c26ca9ec
# It's probably related to https://github.com/dtolnay/linkme/issues/49
MAKE_ENV=	HOME=${WRKDIR} \
		PYTHON=${PYTHON_CMD} \
		RUSTFLAGS=-Clink-dead-code \
		XDG_CACHE_HOME=${WRKDIR}/.cache

MAKE_ENV+=	RUSTC_BOOTSTRAP=aes,polyval

USE_LDCONFIG=	yes

PLIST_FILES=	lib/libsignal_node.so

NODEJS_VERSION=	20
NODE_ARCH=	${ARCH:S/aarch64/arm64/:S/amd64/x64/:S/i386/ia32/:C/powerpc64.*/ppc64/}
NPM_RINGRTC_DIR=	npm-@signalapp-ringrtc-2.36.0-67d1b48bd4c1ea31c155ea14a0bd28f04e46eff5-integrity
NPM_SIGNAL_DIR=		npm-@signalapp-libsignal-client-0.39.1-15b41f15c516ae3eecf8a098a9c9c7aac00444d7-integrity
NPM_SQLITE3_DIR=	npm-@signalapp-better-sqlite3-8.6.0-0413f4d0626b99838cd64ad09c88720aa2bec6ed-integrity
RUST_ARCH=	${ARCH:S/amd64/x86_64/:S/i386/i686/}
SQLCIPHER=		sqlcipher-4.5.5-fts5-fix--3.0.7--0.2.1-ef53ea45ed92b928ecfd33c552d8d405263e86e63dec38e1ec63e1b0193b630b

YARN_TIMESTAMP=	1661146515

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc64*}
EXTRA_PATCHES=	${FILESDIR}/${ARCH}-patch-node_binding.gyp
.endif

pre-fetch:
	if [ ! -f ${DISTDIR}/libsignal-node-${DISTVERSION}-yarn-cache.tar.gz ]; \
		then ${MKDIR} ${WRKDIR}; \
		${ECHO_CMD} 'yarn-offline-mirror "./yarn-offline-cache"' >> \
			${WRKDIR}/.yarnrc; \
		${CP} ${FILESDIR}/node/package.json ${FILESDIR}/node/yarn.lock ${WRKDIR}; \
		cd ${WRKDIR} && ${SETENV} HOME=${WRKDIR} XDG_CACHE_HOME=${WRKDIR}/.cache \
			yarn --frozen-lockfile --ignore-scripts; \
		${MTREE_CMD} -cbnSp yarn-offline-cache | ${MTREE_CMD} -C | ${SED} \
			-e 's:time=[0-9.]*:time=${YARN_TIMESTAMP}.000000000:' \
			-e 's:\([gu]id\)=[0-9]*:\1=0:g' \
			-e 's:flags=.*:flags=none:' \
			-e 's:^\.:./yarn-offline-cache:' > yarn-offline-cache.mtree; \
		${TAR} cJf ${DISTDIR}/libsignal-node-${DISTVERSION}-yarn-cache.tar.gz  \
			@yarn-offline-cache.mtree; \
		${RM} -r ${WRKDIR}; \
	fi

post-patch:
	${REINPLACE_CMD} "s#python3#${PYTHON_CMD}#" \
		${WRKSRC}/node/binding.gyp

# to get the hash:
# fetch -o - https://raw.githubusercontent.com/signalapp/libsignal/v0.45.0/Cargo.lock | grep https://github.com/signalapp/boring
post-extract:
	${MV} ${WRKDIR}/boringssl-44b3df6f03d85c901767250329c571db405122d5/* ${WRKDIR}/boring-signal-v4.6.0/boring-sys/deps/boringssl
	${MV} ${WRKDIR}/boringssl-853ca1ea1168dff08011e5d42d94609cc0ca2e27/* ${WRKDIR}/boring-signal-v4.6.0/boring-sys/deps/boringssl-fips

	${CP} ${FILESDIR}/node/package.json ${WRKSRC}/node

do-build:
	${ECHO_CMD} 'yarn-offline-mirror "../yarn-offline-cache"' > ${WRKSRC}/.yarnrc
	${ECHO_CMD} 'nodedir "${LOCALBASE}"' >> ${WRKSRC}/.yarnrc
	cd ${WRKSRC}/node && \
		${SETENV} ${MAKE_ENV} yarn install --frozen-lockfile --ignore-optional --offline
	cd ${WRKSRC}/node && \
		${SETENV} ${MAKE_ENV} yarn tsc

do-install:
	${INSTALL_DATA} ${WRKSRC}/node/build/Release/obj.target/libsignal_client_freebsd_${NODE_ARCH}.node/geni/rust/${RUST_ARCH}-unknown-freebsd/release/libsignal_node.so \
		${STAGEDIR}${PREFIX}/lib/

.include <bsd.port.mk>
