PORTNAME=	viddy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.4
PORTREVISION=	29
CATEGORIES=	sysutils
MASTER_SITES=

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Modern watch command
WWW=		https://github.com/sachaos/viddy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/sachaos/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X main.version=${DISTVERSION}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

PORTSCOUT=	ignore:1 site:none

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
