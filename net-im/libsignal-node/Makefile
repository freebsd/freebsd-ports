PORTNAME=	libsignal
DISTVERSIONPREFIX=	v
DISTVERSION=	0.32.1
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

FETCH_DEPENDS=	yarn-node18>0:www/yarn-node18
EXTRACT_DEPENDS=yarn-node18>0:www/yarn-node18
BUILD_DEPENDS=	llvm-config${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT} \
		protoc:devel/protobuf \
		yarn:www/yarn-node18

USES=		cargo gmake python:build
USE_GITHUB=	yes
GH_ACCOUNT=	signalapp
GH_TUPLE=	google:boringssl:3b74ab506eff560da3d67bfac9f1caa68bf31fbd:boringssl \
		google:boringssl:ae223d6138807a13006342edfeef32e813246b39:boringssl_fips

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

NODE_ARCH=	${ARCH:S/aarch64/arm64/:S/amd64/x64/:S/i386/ia32/:C/powerpc64.*/ppc64/}
RUST_ARCH=	${ARCH:S/amd64/x86_64/:S/i386/i686/}

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

# Check hash here: https://github.com/signalapp/boring/tree/libsignal/boring-sys/deps
post-extract:
	${MV} ${WRKDIR}/boringssl-3b74ab506eff560da3d67bfac9f1caa68bf31fbd/* ${WRKDIR}/boring-3809a7e1ca2f60a9495620da514f8432f148cde7/boring-sys/deps/boringssl
	${MV} ${WRKDIR}/boringssl-ae223d6138807a13006342edfeef32e813246b39/* ${WRKDIR}/boring-3809a7e1ca2f60a9495620da514f8432f148cde7/boring-sys/deps/boringssl-fips

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
