# $FreeBSD$

PORTNAME=	modules2tuple
PORTVERSION=	1.8.1
DISTVERSIONPREFIX=	v
CATEGORIES=	ports-mgmt

MAINTAINER=	dg@syrec.org
COMMENT=	Generate GH_TUPLE from modules.txt

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_BUILDFLAGS=	-ldflags="-X main.version=${PORTVERSION}"

USE_GITHUB=	yes
GH_ACCOUNT=	dmgk

PLIST_FILES=	bin/${PORTNAME}

do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} test ${GO_BUILDFLAGS} ./...

.include <bsd.port.mk>
