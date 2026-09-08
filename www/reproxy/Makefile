PORTNAME=	reproxy
PORTVERSION=	1.7.1
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Simple edge HTTP(S) server and reverse proxy
WWW=		https://reproxy.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.26+,modules
USE_GITHUB=	yes
GH_ACCOUNT=	umputun
GO_LDFLAGS=	-X main.revision=v${PORTVERSION}

BUILD_WRKSRC=	${WRKSRC}/app
PLIST_FILES=	bin/reproxy

do-build:
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} \
		GOPROXY=off ${GO_CMD} build ${GO_BUILDFLAGS} \
		-o ${GO_WRKDIR_BIN}/${PORTNAME}

.include <bsd.port.mk>
