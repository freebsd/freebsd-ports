# $FreeBSD$

PORTNAME=	elvish
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12
CATEGORIES=	shells

MAINTAINER=	vendion@gmail.com
COMMENT=	Friendly Interactive Shell and Expressive Programming Language

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	go
USE_GITHUB=	yes
GH_ACCOUNT=	elves

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/elvish

do-build:
	@cd ${GO_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} build

do-install:
	${INSTALL_PROGRAM} ${GO_WRKSRC}/${PORTNAME} \
	${STAGEDIR}/${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
