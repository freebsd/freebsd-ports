# $FreeBSD$

PORTNAME=	k6
DISTVERSIONPREFIX=	v
DISTVERSION=	0.26.2
CATEGORIES=	net

MAINTAINER=	vulcan@wired.sh
COMMENT=	Modern load testing tool, using Go and Javascript

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	loadimpact

_BUILD_DATE=	$$(date -u +"%FT%T%z")
_BUILD_HASH=	459da79

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X ${GO_PKGNAME}/lib/consts.VersionDetails=${_BUILD_DATE}/${_BUILD_HASH}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	${DOCS:T}

OPTIONS_DEFINE=	DOCS

DOCS=		release\ notes/\${DISTVERSIONFULL}.md CODE_OF_CONDUCT.md \
		CONTRIBUTING.md README.md SUPPORT.md

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
