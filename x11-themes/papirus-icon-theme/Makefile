# $FreeBSD$

PORTNAME=	papirus-icon-theme
PORTVERSION=	20190302
CATEGORIES=	x11-themes

MAINTAINER=	tagattie@yandex.com
COMMENT=	Papirus icon theme

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake gnome

USE_GITHUB=	yes
GH_ACCOUNT=	PapirusDevelopmentTeam

NO_ARCH=	yes
NO_BUILD=	yes

INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	AUTHORS README.md

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S/^/${WRKSRC}\//} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
