PORTNAME=	reproxy
PORTVERSION=	1.2.3
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Simple edge HTTP(S) server and reverse proxy
WWW=		https://reproxy.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.23,modules
USE_GITHUB=	yes
GH_ACCOUNT=	umputun

DEPRECATED=	Uses old go, but try building without USES=go:someversion
EXPIRATION_DATE=2026-01-01

BUILD_WRKSRC=	${WRKSRC}/app
PLIST_FILES=	bin/reproxy

post-patch:
	@${REINPLACE_CMD} -e '/var revision/s,unknown,${PORTVERSION},' \
		${BUILD_WRKSRC}/main.go

do-build:
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} \
		GOPROXY=off ${GO_CMD} build ${GO_BUILDFLAGS} \
		-o ${GO_WRKDIR_BIN}/${PORTNAME}

.include <bsd.port.mk>
