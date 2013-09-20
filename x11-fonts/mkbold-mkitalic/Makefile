# Created by: KOMATSU Shinichiro
# $FreeBSD$

PORTNAME=	mkbold-mkitalic
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://hp.vector.co.jp/authors/VA013651/lib/

MAINTAINER=	koma2@lovepeers.org
COMMENT=	Programs to make BDF font bold/italic

CONFLICTS=	mkbold-[0-9]* mkitalic-[0-9]*

PLIST_FILES=	bin/mkbold bin/mkitalic bin/mkbolditalic
PORTDOCS=	ALGORITHM ALGORITHM.eucJP LICENSE README README.eucJP
USE_BZIP2=	yes

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}; ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.mk>
