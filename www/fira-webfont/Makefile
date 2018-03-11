# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	fira
PORTVERSION=	4.203
CATEGORIES=	www
MASTER_SITES=	https://carrois.com/downloads/Fira/
PKGNAMESUFFIX=	-webfont
DISTFILES=	Fira_Code_3_2.zip Fira_Mono_3_2.zip Fira_Sans_4_2.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sans-serif and monospaced Web Font for small screens

LICENSE=	OFL11

DEPRECATED=	Unused with no apparent use case
EXPIRATION_DATE=	2018-03-25

USES=		zip
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SUB_FILES=	pkg-message
PLIST_SUB=	WWWDIR_REL="${WWWDIR_REL}"

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
PORTDOCS=	*.pdf *.rtf

OPTIONS_DEFINE=	DOCS

do-install:
.for w in eot ttf woff woff2
	@${MKDIR} ${STAGEDIR}${WWWDIR}/${w}
	${FIND} ${WRKSRC}/Fira* -type f -name \*.${w} | while read f; do \
		${INSTALL_DATA} $$f ${STAGEDIR}${WWWDIR}/${w} ; done
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Fira*/PDF/*.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Fira_Sans_4_2/Fira_4_2_Version_Log.rtf \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
