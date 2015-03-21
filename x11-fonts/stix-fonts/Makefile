# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	stixfonts
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	SF/${PORTNAME}/Current%20Release/
DISTNAME=	STIXv${PORTVERSION}-webfonts

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	OpenType Unicode fonts for Scientific, Technical, and Math texts

LICENSE=	OFL11

NO_WRKSUBDIR=	yes

USES=		fonts zip
USE_XORG=	x11

SUB_FILES=	pkg-message

FONTNAME=	stix

OPTIONS_DEFINE=	DOCS

PORTDOCS=	"STIX Font ${PORTVERSION}-webfonts Release Documentation.pdf"

do-build:
	${MKDIR} ${WRKDIR}/build
.for group in stix-web STIX-MathJax/woff
	${CP} ${WRKSRC}/${group}/*.woff ${WRKDIR}/build/
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKDIR}/build && ${INSTALL_DATA} *.woff ${STAGEDIR}${FONTSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
