PORTNAME=	AndikaCompact
DISTVERSION=	6.200
CATEGORIES=	x11-fonts
# Use the port maintainer's GitHub to fetch the font, since the SIL server
# embeds dynamic content into the file.
MASTER_SITES=	https://raw.githubusercontent.com/zoliky/distfiles/refs/heads/main/

MAINTAINER=	ports@zoltankiraly.com
COMMENT=	Sans-serif font designed for literacy use, compact variant
WWW=		https://software.sil.org/andika/

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

_DOCSLIST=	FONTLOG.txt OFL-FAQ.txt README.txt

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/documentation
	(cd ${WRKSRC}/documentation && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/documentation)
	${RM} -r ${STAGEDIR}${DOCSDIR}/documentation/source
	(cd ${WRKSRC} && ${INSTALL_DATA} ${_DOCSLIST} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
