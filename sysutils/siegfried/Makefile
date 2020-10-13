# Created by: Steffen Fritz <steffen@fritz.wtf>
# $FreeBSD$

PORTNAME=	siegfried
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.1
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File identification tool

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	richardlehane

GO_TARGET=	./cmd/sf

PLIST_FILES=	bin/sf

do-test:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} test ${GO_BUILDFLAGS} \
		./cmd/sf

.include <bsd.port.mk>
