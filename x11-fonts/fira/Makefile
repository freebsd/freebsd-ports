# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	fira
PORTVERSION=	4.203
CATEGORIES=	x11-fonts
MASTER_SITES=	https://carrois.com/downloads/Fira/
DISTFILES=	Fira_Code_3_2.zip Fira_Mono_3_2.zip Fira_Sans_4_2.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sans-serif and monospaced typeface for small screens

LICENSE=	OFL11

USES=		fonts zip
USE_XORG=	x11
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

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
	${INSTALL_DATA} ${WRKSRC}/Fira_Sans_4_2/Fira_4_2_Version_Log.rtf \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
