# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	exercism
PORTVERSION=	2.4.1
DISTVERSIONPREFIX=	v
CATEGORIES=	misc

MAINTAINER=	swills@FreeBSD.org
COMMENT=	CLI client for exercism.io

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes
GH_PROJECT=	cli

PLIST_FILES=	bin/exercism

post-patch:
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}
.for src in .gitignore .travis.yml CHANGELOG.md LICENSE README.md RELEASE.md \
	api bin cmd config exercism fixtures user debug paths vendor
	@${MV} ${WRKSRC}/${src} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}
.endfor

do-build:
	@(cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT} ; \
		${SETENV} ${MAKE_ENV} GO15VENDOREXPERIMENT=1 GOPATH=${WRKSRC} go build -o bin/exercism exercism/main.go)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/bin/exercism ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
