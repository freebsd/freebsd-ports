PORTNAME=	chisel
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.1
PORTREVISION=	15
CATEGORIES=	www

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Fast TCP tunnel over HTTP
WWW=		https://github.com/jpillora/chisel

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/jpillora/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X ${GO_MODULE}/share.BuildVersion=${DISTVERSION}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
