# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	exercism
PORTVERSION=	2.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	misc

MAINTAINER=	swills@FreeBSD.org
COMMENT=	CLI client for exercism.io

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	codegangsta:cg kardianos:osext golang:text,net
GH_PROJECT=	cli:DEFAULT cli:cg osext:osext text:text net:net
GH_TAGNAME=	bca61c4:cg 6e7f843:osext 3eb7007:text 51854ab:net

STRIP=		# stripping can break go binaries

PLIST_FILES=	bin/exercism

post-patch:
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}
.for src in .gitignore .travis.yml CHANGELOG.md LICENSE README.md RELEASE.md \
	api bin cmd config exercism fixtures user
	@${MV} ${WRKSRC}/${src} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}
.endfor
	@${MKDIR} ${WRKSRC}/src/golang.org/x
	@${MKDIR} ${WRKSRC}/src/github.com/codegangsta
	@${MKDIR} ${WRKSRC}/src/github.com/kardianos
	@${MV} ${WRKSRC_cg} ${WRKSRC}/src/github.com/codegangsta/cli
	@${MV} ${WRKSRC_osext} ${WRKSRC}/src/github.com/kardianos/osext
	@${MV} ${WRKSRC_text} ${WRKSRC}/src/golang.org/x/text
	@${MV} ${WRKSRC_net} ${WRKSRC}/src/golang.org/x/net

do-build:
	@(cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT} ; \
		${SETENV} GOPATH=${WRKSRC} go build -o bin/exercism exercism/main.go)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/bin/exercism ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
