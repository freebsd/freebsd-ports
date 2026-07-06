PORTNAME=	gomi
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.4
CATEGORIES=	sysutils

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Unix rm(1) command that can restore deleted files
WWW=		https://github.com/babarot/gomi

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

_BUILD_VERSION=		${DISTVERSIONFULL}
_BUILD_REVISION=	08cdfa5
_BUILD_DATE=		${HOSTARCH}-portbld-${OPSYS:tl}-${OSREL:R}

GO_MODULE=	github.com/babarot/gomi
GO_LDFLAGS=	-X main.version=${_BUILD_VERSION} \
		-X main.revision=${_BUILD_REVISION} \
		-X main.buildDate=${_BUILD_DATE}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
