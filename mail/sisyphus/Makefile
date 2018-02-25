# Created by: Carlo Strub <cs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sisyphus
PORTVERSION=	1.1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	mail

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Intelligent Junk Mail Handler

LICENSE=	BSD3CLAUSE

BROKEN=		fails to configure
DEPRECATED=	Never built
EXPIRATION_DATE=	2018-03-25

BUILD_DEPENDS=	glide:devel/go-glide

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	carlostrub
GO_PKGNAME=	github.com/carlostrub/sisyphus
PLIST_FILES=	bin/sisyphus

post-configure:
	@(cd ${WRKSRC}; glide install)

do-build:
	@(cd ${GO_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} build -o sisyphus/sisyphus -ldflags "-X main.version=${PORTVERSION}" -v sisyphus/sisyphus.go)

do-install:
	@(cd ${GO_WRKSRC}; ${MV} sisyphus/sisyphus ${STAGEDIR}/${LOCALBASE}/bin)

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sisyphus

.include <bsd.port.mk>
