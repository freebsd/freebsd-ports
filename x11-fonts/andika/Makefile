PORTNAME=	Andika
DISTVERSION=	6.000
CATEGORIES=	x11-fonts
MASTER_SITES=	https://software.sil.org/downloads/r/andika/

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Sans-serif font designed for literacy use

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
