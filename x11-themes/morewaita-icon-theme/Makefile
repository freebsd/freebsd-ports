PORTNAME=	morewaita-icon-theme
DISTVERSION=	48.4
CATEGORIES=	x11-themes

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Expanded Adwaita-styled companion icon theme
WWW=		https://github.com/somepaulo/MoreWaita

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		meson

USE_GITHUB=	yes
GH_ACCOUNT=	somepaulo
GH_PROJECT=	MoreWaita

NO_ARCH=	yes

PORTDOCS=	AUTHORS CONTRIBUTING.md README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
