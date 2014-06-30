# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	sprinkle
DISTVERSION=	2007-08-07
CATEGORIES=	net python
MASTER_SITES=	http://www.thuswise.org/sprinkle/pub/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Stomp messaging broker written in Python

NO_BUILD=	yes
USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/sprinkle-dist

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sprinkle.py ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
