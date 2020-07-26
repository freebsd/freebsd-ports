# $FreeBSD$

PORTNAME=	k6
DISTVERSIONPREFIX=	v
DISTVERSION=	0.27.0
CATEGORIES=	net

MAINTAINER=	vulcan@wired.sh
COMMENT=	Modern load testing tool, using Go and Javascript

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	loadimpact

_BUILD_DATE=	$$(date -u +"%FT%T%z")
_BUILD_HASH=	6fa889d

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X ${GO_PKGNAME}/lib/consts.VersionDetails=${_BUILD_DATE}/${_BUILD_HASH}"

PLIST_FILES=	bin/${PORTNAME}
_DOCS=		release\ notes/\${DISTVERSIONFULL}.md CODE_OF_CONDUCT.md \
		CONTRIBUTING.md README.md SUPPORT.md
PORTDOCS=	${_DOCS:T}

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${_DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
