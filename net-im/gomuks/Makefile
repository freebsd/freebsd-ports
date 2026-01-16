PORTNAME=	gomuks
DISTVERSION=	25.12
PORTREVISION=	1
CATEGORIES=	net-im

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Terminal Matrix client written in Go
WWW=		https://github.com/gomuks/gomuks

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libolm.so:security/olm
RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

USES=		go:1.25+,modules

GO_MODULE_VER=	0.${DISTVERSION:C/\.//}.0
GO_MODULE=	go.mau.fi/gomuks@v${GO_MODULE_VER}

MAKE_ENV+=	BINARY_NAME=${PORTNAME} \
		CGO_CFLAGS="-I${LOCALBASE}/include" \
		CGO_ENABLED=1 \
		CGO_LDFLAGS="-L${LOCALBASE}/lib" \
		MAU_VERSION_PACKAGE=${GO_MODNAME}/version

PLIST_FILES=	bin/gomuks

pre-build:
	${MKDIR} ${WRKSRC}/web/dist/
	${TOUCH} ${WRKSRC}/web/dist/empty

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_CMD} tool maubuild

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
