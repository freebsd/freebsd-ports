PORTNAME=	siegfried
DISTVERSIONPREFIX=	v
DISTVERSION=	1.11.2
PORTREVISION=	5
CATEGORIES=	sysutils

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	File identification tool
WWW=		https://github.com/richardlehane/siegfried

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:modules
GO_MODULE=	github.com/richardlehane/siegfried
GO_TARGET=	./cmd/sf

PLIST_FILES=	bin/sf

do-test:
	@cd ${WRKSRC} && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} test ${GO_BUILDFLAGS} \
		./cmd/sf

.include <bsd.port.mk>
