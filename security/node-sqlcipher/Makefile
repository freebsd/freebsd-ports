PORTNAME=	node-sqlcipher
DISTVERSION=	1.0.0
CATEGORIES=	security
MASTER_SITES=	https://github.com/signalapp/node-sqlcipher/archive/refs/tags/v${DISTVERSION}/:sqlcipher \
		LOCAL/mikael/signal-desktop/:npm
DISTFILES=	node-sqlcipher-${DISTVERSION}.tar.gz:sqlcipher \
		node-sqlcipher-${DISTVERSION}-npm-cache.tar.gz:npm \

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Fast N-API-based Node.js addon wrapping sqlcipher and FTS5 segmenting APIs
WWW=		https://github.com/signalapp/node-sqlcipher

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libsignal_sqlcipher_extension.a:devel/signal-sqlcipher-extension \
		npm:www/npm${NODEJS_SUFFIX}

USES=		nodejs:20,build

PLIST_FILES=	lib/node_sqlcipher.node

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
