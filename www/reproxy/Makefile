PORTNAME=	reproxy
PORTVERSION=	0.11.0
DISTVERSIONPREFIX=	v
PORTREVISION=	16
CATEGORIES=	www

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Simple edge HTTP(S) server and reverse proxy
WWW=		https://reproxy.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	umputun
GH_TUPLE=	golang:sys:v0.6.0:sys

BUILD_WRKSRC=	${WRKSRC}/app
PLIST_FILES=	bin/reproxy

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

post-patch:
	@${REINPLACE_CMD} -e '/var revision/s,unknown,${PORTVERSION},' \
		${BUILD_WRKSRC}/main.go

do-build:
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} \
		GOPROXY=off ${GO_CMD} build ${GO_BUILDFLAGS} \
		-o ${GO_WRKDIR_BIN}/${PORTNAME}

.include <bsd.port.mk>
