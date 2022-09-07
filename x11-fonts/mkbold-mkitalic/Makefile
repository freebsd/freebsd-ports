PORTNAME=	mkbold-mkitalic
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://hp.vector.co.jp/authors/VA013651/lib/

MAINTAINER=	koma2@lovepeers.org
COMMENT=	Programs to make BDF font bold/italic
WWW=		https://hp.vector.co.jp/authors/VA013651/freeSoftware/mkbold-mkitalic.html

CONFLICTS=	mkbold mkitalic

PLIST_FILES=	bin/mkbold bin/mkitalic bin/mkbolditalic
PORTDOCS=	ALGORITHM ALGORITHM.eucJP LICENSE README README.eucJP
USES=	tar:bzip2

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}; ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
