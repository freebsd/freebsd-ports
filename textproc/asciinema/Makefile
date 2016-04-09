# $FreeBSD$

PORTNAME=	asciinema
PORTVERSION=	1.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Terminal session recorder

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes

PLIST_FILES=	bin/${PORTNAME}

STRIP=		# stripping can break go binaries

PORTDOCS=	CHANGELOG.md LICENSE README.md

post-patch:
	@cd ${WRKSRC} ; ${MKDIR} src/github.com/${GH_ACCOUNT} ; \
		${MKDIR} Godeps/_workspace/src/github.com/${GH_ACCOUNT} ; \
		${LN} -s ../../../../../ Godeps/_workspace/src/github.com/${GH_ACCOUNT}/${GH_PROJECT} ; \
		${LN} -s ../../.. src/github.com/${GH_ACCOUNT}/${GH_PROJECT}

do-build:
	@cd ${WRKSRC} ; \
		${SETENV} GOPATH=${WRKSRC}/Godeps/_workspace go build -o bin/asciinema

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
