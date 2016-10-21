# Created by: moeding
# $FreeBSD$

PORTNAME=	jargon
PORTVERSION=	4.4.7
CATEGORIES=	misc
MASTER_SITES=	http://www.catb.org/~esr/jargon/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The famous jargon file

NO_BUILD=	yes

DATADIR=	${PREFIX}/share/jargon

post-extract:
	(cd ${WRKSRC}; \
	 ${RM} -r html/graphics/.xvpics graphics/.xvpics \
		html/letters.html~ html/online-preface.html~)

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}; ${PAX} -rw . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
