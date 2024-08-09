PORTNAME=	lux
DISTVERSIONPREFIX=	v
DISTVERSION=	0.23.0
PORTREVISION=	5
CATEGORIES=	www

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Fast, simple and clean video downloader
WWW=		https://github.com/iawia002/lux

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

USES=		go:1.21,modules
GO_MODULE=	github.com/iawia002/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CONTRIBUTING.md README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
