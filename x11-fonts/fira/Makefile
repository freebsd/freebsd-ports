# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	fira
PORTVERSION=	4.301
PORTREVISION=	1
CATEGORIES=	x11-fonts

MAINTAINER=	trueos@norwegianrockcat.com
COMMENT=	Sans-serif, monospaced, and code typeface for small screens

LICENSE=	OFL11

USES=		fonts
USE_XORG=	x11
USE_GITHUB=	yes
GH_ACCOUNT=	bBoxType
GH_PROJECT=	FiraSans
GH_TAGNAME=	f54eeb3
NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

PORTDOCS=	*.pdf *.rtf

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${FIND} ${WRKSRC}/Fira* -type f -name \*.otf | while read f; do \
		${INSTALL_DATA} $$f ${STAGEDIR}${FONTSDIR} ; done

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Fira*/PDF/*.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Fira_Sans_4_3/Fira_4_3_Change_Log.rtf \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
