# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	sprinkle
DISTVERSION=	2007-08-07
CATEGORIES=	net python
MASTER_SITES=	http://www.thuswise.org/sprinkle/pub/

MAINTAINER=	gslin@gslin.org
COMMENT=	Stomp messaging broker written in Python

NO_BUILD=	yes
USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/sprinkle-dist

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sprinkle.py ${PREFIX}/sbin
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/*.* ${DOCSDIR}
.endif

.include <bsd.port.mk>
