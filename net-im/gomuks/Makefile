PORTNAME=	gomuks
DISTVERSION=	26.07
CATEGORIES=	net-im

MAINTAINER=	dereks@lifeofadishwasher.com
COMMENT=	Web and Terminal Matrix client
WWW=		https://github.com/gomuks/gomuks

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

LIB_DEPENDS=	libolm.so:security/olm
RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

USES=		go:1.26+,modules nodejs:build npm:npm

GO_MODULE_VER=	0.${DISTVERSION:C/\.//}.0
GO_MODULE=	go.mau.fi/gomuks@v${GO_MODULE_VER}

MAKE_ENV+=	CGO_CFLAGS="-I${LOCALBASE}/include" \
		CGO_LDFLAGS="-L${LOCALBASE}/lib" \
		GO_CMD=${GO_CMD} \
		MAU_VERSION_PACKAGE=${GO_MODNAME}/version

PLIST_FILES=	bin/gomuks \
		bin/gomuks-terminal

NPM_EXTRACT_WRKSRC=	${WRKSRC}/web

do-build:
	cd ${WRKSRC}/web \
		&& \
	${SETENV} ${MAKE_ENV} \
	${GO_CMD} run \
	../pkg/hicli/cmdspec/print \
	src/api/types/stdcommands.json  \
	src/api/types/stdcommands.d.ts \
	src/api/types/commandtestdata \
		&& \
	${SETENV} ${MAKE_ENV} \
	GOOS=js \
	GOARCH=wasm \
	CGO_ENABLED=0 \
	${GO_CMD} build \
	-o src/api/wasm/_gomuks.wasm \
	-tags "goolm sqlite_fts5" \
	../cmd/wasmuks \
		&& \
	${SETENV} ${MAKE_ENV} \
	npm run build \
		&& \
	cd .. \
		&& \
	${SETENV} ${MAKE_ENV} \
	CGO_ENABLED=1 \
	BINARY_NAME=gomuks \
	${GO_CMD} tool maubuild \
	-tags "sqlite_fts5" \
		&& \
	${SETENV} ${MAKE_ENV} \
	CGO_ENABLED=1 \
	BINARY_NAME=gomuks-terminal \
	${GO_CMD} tool maubuild

do-install:
	${INSTALL_PROGRAM} \
		${WRKSRC}/${PORTNAME} \
		${WRKSRC}/${PORTNAME}-terminal \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
