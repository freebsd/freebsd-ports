PORTNAME=	reproxy
PORTVERSION=	1.1.1
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	www

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Simple edge HTTP(S) server and reverse proxy
WWW=		https://reproxy.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	umputun

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
