PORTNAME=	paseo-hub
DISTVERSION=	0.12.0
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Agentic development environment (automation hub)
WWW=		https://paseo.sh/docs/hub \
		https://github.com/getpaseo/hub

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/node_modules/@getpaseo/hub/LICENSE

LIB_DEPENDS=	libuv.so:devel/libuv

USES=		nodejs:build,run npm:npm
USE_RC_SUBR=	paseo_hub

USERS=		paseo-hub
GROUPS=		paseo-hub

NPM_FETCH_FLAGS+=	--os=freebsd
# Prune node_modules in pre-fetch, before it is archived.
TARGET_ORDER_OVERRIDE=	290:npm-fetch-node-modules

APPDIR=		${PREFIX}/lib/${PORTNAME}
SUB_FILES=	paseo-hub pkg-message
SUB_LIST=	APPDIR=${APPDIR}
PLIST_FILES=	bin/paseo-hub

# fs-native-extensions has no FreeBSD backend; build it with ours.
# require-addon looks in prebuilds/<platform>-<process.arch>.
_FNE=		${WRKSRC}/node_modules/fs-native-extensions
_FNE_ARCH=	${ARCH:S/aarch64/arm64/:S/amd64/x64/:S/i386/ia32/:S/armv6/arm/:S/armv7/arm/:S/powerpc64le/ppc64/:S/powerpc64/ppc64/}
_FNE_PREBUILD=	prebuilds/freebsd-${_FNE_ARCH}/fs-native-extensions.node

pre-fetch:
	# Drop lightningcss's native binary: only the build tooling uses it.
	@if [ -d ${WRKDIR}/node-modules-cache ]; then \
		${RM} -r ${WRKDIR}/node-modules-cache/node_modules/lightningcss-*; \
	fi

post-patch:
	${CP} ${FILESDIR}/fs-native-extensions-freebsd.c ${_FNE}/src/freebsd.c

do-build:
	@${MKDIR} ${_FNE}/${_FNE_PREBUILD:H}
	cd ${_FNE} && ${CC} ${CFLAGS} -fPIC -shared -DNAPI_VERSION=9 \
		-I${WRKSRC}/node_modules/bare-compat-napi/include \
		-I${LOCALBASE}/include/node -I${LOCALBASE}/include \
		binding.c src/posix.c src/shared.c src/freebsd.c \
		${LDFLAGS} -L${LOCALBASE}/lib -luv -o ${_FNE_PREBUILD}

do-install:
	@cd ${WRKSRC}/node_modules && ${RM} -r .bin bare-compat-napi
	@cd ${_FNE} && ${RM} -r CMakeLists.txt PrivacyInfo.xcprivacy binding.c \
		include src
	@${FIND} ${_FNE}/prebuilds -mindepth 1 -maxdepth 1 \
		-not -name freebsd-${_FNE_ARCH} -exec ${RM} -r {} +
	@${MKDIR} ${STAGEDIR}${APPDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} node_modules ${STAGEDIR}${APPDIR}
	${INSTALL_LIB} ${_FNE}/${_FNE_PREBUILD} \
		${STAGEDIR}${APPDIR}/node_modules/fs-native-extensions/${_FNE_PREBUILD:H}
	${INSTALL_SCRIPT} ${WRKDIR}/paseo-hub ${STAGEDIR}${PREFIX}/bin

post-install:
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} -s ${APPDIR:S,^${PREFIX}/,,} -not -type d >> ${TMPPLIST}

.include <bsd.port.mk>
