PORTNAME=	gdu
DISTVERSIONPREFIX=	v
DISTVERSION=	5.32.0
CATEGORIES=	sysutils

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Disk usage analyzer with console interface written in Go
WWW=		https://github.com/dundee/gdu

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go:modules

GO_MODULE=	github.com/dundee/${PORTNAME}/${DISTVERSIONFULL:R:R}
GO_TARGET=	./cmd/${PORTNAME}

CONFLICTS_INSTALL=	coreutils

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=		DOCS MANPAGES
OPTIONS_DEFAULT=	MANPAGES

MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} -e '\
	    s|%%DISTVERSION%%|${DISTVERSION}|g; \
	    s|%%BUILDTIME%%|${CONFIGURE_TARGET}|g; \
	    s|%%BUILDUSER%%|portbld|g' \
	    ${PATCH_WRKSRC}/build/build.go

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} \
		${STAGEDIR}${DOCSDIR}

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
