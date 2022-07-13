# Created by: Steffen Fritz <steffen@fritz.wtf>

PORTNAME=	siegfried
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.3
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	File identification tool

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:modules

GO_MODULE=	github.com/richardlehane/siegfried

GO_TARGET=	./cmd/sf

PLIST_FILES=	bin/sf

do-test:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} test ${GO_BUILDFLAGS} \
		./cmd/sf

.include <bsd.port.mk>
