PORTNAME=	gdu
DISTVERSIONPREFIX=	v
DISTVERSION=	5.31.0
CATEGORIES=	sysutils

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Disk usage analyzer with console interface written in Go
WWW=		https://github.com/dundee/gdu

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go:1.22,modules

_BUILD_MAJOR=	${DISTVERSIONFULL:C/\..*$//}
_BUILD_DATE=	$$(date +%Y-%m-%d)

GO_MODULE=	github.com/dundee/${PORTNAME}/${_BUILD_MAJOR}
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS+= -ldflags="-s -w -X ${GO_MODULE}/build.Version=${DISTVERSIONFULL} -X ${GO_MODULE}/build.Time=${_BUILD_DATE}"

CONFLICTS_INSTALL=	coreutils

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=		DOCS MANPAGES
OPTIONS_DEFAULT=	MANPAGES

MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} \
		${STAGEDIR}${DOCSDIR}

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
