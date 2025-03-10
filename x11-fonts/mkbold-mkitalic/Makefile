PORTNAME=	mkbold-mkitalic
DISTVERSION=	0.11
PORTREVISION=	2
CATEGORIES=	x11-fonts

MAINTAINER=	koma2@lovepeers.org
COMMENT=	Programs to make BDF font bold/italic
WWW=		https://gitlab.com/unshumikan/mkbold-mkitalic/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS=	mkbold mkitalic

USE_GITLAB=	yes
GL_ACCOUNT=	unshumikan

PORTDOCS=	ALGORITHM \
		ALGORITHM.eucJP \
		README \
		README.eucJP

PLIST_FILES=	bin/mkbold \
		bin/mkbolditalic \
		bin/mkitalic

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}; ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
