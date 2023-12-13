PORTNAME=	mdbook-mermaid
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.0
CATEGORIES=	textproc

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Preprocessor for mdBook to add mermaid.js support
WWW=		https://github.com/badboy/mdbook-mermaid

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	badboy

PLIST_FILES=	bin/${PORTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
